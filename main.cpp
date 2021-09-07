#include <iostream>
#include <chrono>
#include <ctime>
#include <vector>
#include <unistd.h>
#include <stdlib.h>

#include "functions.h"

#define n 1000               // Chromosome size
#define m 100                // Population size
#define seed 42            // #define seed (unsigned)time( NULL )
#define maxgenerations 1000 // Maximum number of generations (while Loop limit)
#define t 2                // Tournament size
bool useseed = true;
bool verbose = false;
bool printfitness = true;

int p[m][n];
int q[m][n];

int best;
int generation = 0;
int fitness[maxgenerations];

int main(int argc, char *argv[])
{

    if (useseed)
    {
        std::srand(seed);
    }

    if (verbose)
    {
        RandomPopulationVerbose((int *)p, n, m);
        best = MaxFitness((int *)p, n, m);

        while ((best != n) && (generation < maxgenerations))
        {
            fitness[generation] = best;
            std::cout << " ------------ Generation: " << generation << " Best Fitness: " << best << " --------------" << std::endl;
            CrossoverVerbose(t, (int *)p, (int *)q, n, m);
            MutateVerbose((int *)q, n, m);
            NextGenerationVerbose((int *)p, (int *)q, n, m);
            best = MaxFitness((int *)p, n, m);
            generation++;
        }
        fitness[generation] = best;
        std::cout << " ------------ Generation: " << generation << " Best Fitness: " << fitness[generation] << " --------------" << std::endl;
    }
    else
    {
        {
            RandomPopulation((int *)p, n, m);
            best = MaxFitness((int *)p, n, m);

            while ((best != n) && (generation < maxgenerations))
            {
                fitness[generation] = best;
                Crossover(t, (int *)p, (int *)q, n, m);
                Mutate((int *)q, n, m);
                NextGeneration((int *)p, (int *)q, n, m);
                best = MaxFitness((int *)p, n, m);
                generation++;
            }
            fitness[generation] = best;
        }
    }

    if (printfitness)
    {
        PrintFitness(fitness,  generation);
    }
    return 0;
}