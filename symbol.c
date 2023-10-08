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
  int x = 1;

  if (x1->__s == 0 && x2->__s == -1)
    {
      x--;

      if ((x1->__n == BRACE_OPEN || x1->__n == PAREN_OPEN)
          && (x1->__n == BRACE_OPEN || x1->__n == PAREN_OPEN))
        return x;
    }

  return 1;
}
