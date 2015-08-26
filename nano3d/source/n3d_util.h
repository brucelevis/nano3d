#pragma once

#if defined(_MSC_VER)
  #include <intrin.h>
#endif

// include sse intrinsics
#include <xmmintrin.h>

#if defined(_MSC_VER)
  #define assert( X ) { if (!(X)) __debugbreak(); }
#else
  #if 1
    #include <signal.h>
    #include <unistd.h>
    #define assert( X ) { if (!(X)) raise(SIGTRAP); }
  #else
    #define assert( X ) { if (!(X)) __asm__("int3 \n"); }
  #endif
#endif

template <typename type_t>
static type_t * checked(type_t * x) {
    assert(x);
    return x;
}

static
bool power_of_two(uint32_t x) {
    return ((x - 1) & x) == 0;
}