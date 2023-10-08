#include "depth.h"
#include "stack.h"
#include "symbol.h"

#include "parser.h"

#include <stdio.h>

main ()
{
  //   Stack s;

  //   Symbol open = create_symbol ('{');
  //   Symbol close = create_symbol ('}');

  //   stack_initialize (&s);

  //   stack_move (&s, &open); // {
  //   stack_move (&s, &open); // {{

  //   stack_pop (&s, &close); // {{ }
  //   stack_pop (&s, &close); // {{ }}

  // stack is clear

  Stack s;
  string str;
  
  string1(&str);
  stack_initialize(&s);

  parser_populate(&s, "(print (1 2 3))", &str);

  printf("%s\n", str._p);

  //   ParserDiagnostic m = examine (&g, "(print (1 2 3))"); /* a simple
  //   S-expression */
  //   parser_populate (&g, "(print (1 2 3))"); /* a simple S-expression */
}
