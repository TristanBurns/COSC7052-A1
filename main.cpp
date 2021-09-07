#include <iostream>
#include <stdlib.h>
#include <chrono>

#include "functions.h"

#define n 1024               // Chromosome size
#define m 100               // Population size
#define seed 42              // #define seed
#define maxgenerations 2000  // Maximum number of generations (while Loop limit)
#define t 2                  // Tournament size


bool verbose = false;
bool printfitness = true;

int p[m][n];
int q[m][n];

int best;
int generation = 0;
int fitness[maxgenerations];


int main(int argc, char *argv[])
{
    auto start = std::chrono::high_resolution_clock::now();
    int seed_rand = time(NULL);
    std::cout << seed_rand << std::endl;
    std::srand(seed_rand);
  
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
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
    std::cout << "Runtime (microseconds): "<< duration << std::endl;
    return 0;
}