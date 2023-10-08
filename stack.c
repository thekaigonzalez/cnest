#include "stack.h"
#include "symbol.h"

#include <stdlib.h>

void
stack_initialize (Stack *s)
{
  s->__d = 0;
}

void
stack_move (Stack *x, Symbol *y)
{
  if (symbol_type (y) == 0)
    {
      x->s[x->__d] = create_symbol (y->__n);
      x->__d++;
    }
}

void
stack_pop (Stack *x, Symbol *y)
{
  Symbol *t = &x->s[x->__d - 1];
  
  if (same(t, y) == 0) {
    x->__d = x->__d - 1;
    x->s[x->__d] = empty();
  }
}

int
stack_top (Stack *s)
{
  return (s->__d > 0);
  // s->s[s->__d];
}
