# HPC_week_2
## Homework for the 3rd week

### 4. Small GEMMs: Getting Started
#### 4.1 Matrix Kernels: Reference
For this exercise the variables of the leading dimensions were not implemented since they can be derived from the dimensions of the matrices together with the knowledge that for us the storage major is column major.

#### 4.2 Matrix Kernels: Measuring Performance
FMA operations of the form c = c + a $\cdot$ b can be splitted into two floating point operations, the multiplication and addition. Given the matrix dimensions M, N, K for every element in the result matrix c we need to do K$^2$ scalar multiplications for the matrix-matrix multiplication of A and B and one addition to add the result to the corresponding element in C. C has M$\cdot$N elements which leads to M$\cdot$N$\cdot$(K$^2$+1) floating point operations per matrix FMA operation.

The benchmarks for different matrix sizes in the form of 
$$
M=N=K=ldA=ldB=ldC=\lambda
$$
with
$$
\lambda \in \{ 4, 8, 12, 16, 24, 32, 48, 64\}
$$
give the results that are presented in the following:
**Optimization ```O0```**

<details>
  <summary> Output matrix FMA on single core with compiler optimization O0 </summary>

```yaml
say whaaaat
```

</details>

</br>

**Optimization ```O1```**

<details>
  <summary> Output matrix FMA on single core with compiler optimization O1 </summary>

```yaml
say whaaaat
```

</details>

</br>

**Optimization ```O2```**

<details>
  <summary> Output matrix FMA on single core with compiler optimization O2 </summary>

```yaml
say whaaaat
```

</details>

</br>

