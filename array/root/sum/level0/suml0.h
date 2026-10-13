#ifndef SUM
#define SUM

#include <stddef.h>
#include <stdint.h>


float sum_f32_l0(const float * const __restrict__ ptr, size_t n);
int64_t sum_i32_l0(const int32_t  * const __restrict__ ptr, size_t n);

#endif
