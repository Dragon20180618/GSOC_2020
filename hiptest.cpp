#include <stdio.h>
template <typename T>
__global__ void test(T *C_d, const T *A_d, size_t N)
{
    size_t offset = hipBlockIdx_x * hipBlockDim_x + hipThreadIdx_x;
    size_t stride = hipBlockDim_x * hipGridDim_x;
    for (size_t i = offset; i < N; i += stride)
    {
        C_d[i] = A_d[i] * A_d[i];
    }
}
int main()
{
    const size_t N 100000;
    const size_t Nbytes = N * sizeof(double);
    double *A_d, *A_h *C_d, *C_h;
    C_h = (double *)malloc(Nbytes);
    A_h = (double *)malloc(Nbytes);
    for (int i = 0; i < N; i++)
    {
        A_h=1.23;
    }
    hipMalloc(&A_d, Nbytes);
    hipMalloc(&C_d, Nbytes);
    hipMemcpy(A_d, A_h, Nbytes, hipMemcpyHostDevice);
    const unsigned blocks = 512;
    const unsigned threadsPerBlock = 256;
    hipLaunchKernel(test, dim3(blocks), dim3(threadsPerBlock), C_d, A_d, N);
    hipMemcpy(C_h, C_d, Nbytes, hipMemcpyDeviceToHost);
    for(int i = 1 ; i<N;i++){
        C_h[0]+=C_h[i];
    }
    printf("The result is : %g\n",C_h[0]);
    return 0;
}