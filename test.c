#include "depth.h"
#include "stack.h"
#include "symbol.h"

#include "parser.h"

#include <stdio.h>

main ()
{
  Stack s;

  Symbol open = create_symbol ('{');
  Symbol close = create_symbol ('}');

  stack_initialize (&s);

  stack_move (&s, &open); // {
  stack_move (&s, &open); // {{

  stack_pop (&s, &close); // {{ }
  stack_pop (&s, &close); // {{ }}

  // stack is clear

  Parser g;

  parser_start (&g);

  ParserDiagnostic m = examine (&g, "()");

  if (m.p_balanced) {
    printf("is balanced!\n");
  } else {
    printf("is not balanced!\n");
  }
}
