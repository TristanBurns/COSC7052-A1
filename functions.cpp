#include "functions.h" 
#include <iostream>


void RandomPopulationVerbose(int *p, int n, int m)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            *((p+i*n)+j) = ((int)std::rand() % 2);
            std::cout <<*((p+i*n)+j);
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
            *((p+i*n)+j) = ((int)std::rand() % 2);
        }
    }
    return;
}


int MaxFitnessVerbose(int *p, int n, int m)
{
    int best = 0;
    int besti = 0;
    int sum  = 0;

    for (int i = 0; i < m; i++)
    {
        sum = 0;
        for (int j = 0; j < n; j++)
        {
            std::cout <<*((p+i*n)+j);
            sum += *((p+i*n)+j);
            
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
    int sum  = 0;

    for (int i = 0; i < m; i++)
    {
        sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += *((p+i*n)+j);
        }


        if (sum > best)
        {
            best = sum;
        }
    }
    return best;
}


int IndividualFitness( int i, int *p, int n, int m)
{
    int sum = 0;
    for (int j = 0; j < n; j++)
    {
        sum += *((p+i*n)+j);
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
    std::cout << "Running Crossover (Verbose)\n" << std::endl;
    for (int i = 0; i < m; i += 2)
    {
        c = (std::rand() % n);
        individual1 = TournamentSelection(t, p, n, m);
        individual2 = TournamentSelection(t, p, n, m);
        for (int j = 0; j < c; j++)
        {
            // q[i][j] = p[individual1][j];
           *((q+i*n)+j) = *((p+individual1*n)+j);
            // q[i + 1][j] = p[individual2][j];
            *((q+(i+1)*n)+j) = *((p+individual2*n)+j);
        }

        for (int j = c; j < n; j++)
        {
            // q[i][j] = p[individual2][j];
            *((q+i*n)+j) = *((p+individual2*n)+j);
            // q[i + 1][j] = p[individual1][j];
            *((q+(i+1)*n)+j) = *((p+individual1*n)+j);
        }

        std::cout << "Crossover at chromosome " << c << ":" << std::endl;

        for (int j = 0; j < n; j++)
        {
            if (j == c)
            {
                std::cout << "|" << *((p+individual1*n)+j);
            }
            else
            {
                std::cout << *((p+individual1*n)+j);
            }
        }
        std::cout << " -> Parent 1 (Individual = " << individual1 << ")";
        std::cout << std::endl;
        for (int j = 0; j < n; j++)
        {
            if (j == c)
            {
                std::cout << "|" << *((p+individual2*n)+j);
            }
            else
            {
                std::cout << *((p+individual2*n)+j);
            }
        }
        std::cout << " -> Parent 2 (Individual = " << individual2 << ")";
        std::cout << std::endl;

        for (int j = 0; j < n; j++)
        {
            if (j == c)
            {
                std::cout << "|" << *((q+i*n)+j);
            }
            else
            {
                std::cout << *((q+i*n)+j);
            }
        }
        std::cout << " -> Child (i = " << i << "): ";
        std::cout << std::endl;

        for (int j = 0; j < n; j++)
        {
            if (j == c)
            {
                std::cout << "|" << *((q+(i+1)*n)+j);
            }
            else
            {
                std::cout << *((q+(i+1)*n)+j);
            }
        }
        std::cout << " -> Child (i = " << i + 1 << "): ";
        std::cout << std::endl;
    }
    return;
}