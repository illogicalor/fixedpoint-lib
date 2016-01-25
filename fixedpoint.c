/********************************************************************************
 * 
 *  @file:    fixedpoint.c
 *  @author:  IllogicalOR
 *  @brief:   Provides basic fixed-point functionality.
 * 
 ********************************************************************************
 */

/***** Includes *****/
#include "fixedpoint.h"

/***** Error checking *****/
#if ( FBITS == 0 || IBITS == 0 )
#error "Q0.0: Integer and fractional bits cannot be zero."
#endif /* ( FBITS == 0 || IBITS == 0 ) */
#if ( FBITS == 64 || IBITS == 64 )
#error "Q0.0: Integer and fractional bits cannot exceed 64."
#endif /* ( FBITS == 64 || IBITS == 64 ) */

/***** Definitions *****/

/***** Local Variables *****/
#if ( defined FIXEDPOINT_INLINE_OP && FIXEDPOINT_INLINE_OP == 0 )
static int overflow = 0;

/***** Function Definitions *****/
// ---------- Overflow Functions ----------
/**
 *  @brief  Returns the overflow flag determining whether the last
 *          operation overflowed.
 *          See http://www.doc.ic.ac.uk/~eedwards/compsys/arithmetic/ for
 *          details on overflow with signed integers.
 *  @return Overflow flag.
 */
int fixedpoint_did_overflow( void )
{
  return overflow;
}

/**
 *  @brief  Clear the overflow flag.
 */
void fixedpoint_clear_overflow( void )
{
  overflow = 0;
}

// ---------- Addition Functions ----------
/**
 *  @brief  Add two unsigned fixed-point numbers.
 *  @param  a - Unsigned fixed-point number
 *  @param  b - Unsigned fixed`point number
 *  @return Result of a + b. Set overflow flag is overflow occurs.
 */
ufixed_t q_uadd( ufixed_t a, ufixed_t b )
{
  ufixed_t result = a + b;

  // Check if an overflow occurred.
  if ( a > UFIXED_MAX - b )
  {
    overflow = 1;
  }

  return result;
}

/**
 *  @brief  Add two signed fixed-point numbers.
 *  @param  a - Signed fixed-point number
 *  @param  b - Signed fixed-point number
 *  @return Result of a + b. Set overflow flag is overflow occurs.
 */
sfixed_t q_sadd( sfixed_t a, sfixed_t b )
{
  sfixed_t result = a + b;

  // Check if an overflow occurred.
  // If both operands have the same sign, then an overflow occurs
  // if the result has a different sign.
  if ( ( a > 0 && b > 0 ) || ( a < 0 && b < 0 ) )
  {
    if ( ( a < 0 && result > 0 ) || ( a > 0 && result < 0 ) )
    {
      overflow = 1;
    }
  }

  // Return the result
  return result;
}

// ---------- Subtraction Functions ----------
/**
 *  @brief  Subtract two unsigned fixed-point numbers.
 *  @param  a - Unsigned fixed-point number
 *  @param  b - Unsigned fixed`point number
 *  @return Result of a - b. Set overflow flag is overflow occurs.
 */
ufixed_t q_usub( ufixed_t a, ufixed_t b )
{
  ufixed_t result = a - b;

  // Check if an overflow occurred.
  if ( b > a )
  {
    overflow = 1;
  }

  return result;
}

/**
 *  @brief  Subtract two signed fixed-point numbers.
 *  @param  a - Signed fixed-point number
 *  @param  b - Signed fixed-point number
 *  @return Result of a - b. Set overflow flag is overflow occurs.
 */
sfixed_t q_ssub( sfixed_t a, sfixed_t b )
{
  sfixed_t result = a - b;

  // Check if an overflow occurred.
  // If the signs differ, check the sign of the result.
  if ( ( a > 0 && b < 0 ) || ( a < 0 && b > 0 ) )
  {
    // If result and b have the same sign, an overflow occurred.
    if ( ( result < 0 && b < 0 ) || ( result > 0 && b > 0 ) )
    {
      overflow = 1;
    }
  }

  // Return the result
  return result;
}

#if ( FIXEDPOINT_SIZE <= 32 )
// ---------- Multiplication Functions ----------
/**
 *  @brief  Multiply two unsigned fixed-point numbers.
 *  @param  a - Unsigned fixed-point number
 *  @param  b - Unsigned fixed`point number
 *  @return Result of a - b. Set overflow flag is overflow occurs.
 */
ufixed_t q_umul( ufixed_t a, ufixed_t b )
{
  ufixed_t result = ( (ufixed_temp_t)a * (ufixed_temp_t)b ) >> FBITS;

  // Check if an overflow occurred.
  //

  return result;
}

/**
 *  @brief  Multiply two signed fixed-point numbers.
 *  @param  a - Signed fixed-point number
 *  @param  b - Signed fixed-point number
 *  @return Result of a - b. Set overflow flag is overflow occurs.
 */
sfixed_t q_smul( sfixed_t a, sfixed_t b )
{
  sfixed_t result = ( (sfixed_temp_t)a * (sfixed_temp_t)b ) >> FBITS;

  // Check if an overflow occurred.
  //

  // Return the result
  return result;
}

// ---------- Division Functions ----------
/**
 *  @brief  Division two unsigned fixed-point numbers.
 *  @param  a - Unsigned fixed-point number
 *  @param  b - Unsigned fixed`point number
 *  @return Result of a - b. Set overflow flag is overflow occurs.
 */
ufixed_t q_udiv( ufixed_t a, ufixed_t b )
{
  ufixed_t result = a * b;

  // Check if an overflow occurred.
  //

  return result;
}

/**
 *  @brief  Division two signed fixed-point numbers.
 *  @param  a - Signed fixed-point number
 *  @param  b - Signed fixed-point number
 *  @return Result of a - b. Set overflow flag is overflow occurs.
 */
sfixed_t q_sdiv( sfixed_t a, sfixed_t b )
{
  sfixed_t result = a * b;

  // Check if an overflow occurred.
  //

  // Return the result
  return result;
}
#endif /* FIXEDPOINT_SIZE <= 32  */

#endif /* FIXEDPOINT_INLINE_OP == 0 */

