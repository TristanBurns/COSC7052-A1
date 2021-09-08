#include <iostream>
#include <stdlib.h>
#include <chrono>
#include "functions.h" 

//######################################################################################
//####                                                                              ####
//####                               User Input (macros)                            ####
//####                                                                              ####
//######################################################################################

#define n 16                    // Chromosome size (number of genes per individual).
#define m 8                     // Population size (number of individuals).
#define seed 42                 // Psuedorandom number generator seed (std:srand(seed)).
#define maxgenerations 2000     // Maximum number of generations (while loop limit).
#define t 2                     // Tournament size (parents competing for selection).
#define verbose true            // Verbose output (cout) for verification.
#define printfitness false      // Best fitness per generation output (cout).

//######################################################################################
//####                                                                              ####
//####                         DO NOT MODIFY BELOW THIS LINE                        ####
//####                                                                              ####
//######################################################################################

//  p[m][n] - Array to store population with m individuals with chromosome size n.
int p[m][n];
//  q[m][n] - Array to store m children with chromosome size n.                 
int q[m][n];
//  best - Best (highest) fitness of current generation.
int best;
//  generation - While loop counter. Initialise first generation (generation 0).
int generation = 0;
//  fitness[maxgenerations] - Array to store best (highest) fitness per generation.
int fitness[maxgenerations];

int main()
{
    auto start = std::chrono::high_resolution_clock::now();

    std::srand(seed);
  
    if (verbose)
    {
        RandomPopulation((int *)p, n, m);
        best = MaxFitnessVerbose((int *)p, n, m);

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