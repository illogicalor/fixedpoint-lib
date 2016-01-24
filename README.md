# fixedpoint-lib
Fixed point library in C

## How to use this library
This library provides basic fixed-point functionality. There are three parameters
that need to be defined in order to use the library:
* Number of integer bits (IBITS)
* Number of fractional bits (FBITS)
* Whether to use inline operations or functions (FIXEDPOINT\_INLINE\_OP)

Both IBITS and FBITS must be greater than zero. If FIXEDPOINT\_INLINE\_OP is enabled,
the fixedpoint.c file can be omitted as all mathematical operations are handled
inline. Enabling FIXEDPOINT\_INLINE\_OP allows for simpicity and smaller code
footprint. However, no error checks are done (e.g. overflows) so those will need
to be done manually in this mode.


