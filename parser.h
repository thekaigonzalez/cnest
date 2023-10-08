/*Copyright 2019-2023 Kai D. Gonzalez*/

#include "stack.h"
#include "string.h"
#include "symbol.h"

#ifndef __PARSER_H
#define __PARSER_H

// simple structure to hold the stack and the data
typedef struct Parser
{
  Stack stack;
} Parser;

// simple structure to return different values about the
// statement being parsed
typedef struct parser_diagnostic
{
  int p_balanced;
} ParserDiagnostic;

// insert a symbol to the stack
void parser_insert (Parser *p, char s);

// pop the stack
void parser_pop (Parser *p, char s);

// initialize the parser and it's children
void parser_start (Parser *p);

// update the parser's data buffer
void parser_populate (Stack *p, const char *stat, string *str);

// returns a ParserDiagnostic
ParserDiagnostic examine (Parser *p, const char *stat);

#endif
