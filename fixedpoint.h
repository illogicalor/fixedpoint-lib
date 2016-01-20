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
// FIxed-point format is defined as:
// Q(IBITS).(FBITS)
#define IBITS   16  // Integer bits
#define FBITS   16  // Fractional bits

// --- Remaining code should not be modified ---
// Size of the fixed-point interger in bits
#define FIXEDPOINT_SIZE   ( IBITS + FBITS )

// Define the data type
#if ( FIXEDPOINT_SIZE <= 8 )
typedef uint8_t ufixed_t;
typedef int8_t sfixed_t;
#elif ( FIXEDPOINT_SIZE <= 16 )
typedef uint16_t ufixed_t;
typedef int16_t sfixed_t;
#elif ( FIXEDPOINT_SIZE <= 32 )
typedef uint32_t ufixed_t;
typedef int32_t sfixed_t;
#elif ( FIXEDPOINT_SIZE <= 64 )
typedef uint64_t ufixed_t;
typedef int64_t sfixed_t;
#else
#error "Data type greater than 64-bits not supported."
#endif

/***** Function Prototypes *****/
// Overflow functions
int fixedpoint_did_overflow( void );
void fixedpoint_clear_overflow( void );

// Math functions


// Utility functions

#endif /* __FIXEDPOINT_H__ */

