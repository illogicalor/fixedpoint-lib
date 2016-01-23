/********************************************************************************
 * 
 *  @file:    fixedpoint.h
 *  @author:  IllogicalOR
 *  @brief:   Header file for generic fixed-point library.
 * 
 ********************************************************************************
 */

#ifndef __FIXEDPOINT_H__
#define __FIXEDPOINT_H__

/***** Includes *****/
#include <stdint.h> // Requires a standard int header.

/***** Definitions *****/
//
// FIxed-point format is defined as:
// Q(IBITS).(FBITS)
//
#define IBITS   16  // Integer bits
#define FBITS   16  // Fractional bits

//
// Configure whether we want inline operations to minimize code
// footprint i.e. no function calls; will need to do error
// checking MANUALLY.
//
#define FIXEDPOINT_INLINE_OP    1

//
// Configure whether we want overflow support
//
#define OVERFLOW_SUPPORT        1

//
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// !! --- Remaining code should not be modified --- !!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//

//
// The equivalent of 1.0 in fixed point
//
#define Q_ONE         ( (ufixed_t)1 << FBITS )

//
// Size of the fixed-point interger in bits
//
#define FIXEDPOINT_SIZE   ( IBITS + FBITS )

//
// Convert float literal to fixed point
//
#define UQ_LITERAL( float_literal ) ( (ufixed_t)( (float_literal) * Q_ONE ) )
#define SQ_LITERAL( float_literal ) ( (sfixed_t)( (float_literal) * Q_ONE ) )

//
// Convert fixed point to float
// Warning: 
//
#define Q_TO_FLOAT( fixed )         ( ((float)fixed) / Q_ONE )

//
// Define the data type
//
#if ( FIXEDPOINT_SIZE <= 8 )
typedef uint8_t   ufixed_t;
typedef int8_t    sfixed_t;
typedef uint16_t  ufixed_temp_t;  // Used for intermediate steps in mult/div calculations
typedef int16_t   sfixed_temp_t;  // Used for intermediate steps in mult/div calculations
#elif ( FIXEDPOINT_SIZE <= 16 )
typedef uint16_t  ufixed_t;
typedef int16_t   sfixed_t;
typedef uint32_t  ufixed_temp_t;  // Used for intermediate steps in mult/div calculations
typedef int32_t   sfixed_temp_t;  // Used for intermediate steps in mult/div calculations
#elif ( FIXEDPOINT_SIZE <= 32 )
typedef uint32_t  ufixed_t;
typedef int32_t   sfixed_t;
typedef uint64_t  ufixed_temp_t;  // Used for intermediate steps in mult/div calculations
typedef int64_t   sfixed_temp_t;  // Used for intermediate steps in mult/div calculations
#elif ( FIXEDPOINT_SIZE <= 64 )
// Warning: Only addition and subtraction are supported in this mode
typedef uint64_t  ufixed_t;
typedef int64_t   sfixed_t;
#else
#error "Data type greater than 64-bits not supported."
#endif

//
// For debug purposes
//
#define str( s )              #s
#define QFORMAT_STR( i, f )   "Q" str(i) "." str(f)

/***** Function Prototypes *****/
#if ( defined FIXEDPOINT_INLINE_OP && FIXEDPOINT_INLINE_OP == 1 )
//
// Error checking
//
#if ( FBITS == 0 || IBITS == 0 )
#error "Q0.0: Integer and fractional bits cannot be zero."
#endif /* ( FBITS == 0 || IBITS == 0 ) */
#if ( FBITS == 64 || IBITS == 64 )
#error "Q0.0: Integer and fractional bits cannot exceed 64."
#endif /* ( FBITS == 64 || IBITS == 64 ) */

//
// Overflow functions (undefined)
//
#define fixedpoint_did_overflow()
#define fixedpoint_clear_overflow()

//
// Math functions
//
#define q_uadd( a, b )  ( (ufixed_t)(a) + (ufixed_t)(b) )
#define q_sadd( a, b )  ( (sfixed_t)(a) + (sfixed_t)(b) )
#define q_usub( a, b )  ( (ufixed_t)(a) - (ufixed_t)(b) )
#define q_ssub( a, b )  ( (sfixed_t)(a) - (sfixed_t)(b) )
#define q_umul( a, b )  ( (ufixed_t)( (ufixed_temp_t)(a) * (ufixed_temp_t)(b) >> FBITS ) )
#define q_smul( a, b )  ( (sfixed_t)( (sfixed_temp_t)(a) * (sfixed_temp_t)(b) >> FBITS ) )
#if ( FIXEDPOINT_SIZE <= 32 )
// Only define divide functions if data size is not greater than 32 bits.
#define q_udiv( a, b )  ( (ufixed_t)( ( (ufixed_temp_t)(a) << FBITS ) / (ufixed_t)(b) ) )
#define q_sdiv( a, b )  ( (sfixed_t)( ( (sfixed_temp_t)(a) << FBITS ) / (sfixed_t)(b) ) )
#endif /* FIXEDPOINT_SIZE <= 32 */

#else /* FIXEDPOINT_INLINE_OP == 0 */

//
// Overflow functions
//
#if ( defined OVERFLOW_SUPPORT && OVERFLOW_SUPPORT == 1 )
int fixedpoint_did_overflow( void );
void fixedpoint_clear_overflow( void );
#endif /* OVERFLOW_SUPPORT */

//
// Math functions
//
ufixed_t q_uadd( ufixed_t a, ufixed_t b );
sfixed_t q_sadd( sfixed_t a, sfixed_t b );
ufixed_t q_usub( ufixed_t a, ufixed_t b );
sfixed_t q_ssub( sfixed_t a, sfixed_t b );
ufixed_t q_umul( ufixed_t a, ufixed_t b );
sfixed_t q_smul( sfixed_t a, sfixed_t b );
#if ( FIXEDPOINT_SIZE <= 32 )
// Only define divide functions if data size is not greater than 32 bits.
ufixed_t q_udiv( ufixed_t a, ufixed_t b );
sfixed_t q_sdiv( sfixed_t a, sfixed_t b );
#endif /* FIXEDPOINT_SIZE <= 32 */

//
// Utility functions
//
#endif /* FIXEDPOINT_INLINE_OP */

#endif /* __FIXEDPOINT_H__ */

