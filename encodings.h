#ifndef ENCODINGS_H
#define ENCODINGS_H

#include <stdint.h>
#include <stdbool.h>


/*******************************
 *                             *
 *           OPCODES           *
 *                             *
 *******************************/

#define TM_OPCODE_ALP 0
#define TM_OPCODE_CMP 1
#define TM_OPCODE_JMP 2
#define TM_OPCODE_DRW 3
#define TM_OPCODE_MOV 4
#define TM_OPCODE_STP 5

/*******************************
 *                             *
 *     ENCODING STRUCTURE      *
 *                             *
 *******************************/

typedef union tm_encoding {
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
          int16_t amount  : 13;
          uint16_t opcode : 3;
     } move;
     struct {
          uint16_t rsvd   : 12;
          uint16_t halt   : 1;
          uint16_t opcode : 3;
     } stop;
} tm_encoding;

#endif