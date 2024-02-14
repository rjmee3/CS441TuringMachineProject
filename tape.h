#include <stdbool.h>

#ifndef TAPE_H
#define TAPE_H

    typedef struct TapeCell {
        char symbol;
        bool blank;
        struct TapeCell* next;
        struct TapeCell* prev;
    } TapeCell;

    typedef struct {
        TapeCell* current;
    } Tape;

    void initTape(Tape* tape, char* input);
    void moveHead(Tape* tape, signed int amt);
    char readHead(Tape* tape);
    void writeHead(Tape* tape, char input);
    char* printTape(Tape* tape);
    void destroyTape(Tape* tape);

#endif