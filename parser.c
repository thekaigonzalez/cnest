/*Copyright 2019-2023 Kai D. Gonzalez*/

#include "parser.h"

void
parser_add_data (Parser *p, char s)
{
  string_append (&p->data, s);
}

void
parser_insert (Parser *p, char s)
{
  Symbol z = create_symbol (s);
  stack_move (&p->stack, &z);
}

void
parser_pop (Parser *p, char s)
{
  Symbol symb = create_symbol (s);
  stack_pop (&p->stack, &symb);
}

void
parser_start (Parser *p)
{
  string1 (&p->data);           // initialize the string
  stack_initialize (&p->stack); // initialize the stack
}

ParserDiagnostic
examine (Parser *p, const char *stat)
{
  ParserDiagnostic new;
  while (*stat != '\0')
    {
      if (symbol_real (*stat))
        {
          Symbol sb = create_symbol (*stat);
          switch (symbol_type (&sb))
            {
            case 0:
              Symbol s = create_symbol (*stat);
              stack_move (&p->stack, &s);
              break;
            case -1:
              Symbol bs = create_symbol (*stat);
              if (stack_top (&p->stack))
                {
                  stack_pop (&p->stack, &bs);
                }
              else
                {
                  new.p_balanced = 0;
                }
              break;
            default:
              break;
            }
        }
      *stat++;
    }
    
    if (p->stack.__d > 0) new.p_balanced = 0;
    if (new.p_balanced != 0) new.p_balanced = 1;
    
  return new;
}
