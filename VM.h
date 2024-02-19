#ifndef VM_H
#define VM_H

/**********************
 *                    *
 *      OP CODES      *
 *                    *
 **********************/

#define OPCODE_ALP 0
#define OPCODE_CMP 1
#define OPCODE_JMP 2
#define OPCODE_DRW 3
#define OPCODE_MOV 4
#define OPCODE_STP 5

/**********************
 *                    *
 *     ENCODING       *
 *                    *
 **********************/

typedef uint16_t tm_uword;
typedef int16_t tm_sword;

typedef union tm_word tm_word;
typedef union tm_encoding tm_encoding;
typedef struct tm_instruction tm_instruction;

union tm_encoding {
     struct {
          uint16_t rsvd   : 13;
          uint16_t opcode : 3;
     } generic;
     struct {
          uint16_t letter : 8;
          uint16_t rsvd   : 5;
          uint16_t opcode : 3;
     } alpha;
     struct {
          uint16_t letter : 8;
          uint16_t blank  : 1;
          uint16_t rsvd   : 3;
          uint16_t oring  : 1;
          uint16_t opcode : 3;
     } cmp;
     struct {
          uint16_t addr   : 11;
          uint16_t ne     : 1;
          uint16_t eq     : 1;
          uint16_t opcode : 3;
     } jmp;
     struct {
          uint16_t letter : 8;
          uint16_t blank  : 1;
          uint16_t rsvd   : 4;
          uint16_t opcode : 3;
     } draw;
     struct {
          int16_t amount   : 13;
          uint16_t opcode : 3;
     } move;
     struct {
          uint16_t rsvd   : 12;
          uint16_t halt   : 1;
          uint16_t opcode : 3;
     } stop;
     tm_word word;
};

struct tm_instruction {
     int line_num;
     tm_encoding encoding;
};

#endif