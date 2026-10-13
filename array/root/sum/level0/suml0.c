#include"suml0.h"



float sum_f32_l0(const float * const __restrict__ ptr, size_t n)
{
    if(ptr == NULL || n == 0)
        return 0;
    double res = 0.0;
    for(size_t i = 0; i < n; i++)
    {
        res += ptr[i];
    }
    return res;
}
int64_t sum_i32_l0(const int32_t * const __restrict__ ptr, size_t n)
{
    if(ptr == NULL || n == 0)
        return 0;
    int64_t res = 0;
    for(size_t i = 0; i < n; i++)
    {
        res += ptr[i];
    }
    return res;
}

