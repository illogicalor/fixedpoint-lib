#include <stdio.h>
#include "fixedpoint.h"


int main( int argc, char *argv[] )
{
  puts( QFORMAT_STR( IBITS, FBITS ) );
  return 0;
}

