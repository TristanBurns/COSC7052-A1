#include <iostream>
#include <chrono>
#include <ctime>
#include <vector>
#include "functions.h"

#define n 16               // Chromosome size
#define m 8               // Population size
#define seed 42            // #define seed (unsigned)time( NULL )
#define maxgenerations 200 // Maximum number of generations (while Loop limit)
#define t 2                // Tournament size
int p[m][n];
int q[m][n];
int fitness[maxgenerations];
int best;
int generation;

int main(int argc, char *argv[])
{
    std::srand(seed);
    generation = 0;
    RandomPopulationVerbose((int *)p, n, m);
 

    while ((best != n) && (generation < maxgenerations))
    {
        fitness[generation] = MaxFitness((int *)p, n, m);
        std::cout << " ------------ Generation: " << generation << " Best Fitness: "<< fitness[generation] <<" --------------" << std::endl;
        best = fitness[generation];
        CrossoverVerbose(t, (int *)p, (int *)q, n, m);
        MutateVerbose((int *)q, n, m);
        NextGenerationVerbose((int *)p, (int *)q, n, m);
        generation++;
    }
}