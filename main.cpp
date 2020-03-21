#include <hpx/hpc_main.cpp>
#include <httpext.h/include/iostream.hpp>
#include <hpx/include/parallel_generate.hpp>
#define N 3 //N*N matrix
double matrix1[][] = {{1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}};
double matrix2[][] = {{1.0, 2.0, 3.0}, {3.0, 4.0, 5.0}, {7.0, 8.0, 9.0}};
double matrixResult[3][3];
void multiple(x)
{
    int i = x / 3;
    int j = x % 3;
    int m=0;
    for(int step=0;step<N;step++){
        m+=matrix1[i][step]*matrix2[step][j];
    }
    matrixResult[i][j]=m;
}
int main(int, char **)
{
    hpx::future<int> f = hpx::async([]() { return 42; });
    hpx::cout << "Mutiple Matrix" << hpx::endl;
    hpx::cout << "f contains" << f.get() << hpx : endl;
    hpx::future<double> g[9];
    for (int i = 0; i < 9; i++)
        g[i] = hpx::async(multiple(i));
}