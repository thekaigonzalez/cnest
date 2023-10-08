/*Copyright 2019-2023 Kai D. Gonzalez*/

#include "depth.h"
#include "symbol.h"

#ifndef __MAT_H
#define __MAT_H

// the stack will hold the depth number (how far in)
typedef struct Stack
{
  ndepth_t __d; // the depth into the stack
  Symbol s[CHAR_STACK_MAX_DEPTH]; // the symbol stack
} Stack;

// initializes the stack with the depth at 0
void stack_initialize (Stack *s);

// saves the symbol to the stack and moves over one
void stack_move (Stack *s, Symbol *);

// removes the last element if the symbol is the same
void stack_pop(Stack* s, Symbol *);

// checks if the top element of the stack exists
int stack_top(Stack* s);

#endif /* __MAT_H */
