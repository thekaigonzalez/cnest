/*Copyright 2019-2023 Kai D. Gonzalez*/

#include <malloc.h>
#include <stdio.h>
#include <string.h>

#include "string.h"

#define ALLOC_ESCAPE(x) (x + 1)

void
string_append (string *s, char z)
{
  char *nfz = malloc (sizeof (s->_p)); // save the old string
  strcpy (nfz, s->_p);

  s->_p = malloc (ALLOC_ESCAPE (s->_s)
                  + 2);   // allocate a new string with the same length (with 2
                          // extra for the end too)
  s->_p = nfz;            // set the new block to the old saved string
  s->_p[s->_s] = z;       // set the current index to the character
  s->_p[(s->_s) + 1] = 0; // escape it too
  s->_s++;                // update the index
}

void
string1 (string *s)
{
  s->_s = 0;
  s->_p = malloc (1);
  s->_p[0] = 0;
}
