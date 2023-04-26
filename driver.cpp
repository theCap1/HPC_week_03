#include <iostream>
#include "gemm_ref.cpp"
#include <chrono>

int main(int argc, char* argv[]){
    int64_t i_m = 3;
    int64_t i_n = 3;
    int64_t i_k = 4;

    if (argc == 2) {
        int lambda = atoi(argv[1]);
        i_m = lambda;
        i_n = lambda;
        i_k = lambda;
    }

    std::cout << "running GEMM microbenchmarks with m = " << i_m << ", n = " << i_n << ", k = " << i_k << std::endl;
    std::chrono::steady_clock::time_point l_tp0, l_tp1;
    std::chrono::duration< double > l_dur;
    double l_g_flops = 0;
    int l_n_threads = 1;
    uint64_t l_n_repetitions = 5;
    l_n_repetitions *= 1000000;

    DTYPE *a = (DTYPE*) malloc(i_m*i_k*sizeof(DTYPE));
    DTYPE *b = (DTYPE*) malloc(i_k*i_n*sizeof(DTYPE));
    DTYPE *c = (DTYPE*) malloc(i_m*i_n*sizeof(DTYPE));

    for (int i = 0; i < i_k*i_m; i++)
    {
        *(a+i) = i;
    }

    for (int i = 0; i < i_k*i_n; i++)
    {
        *(b+i) = i_k*i_n-i;
    }

    for (int i = 0; i < i_m*i_n; i++)
    {
        *(c+i) = 1;
    }

    gemm_ref(a, b, c, i_m, i_n, i_k); // dry run
    l_tp0 = std::chrono::steady_clock::now();
    for (uint64_t i = 0; i < l_n_repetitions; i++)
    {
        gemm_ref(a, b, c, i_m, i_n, i_k);
    }
    l_tp1 = std::chrono::steady_clock::now();

    l_dur = std::chrono::duration_cast< std::chrono::duration< double> >( l_tp1 - l_tp0 );

    std::cout << "  duration: " << l_dur.count() << " seconds" << std::endl;
    std::cout << "  average duration: " << l_dur.count()/l_n_repetitions << " seconds" << std::endl;
    l_g_flops = i_m*i_n*(i_k*i_k+1);
    l_g_flops *= l_n_threads;
    l_g_flops *= l_n_repetitions;
    l_g_flops *= 1.0E-9;
    l_g_flops /= l_dur.count();
    std::cout << "  GFLOPS: " << l_g_flops << std::endl;
    

}