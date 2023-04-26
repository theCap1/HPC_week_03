#include <iostream>
#include "gemm_ref.cpp"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

void main(){

    int64_t i_m = 3;
    int64_t i_n = 3;
    int64_t i_k = 4;
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

    TEST_CASE("FMA reference"){
        REQUIRE( gemm_ref(a,b,c,i_m,i_n,i_k) );
    }

}