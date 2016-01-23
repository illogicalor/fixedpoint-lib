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
#if ( defined OVERFLOW_SUPPORT && OVERFLOW_SUPPORT == 1 )
#include <limits.h> // Requred if doing overflow check.
#endif

/***** Error checking *****/
#if ( FBITS == 0 || IBITS == 0 )
#error "Q0.0: Integer and fractional bits cannot be zero."
#endif /* ( FBITS == 0 || IBITS == 0 ) */
#if ( FBITS == 64 || IBITS == 64 )
#error "Q0.0: Integer and fractional bits cannot exceed 64."
#endif /* ( FBITS == 64 || IBITS == 64 ) */

/***** Definitions *****/

/***** Local Variables *****/
#if ( defined FIXEDPOINT_INLINE_OP && FIXEDPOINT_INLINE_OP != 1 )
static int overflow = 0;

/***** Function Definitions *****/
/**
 *  @brief  Returns the overflow flag determining whether the last
 *          operation overflowed.
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

/**
 *  @brief  Add two unsigned fixed-point numbers.
 *  @param  a - Unsigned fixed-point number
 *  @param  b - Unsigned fixed`point number
 *  @return Result of a + b.
 */
ufixed_t q_uadd( ufixed_t a, ufixed_t b )
{
  ufixed_t result = a + b;

#if defined OVERFLOW_SUPPORT && OVERFLOW_SUPPORT == 1
  // Check if an overflow occurred.
  //if ( result 
#endif /* OVERFLOW_SUPPORT */

  // Return the result
  return result;
}

/**
 *  @brief  Add two signed fixed-point numbers.
 *  @param  a - Signed fixed-point number
 *  @param  b - Signed fixed-point number
 *  @return Result of a + b.
 */
sfixed_t q_sadd( sfixed_t a, sfixed_t b )
{
  sfixed_t result = a + b;

#if defined OVERFLOW_SUPPORT && OVERFLOW_SUPPORT == 1
  // Check if an overflow occurred.
  //if ( result 
#endif /* OVERFLOW_SUPPORT */

  // Return the result
  return result;
}
#endif /* FIXEDPOINT_INLINE_OP */

