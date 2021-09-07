#include "functions.h"
#include <iostream>


#define p(I, J) *((p + (I)*n) + (J))
#define q(I, J) *((q + (I)*n) + (J))



void RandomPopulationVerbose(int *p, int n, int m)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            p(i, j) = ((int)std::rand() % 2);
            std::cout << p(i, j);
        }
        std::cout << " -> Individual: " << i << std::endl;
    }
    return;
}

void RandomPopulation(int *p, int n, int m)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            p(i, j) = ((int)std::rand() % 2);
        }
    }
    return;
}

int MaxFitnessVerbose(int *p, int n, int m)
{
    int best = 0;
    int besti = 0;
    int sum = 0;

    for (int i = 0; i < m; i++)
    {
        sum = 0;
        for (int j = 0; j < n; j++)
        {
            std::cout << p(i, j);
            sum += p(i, j);
        }
        std::cout << " -> Individual: " << i << ", Fitness: " << sum << std::endl;

        if (sum > best)
        {
            best = sum;
            besti = i;
        }
    }
    std::cout << "Initial Fittest Individual:" << besti << ", Fitness: " << best << std::endl;
    return best;
}

int MaxFitness(int *p, int n, int m)
{
    int best = 0;
    int sum = 0;

    for (int i = 0; i < m; i++)
    {
        sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += p(i, j);
        }

        if (sum > best)
        {
            best = sum;
        }
    }
    return best;
}

int IndividualFitness(int i, int *p, int n, int m)
{
    int sum = 0;
    for (int j = 0; j < n; j++)
    {
        sum += p(i, j);
    }
    return sum;
}

int TournamentSelection(int tsize, int *p, int n, int m)
{
    int sumi;
    int sum;
    int besti;
    int best = 0;

    besti = (std::rand() % m);
    best = IndividualFitness(besti, p, n, m);

    for (int i = 0; i < tsize; i++)
    {
        sumi = (std::rand() % m);
        sum = IndividualFitness(sumi, p, n, m);
        if (sum > best)
        {
            besti = sumi;
            best = sum;
        }
    }
    return besti;
}

void CrossoverVerbose(int t, int *p, int *q, int n, int m)
{
    int c = 0;
    int individual1;
    int individual2;
    std::cout << "Running Crossover (Verbose)" << std::endl;
    for (int i = 0; i < m; i += 2)
    {
        c = (std::rand() % n);
        individual1 = TournamentSelection(t, p, n, m);
        individual2 = TournamentSelection(t, p, n, m);
        for (int j = 0; j < c; j++)
        {
            // q[i][j] = p[individual1][j];
            // *((q+i*n)+j) = *((p+individual1*n)+j);
            q(i, j) = p(individual1, j);
            // q[i + 1][j] = p[individual2][j];
            // *((q+(i+1)*n)+j) = *((p+individual2*n)+j);
            q(i + 1, j) = p(individual2, j);
        }

        for (int j = c; j < n; j++)
        {
            // q[i][j] = p[individual2][j];
            // *((q+i*n)+j) = *((p+individual2*n)+j);
            q(i, j) = p(individual2, j);
            // q[i + 1][j] = p[individual1][j];
            // *((q+(i+1)*n)+j) = *((p+individual1*n)+j);
            q(i + 1, j) = p(individual1, j);
        }

        std::cout << "Crossover at chromosome " << c << ":" << std::endl;

        for (int j = 0; j < n; j++)
        {
            if (j == c)
            {
                std::cout << "|" << p(individual1, j);
            }
            else
            {
                std::cout << p(individual1, j);
            }
        }
        std::cout << " -> Parent 1 (Individual = " << individual1 << ")";
        std::cout << std::endl;
        for (int j = 0; j < n; j++)
        {
            if (j == c)
            {
                std::cout << "|" << p(individual2, j);
            }
            else
            {
                std::cout << p(individual2, j);
            }
        }
        std::cout << " -> Parent 2 (Individual = " << individual2 << ")";
        std::cout << std::endl;

        for (int j = 0; j < n; j++)
        {
            if (j == c)
            {
                std::cout << "|" << q(i, j);
            }
            else
            {
                std::cout << q(i, j);
            }
        }
        std::cout << " -> Child (i = " << i << "): ";
        std::cout << std::endl;

        for (int j = 0; j < n; j++)
        {
            if (j == c)
            {
                std::cout << "|" << q(+1, j);
            }
            else
            {
                std::cout << q(i + 1, j);
            }
        }
        std::cout << " -> Child (i = " << i + 1 << "): ";
        std::cout << std::endl;
    }
    return;
}

void Crossover(int t, int *p, int *q, int n, int m)
{
    int c = 0;
    int individual1;
    int individual2;

    for (int i = 0; i < m; i += 2)
    {
        c = (std::rand() % n);
        individual1 = TournamentSelection(t, p, n, m);
        individual2 = TournamentSelection(t, p, n, m);
        for (int j = 0; j < c; j++)
        {
            // q[i][j] = p[individual1][j];
            // *((q+i*n)+j) = *((p+individual1*n)+j);
            q(i, j) = p(individual1, j);
            // q[i + 1][j] = p[individual2][j];
            // *((q+(i+1)*n)+j) = *((p+individual2*n)+j);
            q(i + 1, j) = p(individual2, j);
        }

        for (int j = c; j < n; j++)
        {
            // q[i][j] = p[individual2][j];
            // *((q+i*n)+j) = *((p+individual2*n)+j);
            q(i, j) = p(individual2, j);
            // q[i + 1][j] = p[individual1][j];
            // *((q+(i+1)*n)+j) = *((p+individual1*n)+j);
            q(i + 1, j) = p(individual1, j);
        }
    }

    return;
}

void MutateVerbose(int *q, int n, int m)
{
    int c;
    int mu;
    bool mutated;

    std::cout << "Running Mutate (Verbose)" << std::endl;

    for (int i = 0; i < m; i++)
    {
        mutated = false;

        for (int j = 0; j < n; j++)
        {
            mu = (std::rand() % n);
            if (mu == 0)
            {
                (q(i, j)) = 1 - (q(i, j));
                mutated = true;
                c = j;
                std::cout << "*" << q(i, j) << "*";
            }
            else
            {
                std::cout << " " << q(i, j) << " ";
            }
        }

        if (mutated)
        {
            std::cout << "-> Child " << i << " Mutation at chromosome(s) *_* " << std::endl;
        }

        else
        {
            std::cout << std::endl;
        }
    }
    return;
}

void Mutate(int *q, int n, int m)
{
    int mu;

    for (int i = 0; i < m; i++)
    {

        for (int j = 0; j < n; j++)
        {
            mu = (std::rand() % n);
            if (mu == 0)
            {
                (q(i, j)) = 1 - (q(i, j));
            }
        }

    }
    return;
}



void NextGenerationVerbose(int *p, int *q, int n, int m)
{
    std::cout << "Assigning next generation (Verbose)" << std::endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << q(i, j);
            p(i, j) = q(i, j);
            //std::cout << p(i,j);
        }
        std::cout << " | Fitness: " << IndividualFitness(i, p, n, m) << std::endl;
    }
}

void NextGeneration(int *p, int *q, int n, int m)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            p(i, j) = q(i, j);
            // p(i,j) = q(i, j, n);
        }
    }
}

void PrintFitness(int fitness[], int generation)
{
    std::cout << "Generation"
              << ","
              << "Best Fitness" << std::endl;
    for (int i = 0; i < (generation + 1); i++)
    {
        std::cout << i << "," << fitness[i] << std::endl;
    }
}