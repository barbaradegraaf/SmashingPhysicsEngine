//
//  Precision.h
//
//	It seems to be common practice to use this for when we want to switch precision between float and double
//
//

#ifndef Precision_h
#define Precision_h

nampespace smashing {
#if defined(IS_DOUBLE_PRECISION_ENABLED)   // If we are compiling for double precision
	typedef double real;
	#define real_sqrt sqrt
#else                                      // If we are compiling for single precision
	typedef float real;
	#define real_sqrt sqrtf
#endif
}


#endif /* Precision_h */
