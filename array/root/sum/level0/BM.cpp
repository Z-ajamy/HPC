extern "C" {
    #include "suml0.h"
}

#include <benchmark/benchmark.h>
#include <vector>

static void BM_sumFL0(benchmark :: State & state)
{
    int64_t n = state.range(0);

    std:: vector<float> v(n, 4.1f);

    for (auto _ :state)
    {
        double res = sum_f32_l0(v.data(), n);
        benchmark:: DoNotOptimize(res);
    }
    
    state.SetBytesProcessed(static_cast<int64_t>(state.iterations()) * n * sizeof(float));
}
BENCHMARK(BM_sumFL0)->Arg(1000)->Arg(100000)->Arg(10000000);

static void BM_sumIL0(benchmark :: State & state)
{
    int64_t n = state.range(0);

    std:: vector<int> v(n, 4);

    for (auto _ :state)
    {
        int64_t res = sum_i32_l0(v.data(), n);
        benchmark:: DoNotOptimize(res);
    }
    
    state.SetBytesProcessed(static_cast<int64_t>(state.iterations()) * n * sizeof(int));
}
BENCHMARK(BM_sumIL0)->Arg(1000)->Arg(100000)->Arg(10000000);


BENCHMARK_MAIN();
