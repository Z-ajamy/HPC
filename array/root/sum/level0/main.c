
#include <stdio.h>
#include <stdlib.h>
#include "suml0.h"
#include <assert.h>

int main() 
{
    size_t n = 100000000;
    
    float *f_arr = (float *)malloc(n * sizeof(float));
    int32_t *i_arr = (int32_t *)malloc(n * sizeof(int32_t));

    assert(f_arr && i_arr);

    for (size_t i = 0; i < n; i++) {
        f_arr[i] = 1.0f;
        i_arr[i] = 1;
    }

    double f_res = sum_f32_l0(f_arr, n);
    int64_t i_res = sum_i32_l0(i_arr, n);

    __asm__ volatile("" : : "g"(f_res) : "memory");
    __asm__ volatile("" : : "g"(i_res) : "memory");
    printf("\n%f\n%ld\n",f_res , i_res);



    free(f_arr);
    free(i_arr);

    return 0;
}
