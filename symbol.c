#include "symbol.h"

int
symbol_type (Symbol *s)
{
  return s->__s;
}

Symbol
create_symbol (char __tm)
{
  Symbol new;
  new.__s = ((__tm == PAREN_OPEN || __tm == BRACE_OPEN))   ? 0
            : ((__tm == PAREN_CLOS || __tm == BRACE_CLOS)) ? -1
                                                           : 1;
  new.__n = __tm;
  return new;
}

int
symbol_real (char s)
{
  return (create_symbol (s).__s == 0 | -1);
}

Symbol
empty ()
{
  Symbol s;
  return s;
}

int
same (Symbol *x1, Symbol *x2)
{
  int x = 1; // will return 0 if they are the same

  if (x1->__s == 0 && x2->__s == -1)
    {
      x--; /* if they're similar, deincrement the return value */

      if ((x1->__n == BRACE_OPEN || x1->__n == PAREN_OPEN) // if they are both open tokens
          && (x2->__n == BRACE_OPEN || x2->__n == PAREN_OPEN))
        return x; // return x (0)
    }

  return 1; // anything else just return 1
}
