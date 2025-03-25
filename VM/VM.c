#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <signal.h>

#ifdef _WIN32
/* Windows-specific includes */
#include <Windows.h>
#include <conio.h>
#else
/* UNIX-specific includes */
#include <unistd.h>
#include <termios.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/select.h> 
#endif

/* 16 bit word */
typedef uint16_t u16;

/* 8192 16 bit memory blocks */
#define MEMORY_MAX (1 << 13)

/* memory */
static u16 memory[MEMORY_MAX];

/* registers */
enum 
{
    R_R0 = 0,
    R_R1,
    R_R2,
    R_R3,
    R_R4,
    R_R5,
    R_R6,
    R_R7,
    R_PC,
    R_IR,
    R_COND,
    R_COUNT
};

/* register array */
static u16 reg[R_COUNT];

/* opcodes */
enum 
{
    OP_BR = 0,  
    OP_ADD,     
    OP_LD,      
    OP_ST,      
    OP_JSR,     
    OP_AND,     
    OP_LDR,     
    OP_STR,     
    OP_RTI,     /* not used (system return to interrupt) */
    OP_NOT,     
    OP_LDI,    
    OP_STI,     
    OP_JMP,     
    OP_LDPTR,     /* not used (system load PTR) */
    OP_LEA,     
    OP_TRAP     
};

/* conditional flags */
enum 
{
    FL_POS = 1 << 0, 
    FL_ZRO = 1 << 1, 
    FL_NEG = 1 << 2, 
};

enum {
    PC_START = 0x3000 /* initial execution address */
};

static u16 sign_extend(u16 x, int bit_count)
{
    return 0;
}

static void update_flags(u16 r)
{

}

static u16 mem_read(u16 address)
{
    return 0;
}

static void mem_write(u16 address, u16 val)
{

}

static void read_image_file(FILE* file)
{

}

static int read_image(const char* image_path)
{
    return 0;
}

/* Ctrl+C */
static void handle_interrupt(int signal)
{
    printf("\nStopping VM emulation.\n");
    exit(2);
}

int main(int argc, const char* argv[])
{
    if (argc < 2)
    {
        printf("Nothing ...\n");
        return 2;
    }
    

    for (int i = 1; i < argc; ++i)
    {
        if (!read_image(argv[i]))
        {
            fprintf(stderr, "Couldn't load object: %s\n", argv[i]);
            return 1;
        }
    }

    signal(SIGINT, handle_interrupt);

    reg[R_PC] = PC_START;
    reg[R_COND] = FL_ZRO;

    int running = 1;
    while (running)
    {
        u16 instr = mem_read(reg[R_PC]++);
        u16 op = instr >> 12; 

        switch (op)
        {
            case OP_ADD:
            {
                
            }
            break;

            case OP_AND:
            {
                
            }
            break;

            case OP_NOT:
            {
                
            }
            break;

            case OP_BR:
            {
                
            }
            break;

            case OP_JMP:
            {
                
            }
            break;

            case OP_JSR:
            {
                
            }
            break;

            case OP_LD:
            {

            }
            break;

            case OP_LDI:
            {
                
            }
            break;

            case OP_LDR:
            {
                
            }
            break;

            case OP_LEA:
            {
               
            }
            break;

            case OP_ST:
            {
                
            }
            break;

            case OP_STI:
            {
               
            }
            break;

            case OP_STR:
            {
                
            }
            break;

            case OP_TRAP:
            {
                
            }
            break;

            case OP_LDPTR:
            {
                
            }
            break;
            case OP_RTI:
            default:
                printf("Undefined operation (0x%X). Stopping.\n", op);
                running = 0;
                break;
        }
    }

    return 0;
}