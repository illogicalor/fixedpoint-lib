#include <stdio.h>
#include "fixedpoint.h"

#define TEST_UFLOAT1    3.1415926f
#define TEST_UFLOAT2    12.3456f
#define TEST_SFLOAT1    -25.3569f
#define TEST_SFLOAT2    -234.23f

int main( int argc, char *argv[] )
{
  //
  // Variables
  //
  ufixed_t u_result;
  sfixed_t s_result;
  float u_f1 = 3.1415926f;
  float u_f2 = 12.3456f;
  float s_f1 = -25.3569f;
  float s_f2 = -234.23f;
  ufixed_t u_fixed1 = UQ_LITERAL( u_f1 );
  ufixed_t u_fixed2 = UQ_LITERAL( u_f2 );
  sfixed_t s_fixed1 = SQ_LITERAL( s_f1 );
  sfixed_t s_fixed2 = SQ_LITERAL( s_f2 );

  //
  // Print fixed point info
  //
  puts( "Fixed-point info: " QFORMAT_STR( IBITS, FBITS ) );
  puts("");
  
  //
  // Unsigned fixed point
  //
  puts( "Unsigned fixed point:" );
  printf( "  UQ_LITERAL(%f) = %u\r\n", u_f1, u_fixed1 );
  printf( "  Q_TO_FLOAT(%u) = %f\r\n", u_fixed1, Q_TO_FLOAT( u_fixed1 ) );

  //
  // Signed fixed point
  //
  puts( "Signed fixed point:" );
  printf( "  SQ_LITERAL(%f) = %u\r\n", s_f1, s_fixed1 );
  printf( "  Q_TO_FLOAT(%u) = %f\r\n", s_fixed1, Q_TO_FLOAT( s_fixed1 ) );

  //
  // Unsigned addition
  //
  puts( "Unsigned fixed point addition:" );
  u_result = q_uadd( u_fixed1, u_fixed2 );
  printf( "  UQ_LITERAL(%f + %f) = UQ_LITERAL(%f) = %u\r\n", u_f1, u_f2, u_f1 + u_f2, u_result );
  printf( "  Q_TO_FLOAT(%u) = %f\r\n", u_result, Q_TO_FLOAT( u_result ) );

  //
  // Signed addition
  //
  puts( "Signed fixed point addition:" );
  s_result = q_sadd( u_fixed1, s_fixed1 );
  printf( "  UQ_LITERAL(%f + %f) = UQ_LITERAL(%f) = %u\r\n", u_f1, s_f1, u_f1 + s_f1, s_result );
  printf( "  Q_TO_FLOAT(%u) = %f\r\n", s_result, Q_TO_FLOAT( s_result ) );

  //
  // Unsigned subtraction
  //
  puts( "Unsigned fixed point subtraction:" );
  u_result = q_usub( u_fixed2, u_fixed1 );
  printf( "  UQ_LITERAL(%f - %f) = UQ_LITERAL(%f) = %u\r\n", u_f2, u_f1, u_f2 - u_f1, u_result );
  printf( "  Q_TO_FLOAT(%u) = %f\r\n", u_result, Q_TO_FLOAT( u_result ) );

  //
  // Signed subtraction
  //
  puts( "Signed fixed point subtraction:" );
  s_result = q_ssub( s_fixed2, s_fixed1 );
  printf( "  UQ_LITERAL(%f - %f) = UQ_LITERAL(%f) = %u\r\n", s_f2, s_f1, s_f2 - s_f1, s_result );
  printf( "  Q_TO_FLOAT(%u) = %f\r\n", s_result, Q_TO_FLOAT( s_result ) );

  //
  // Unsigned multiplication
  //
  

  //
  // Signed multiplication
  //

  //
  // Demo done!
  //
  return 0;
}

