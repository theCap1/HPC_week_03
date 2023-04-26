#include <cstdint>
#include <iostream>

#define DTYPE float

void gemm_ref( DTYPE        const * i_a,
               DTYPE        const * i_b,
               DTYPE              * io_c,
               int64_t              i_m,
               int64_t              i_n,
               int64_t              i_k
            //    int64_t              i_lda,
            //    int64_t              i_ldb,   leading dimensions are actually not required if we assume column major as given and i_m, i_n, i_k are known
            //    int64_t              i_ldc 
               ){

    // get transposed matrix Â for better performance with large matrices that dont fit into cache entirely
    DTYPE *a_t = (DTYPE*) malloc(i_k*i_m*sizeof(DTYPE));
    for(int r=0; r<i_m; ++r)
    {
        for(int c=0; c<i_k; ++c)
        {
            *(a_t + c + r * i_k) = *(i_a + c * i_m + r);
        }
    }
    
    // do multiplication
    for (int n = 0; n < i_n; n++)
    {
        for (int m = 0; m < i_m; m++)
        {
            for (int i = 0; i < i_k; i++)
            {
                *(io_c + m + n * i_m) += *(a_t + i + m * i_k) * *(i_b + i + n * i_k);
            }
        }
    }

    free(a_t);
}