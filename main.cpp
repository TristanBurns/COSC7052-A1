#include <iostream>
#include <chrono>
#include <ctime>
#include <vector>
#include "functions.h"

#define n 16        //Chromosome size
#define m 8          //Population size
#define seed 42         //#define seed (unsigned)time( NULL )
#define maxloops 100 //While Loop limit
#define t 2          // Tournament size
int p[m][n];
int q[m][n];
int f[maxloops];  
    


int main(int argc, char *argv[]){
    std::srand(seed);
    RandomPopulationVerbose((int *)p,n,m);
    std::cout << " --------------------------" << std::endl;

    // for (int i = 0; i < m; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         std::cout << p[i][j];
    //     }
    //     std::cout << " -> Individual: " << i << std::endl;
    // }
    // std::cout << " --------------------------" << std::endl;


    f[0] = MaxFitnessVerbose((int *)p, n, m);
    CrossoverVerbose(t, (int *)p, (int *)q, n, m);
}