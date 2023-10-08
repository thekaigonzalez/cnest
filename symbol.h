/*Copyright 2019-2023 Kai D. Gonzalez*/

#ifndef __SYMBOL_H
#define __SYMBOL_H

#define PAREN_OPEN '('
#define PAREN_CLOS ')'

#define BRACE_OPEN '{'
#define BRACE_CLOS '}'

typedef struct Symbol
{
  char __n; // the character
  int __s;  // 0 or -1 (opening or closing) | note: will be 1 if not opening or
            // closing
} Symbol;

// if the symbol is a open brace or close brace
int symbol_type (Symbol *s);

// makes a symbol out of a character based on the defined open and close macros
Symbol create_symbol (char __tm);

// checks if its actually a symbol and not a regular character
int symbol_real(char s);

// just returns an empty symbol
Symbol empty();

// if the symbols are complementary (one is the close version of the other)
int same(Symbol *x1, Symbol *x2);

#endif // __SYMBOL_H
