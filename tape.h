#include <stdbool.h>

#ifndef TAPE_H
#define TAPE_H

#define TAPE_LENGTH 2000

typedef struct {
    char symbol;
    bool blank;
} TapeCell;

typedef struct {
    TapeCell pos_tape[TAPE_LENGTH];
    TapeCell neg_tape[TAPE_LENGTH];
    int index;
} Tape;

void initTape(Tape* tape, char* input);
void moveTape(Tape* tape, int move);
void writeTape(Tape* tape, char symbol);
char readTape(Tape* tape);
void setBlank(Tape* tape);
bool isBlank(Tape* tape);
void printTape(Tape* tape);

#endif