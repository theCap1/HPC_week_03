#include <iostream>
#include "gemm_ref.cpp"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#define DTYPE float

TEST_CASE("FMA operations of matrices a, b, c (3x3)"){

  int64_t i_m = 3;
  int64_t i_n = 3;
  int64_t i_k = 4;
  DTYPE* a = new DTYPE[i_m*i_k];
  DTYPE* b = new DTYPE[i_k*i_n];
  DTYPE* c = new DTYPE[i_m*i_n];

  for (int i = 0; i < i_k*i_m; i++)
  {
      a[i] = i;
  }

  for (int i = 0; i < i_k*i_n; i++)
  {
      b[i] = i_k*i_n-i;
  }

  for (int i = 0; i < i_m*i_n; i++)
  {
      c[i] = 1;
  }

  gemm_ref(a,b,c,i_m,i_n,i_k);
  DTYPE expected_c[9] = { 175, 217, 259, 103, 129, 155, 31, 41, 51 };
  for (int i = 0; i < i_m*i_n; ++i) {
      REQUIRE(c[i] == expected_c[i]);
  }

  delete[] a;
  delete[] b;
  delete[] c;
}

TEST_CASE("FMA operations of matrices a, b, c (4x4)") {

  // Test parameters
  const int i_m = 4;
  const int i_n = 4;
  const int i_k = 4;

  // Initialize matrices
  DTYPE* a = new DTYPE[i_m*i_k];
  DTYPE* b = new DTYPE[i_k*i_n];
  DTYPE* c = new DTYPE[i_m*i_n];

  // Set matrix values
  for (int i = 0; i < i_m*i_k; ++i) {
    a[i] = i+1;
  }
  for (int i = 0; i < i_k*i_n; ++i) {
    b[i] = i+1;
  }
  for (int i = 0; i < i_m*i_n; ++i) {
    c[i] = 0;
  }

  // Call function
  gemm_ref(a, b, c, i_m, i_n, i_k);

  // Check results
  DTYPE expected_c[16] = { 90, 100, 110, 120, 202, 228, 254, 280, 314, 356, 398, 440, 426, 484, 542, 600 };
  for (int i = 0; i < i_m*i_n; ++i) {
    REQUIRE(c[i] == expected_c[i]);
  }

  // Clean up
  delete[] a;
  delete[] b;
  delete[] c;
}

TEST_CASE("FMA operations of matrices a, b, c (2x2)") {

  // Test parameters
  const int i_m = 2;
  const int i_n = 2;
  const int i_k = 2;

  // Initialize matrices
  DTYPE* a = new DTYPE[i_m*i_k];
  DTYPE* b = new DTYPE[i_k*i_n];
  DTYPE* c = new DTYPE[i_m*i_n];

  // Set matrix values
  for (int i = 0; i < i_m*i_k; ++i) {
    a[i] = i+1;
  }
  for (int i = 0; i < i_k*i_n; ++i) {
    b[i] = i+1;
  }
  for (int i = 0; i < i_m*i_n; ++i) {
    c[i] = 0;
  }

  // Call function
  gemm_ref(a, b, c, i_m, i_n, i_k);

  // Check results
  DTYPE expected_c[4] = { 7, 10, 15, 22 };
  for (int i = 0; i < i_m*i_n; ++i) {
    REQUIRE(c[i] == expected_c[i]);
  }

  // Clean up
  delete[] a;
  delete[] b;
  delete[] c;
}

TEST_CASE("FMA operations of matrices a, b, c are correct (1x1)") {

  // Test parameters
  const int i_m = 1;
  const int i_n = 1;
  const int i_k = 1;

  // Initialize matrices
  DTYPE* a = new DTYPE[i_m*i_k];
  DTYPE* b = new DTYPE[i_k*i_n];
  DTYPE* c = new DTYPE[i_m*i_n];

  // Set matrix values
  a[0] = 3;
  b[0] = 4;
  c[0] = 0;

  // Call function
  gemm_ref(a, b, c, i_m, i_n, i_k);

  // Check results
  REQUIRE(c[0] == 12);

  // Clean up
  delete[] a;
  delete[] b;
  delete[] c;
  }

  TEST_CASE("FMA operations of matrices a, b, c (3x2 and 2x4)") {

  // Test parameters
  const int i_m = 3;
  const int i_n = 4;
  const int i_k = 2;

  // Initialize matrices
  DTYPE* a = new DTYPE[i_m*i_k];
  DTYPE* b = new DTYPE[i_k*i_n];
  DTYPE* c = new DTYPE[i_m*i_n];

  // Set matrix values
  for (int i = 0; i < i_m*i_k; ++i) {
  a[i] = i+1;
  }
  for (int i = 0; i < i_k*i_n; ++i) {
  b[i] = i+1;
  }
  for (int i = 0; i < i_m*i_n; ++i) {
  c[i] = 0;
  }

  // Call function
  gemm_ref(a, b, c, i_m, i_n, i_k);

  // Check results
  DTYPE expected_c[12] = { 9, 12, 15,19, 26, 33, 29, 40, 51, 39, 54, 69 };
  for (int i = 0; i < i_m*i_n; ++i) {
    REQUIRE(c[i] == expected_c[i]);
  }

  // Clean up
  delete[] a;
  delete[] b;
  delete[] c;
  }

  TEST_CASE("FMA operations of matrices a, b, c are correct (2x3 and 3x1)") {

  // Test parameters
  const int i_m = 2;
  const int i_n = 1;
  const int i_k = 3;

  // Initialize matrices
  DTYPE* a = new DTYPE[i_m*i_k];
  DTYPE* b = new DTYPE[i_k*i_n];
  DTYPE* c = new DTYPE[i_m*i_n];

  // Set matrix values
  for (int i = 0; i < i_m*i_k; ++i) {
  a[i] = i+1;
  }
  for (int i = 0; i < i_k*i_n; ++i) {
  b[i] = i+1;
  }
  for (int i = 0; i < i_m*i_n; ++i) {
  c[i] = 0;
  }

  // Call function
  gemm_ref(a, b, c, i_m, i_n, i_k);

  // Check results
  DTYPE expected_c[2] = { 22, 28 };
  for (int i = 0; i < i_m*i_n; ++i) {
  REQUIRE(c[i] == expected_c[i]);
  }

  // Clean up
  delete[] a;
  delete[] b;
  delete[] c;
}