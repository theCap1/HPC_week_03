#include <stdlib.h>

#define DTYPE float

bool transpose = 0; // flag if the transposition of A for optimization should be done

void gemm_compiler_32_32_32_32_32_32_mnk( DTYPE const * i_a,
                                          DTYPE const * i_b,
                                          DTYPE       * io_c ){
    
    if (transpose)
    {
        // get transposed matrix Â for better performance with large matrices that dont fit into cache entirely
        DTYPE *a_t = (DTYPE*) malloc(32*32*sizeof(DTYPE));
        for(int r=0; r<32; ++r)
        {
            for(int c=0; c<32; ++c)
            {
                *(a_t + c + r * 32) = *(i_a + c * 32 + r);
            }
        }

        // do multiplication
        for (int m = 0; m < 32; m++)
        {
            for (int n = 0; n < 32; n++)
            {
                for (int k = 0; k < 32; k++)
                {
                    *(io_c + m + n * 32) += *(a_t + k + m * 32) * *(i_b + k + n * 32);
                }
            }
        }

        free(a_t);
    }else
    {
        // do multiplication
        for (int m = 0; m < 32; m++)
        {
            for (int n = 0; n < 32; n++)
            {
                for (int k = 0; k < 32; k++)
                {
                    *(io_c + m + n * 32) += *(i_a + m + k * 32) * *(i_b + k + n * 32);
                }
            }
        }
    }

}

void gemm_compiler_32_32_32_32_32_32_nkm( DTYPE const * i_a,
                                          DTYPE const * i_b,
                                          DTYPE       * io_c ){
    
    if (transpose)
    {
        // get transposed matrix Â for better performance with large matrices that dont fit into cache entirely
        DTYPE *a_t = (DTYPE*) malloc(32*32*sizeof(DTYPE));
        for(int r=0; r<32; ++r)
        {
            for(int c=0; c<32; ++c)
            {
                *(a_t + c + r * 32) = *(i_a + c * 32 + r);
            }
        }

        // do multiplication
        for (int n = 0; n < 32; n++)
        {
            for (int k = 0; k < 32; k++)
            {
                for (int m = 0; m < 32; m++)
                {
                    *(io_c + n + k * 32) += *(a_t + m + n * 32) * *(i_b + m + k * 32);
                }
            }
        }

        free(a_t);
    }else
    {
        // do multiplication
        for (int m = 0; m < 32; m++)
        {
            for (int n = 0; n < 32; n++)
            {
                for (int k = 0; k < 32; k++)
                {
                    *(io_c + m + n * 32) += *(i_a + m + k * 32) * *(i_b + k + n * 32);
                }
            }
        }
    }
}