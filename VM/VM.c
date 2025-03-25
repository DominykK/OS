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
#endif

/* 16 bit word */
typedef uint16_t u16;

/* 16 bit 65536 memory blocks */
#define MEMORY_MAX (1 << 16)

/* memory */
static u16 memory[MEMORY_MAX];

/* registers */
enum {
    R_R0 = 0,
    R_R1,
    R_R2,
    R_R3,
    R_R4,
    R_R5,
    R_R6,
    R_R7,
    R_PC,
    R_COND,
    R_COUNT
};

/* register array */
static u16 reg[R_COUNT];

/* opcodes */
enum {
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
    OP_RES,     /* reserved (don't use) */
    OP_LEA,     
    OP_TRAP     
};

/* conditional flags */
enum {
    FL_POS = 1 << 0, 
    FL_ZRO = 1 << 1, 
    FL_NEG = 1 << 2, 
};
