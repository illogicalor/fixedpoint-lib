/***** Includes *****/
#include <stdio.h>
#include "fixedpoint.h"

/***** Definitions *****/
#define TEST_UFLOAT1    3.1415926f
#define TEST_UFLOAT2    12.3456f
#define TEST_SFLOAT1    -25.3569f
#define TEST_SFLOAT2    -234.23f

/***** Function Prototypes *****/

/***** Start of main *****/
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
  printf( "  UQ_LITERAL(%f) = %u (0x%X.0x%X)\r\n", u_f1, u_fixed1, Q_TO_Z( u_fixed1 ), Q_FRAC( u_fixed1 ) );
  printf( "  Q_TO_FLOAT(%u) = %f\r\n", u_fixed1, Q_TO_FLOAT( u_fixed1 ) );
  puts("");

  //
  // Signed fixed point
  //
  puts( "Signed fixed point:" );
  printf( "  SQ_LITERAL(%f) = %u (0x%X.0x%X)\r\n", s_f1, s_fixed1, Q_TO_Z( s_fixed1 ), Q_FRAC( s_fixed1 ) );
  printf( "  Q_TO_FLOAT(%u) = %f\r\n", s_fixed1, Q_TO_FLOAT( s_fixed1 ) );
  puts("");

  //
  // Unsigned addition
  //
  puts( "Unsigned fixed point addition:" );
  u_result = q_uadd( u_fixed1, u_fixed2 );
  printf( "  q_uadd( UQ_LITERAL(%f), UQ_LITERAL(%f) ) = %u (%f)\r\n", u_f1, u_f2, u_result, u_f1 + u_f2 );
  printf( "  Q_TO_FLOAT(%u) = %f\r\n", u_result, Q_TO_FLOAT( u_result ) );
  puts("");

  //
  // Signed addition
  //
  puts( "Signed fixed point addition:" );
  s_result = q_sadd( u_fixed1, s_fixed1 );
  printf( "  q_sadd( UQ_LITERAL(%f), SQ_LITERAL(%f) ) = %u (%f)\r\n", u_f1, s_f1, s_result, u_f1 + s_f1 );
  printf( "  Q_TO_FLOAT(%u) = %f\r\n", s_result, Q_TO_FLOAT( s_result ) );
  puts("");

  //
  // Unsigned subtraction
  //
  puts( "Unsigned fixed point subtraction:" );
  u_result = q_usub( u_fixed2, u_fixed1 );
  printf( "  q_usub( UQ_LITERAL(%f), UQ_LITERAL(%f) ) = %u (%f)\r\n", u_f2, u_f1, u_result, u_f2 - u_f1 );
  printf( "  Q_TO_FLOAT(%u) = %f\r\n", u_result, Q_TO_FLOAT( u_result ) );
  puts("");

  //
  // Signed subtraction
  //
  puts( "Signed fixed point subtraction:" );
  s_result = q_ssub( s_fixed2, s_fixed1 );
  printf( "  q_ssub( SQ_LITERAL(%f), SQ_LITERAL(%f) ) = %u (%f)\r\n", s_f2, s_f1, s_result, s_f2 - s_f1 );
  printf( "  Q_TO_FLOAT(%u) = %f\r\n", s_result, Q_TO_FLOAT( s_result ) );
  puts("");

  //
  // Unsigned multiplication
  //
  puts( "Unsigned fixed point multiplication:" );
  u_result = q_umul( u_fixed1, u_fixed2 );
  printf( "  q_umul( UQ_LITERAL(%f), UQ_LITERAL(%f) ) = %u (%f)\r\n", u_f1, u_f2, u_result, u_f1 * u_f2 );
  printf( "  Q_TO_FLOAT(%u) = %f\r\n", u_result, Q_TO_FLOAT( u_result ) );
  puts("");

  //
  // Signed multiplication
  //
  puts( "Signed fixed point multiplication:" );
  s_result = q_smul( u_fixed2, s_fixed2 );
  printf( "  q_smul( UQ_LITERAL(%f), SQ_LITERAL(%f) ) = %u (%f)\r\n", u_f2, s_f2, s_result, u_f2 * s_f2 );
  printf( "  Q_TO_FLOAT(%u) = %f\r\n", s_result, Q_TO_FLOAT( s_result ) );
  puts("");

  //
  // Unsigned division
  //
  puts( "Unsigned fixed point division:" );
  u_result = q_udiv( u_fixed1, u_fixed2 );
  printf( "  q_udiv( UQ_LITERAL(%f), UQ_LITERAL(%f) ) = %u (%f)\r\n", u_f1, u_f2, u_result, u_f1 / u_f2 );
  printf( "  Q_TO_FLOAT(%u) = %f\r\n", u_result, Q_TO_FLOAT( u_result ) );
  puts("");

  //
  // Signed division
  //
  puts( "Signed fixed point division:" );
  s_result = q_sdiv( u_fixed2, s_fixed2 );
  printf( "  q_sdiv( UQ_LITERAL(%f), SQ_LITERAL(%f) ) = %u (%f)\r\n", u_f2, s_f2, s_result, u_f2 / s_f2 );
  printf( "  Q_TO_FLOAT(%u) = %f\r\n", s_result, Q_TO_FLOAT( s_result ) );
  s_result = q_sdiv( s_fixed2, s_fixed1 );
  printf( "  q_sdiv( SQ_LITERAL(%f), SQ_LITERAL(%f) ) = %u (%f)\r\n", s_f2, s_f1, s_result, s_f2 / s_f1 );
  printf( "  Q_TO_FLOAT(%u) = %f\r\n", s_result, Q_TO_FLOAT( s_result ) );
  puts("");

#if ( defined FIXEDPOINT_INLINE_OP && FIXEDPOINT_INLINE_OP == 0 )
  // 
  // Perform overflow checks
  // 
  puts( "Overflow (unsigned fixed-point addition)" );
  u_result = q_uadd( UFIXED_MAX, u_fixed1 );
  if ( fixedpoint_get_error() == OVERFLOW_OCCURRED_ERROR )
  {
    printf( "  !!! OVERFLOW OCCURED !!!\r\n" );
    printf( "  q_uadd( UQ_LITERAL(%f), UQ_LITERAL(%f) ) = %u\r\n", Q_TO_FLOAT( UFIXED_MAX ), u_f1, u_result );
    printf( "  Q_TO_FLOAT(%u) = %f\r\n", u_result, Q_TO_FLOAT( u_result ) );
    fixedpoint_clear_error();
  }
  else
  {
    printf( "  q_uadd( UQ_LITERAL(%f), UQ_LITERAL(%f) ) = %u\r\n", Q_TO_FLOAT( UFIXED_MAX ), u_f1, u_result );
    printf( "  Q_TO_FLOAT(%u) = %f\r\n", u_result, Q_TO_FLOAT( u_result ) );
  }

  puts( "Overflow (signed fixed-point addition: two positive numbers)" );
  s_result = q_sadd( SFIXED_MAX, u_fixed1 );
  if ( fixedpoint_get_error() == OVERFLOW_OCCURRED_ERROR )
  {
    printf( "  !!! OVERFLOW OCCURED !!!\r\n" );
    printf( "  q_uadd( SQ_LITERAL(%f), SQ_LITERAL(%f) ) = %u\r\n", Q_TO_FLOAT( SFIXED_MAX ), u_f1, s_result );
    printf( "  Q_TO_FLOAT(%u) = %f\r\n", s_result, Q_TO_FLOAT( s_result ) );
    fixedpoint_clear_error();
  }
  else
  {
    printf( "  q_uadd( SQ_LITERAL(%f), SQ_LITERAL(%f) ) = %u\r\n", Q_TO_FLOAT( SFIXED_MAX ), s_f1, s_result );
    printf( "  Q_TO_FLOAT(%u) = %f\r\n", s_result, Q_TO_FLOAT( s_result ) );
  }

  puts( "Overflow (signed fixed-point addition: two negative numbers)" );
  s_result = q_sadd( SFIXED_MIN, s_fixed1 );
  if ( fixedpoint_get_error() == OVERFLOW_OCCURRED_ERROR )
  {
    printf( "  !!! OVERFLOW OCCURED !!!\r\n" );
    printf( "  q_uadd( SQ_LITERAL(%f), SQ_LITERAL(%f) ) = %u\r\n", Q_TO_FLOAT( SFIXED_MIN ), s_f1, s_result );
    printf( "  Q_TO_FLOAT(%u) = %f\r\n", s_result, Q_TO_FLOAT( s_result ) );
    fixedpoint_clear_error();
  }
  else
  {
    printf( "  q_uadd( SQ_LITERAL(%f), SQ_LITERAL(%f) ) = %u\r\n", Q_TO_FLOAT( SFIXED_MIN ), s_f1, s_result );
    printf( "  Q_TO_FLOAT(%u) = %f\r\n", s_result, Q_TO_FLOAT( s_result ) );
  }
#endif

  //
  // Demo done!
  //
  return 0;
}

