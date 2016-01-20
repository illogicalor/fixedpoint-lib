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
#if ( FBITS == 0 && IBITS == 0 )
#error "Q0.0: Integer and fractional bits cannot both be zero!"
#endif

/***** Definitions *****/
#define Q_ONE         ( 1 << FBITS )

/***** Local Variables *****/
static int overflow = 0;

/***** Function Definitions *****/
int fixedpoint_did_overflow( void )
{
  return overflow;
}

void fixedpoint_clear_overflow( void )
{
  overflow = 0;
}

