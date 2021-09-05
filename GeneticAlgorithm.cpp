#include <iostream>
#include <chrono>
#include <ctime>
#include <vector>

#define n 128 //Chromosome size
#define m 8 //Population size
#define seed 42 //#define seed (unsigned)time( NULL )
#define maxloops 100 //While Loop limit
#define t 2 // Tournament size
int p[m][n];
int q[m][n];

int *RandomIndividual()
{
    static int r[n];

    std::srand(seed);

    for (int i = 0; i < n; ++i)
    {
        r[i] = ((int)std::rand() % 2);
    }

    return r;
}

void RandomPopulation()
{

    std::srand(seed);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            p[i][j] = ((int)std::rand() % 2);
        }
    }

    return;
}

//NB Test whether fitness or individual fitness is faster/the same.
int Fitness(int *individual)
{
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        temp += *(individual + i);
    }
    return temp;
}

int IndividualFitness(int individual)
{
    int temp = 0;
    for (int j = 0; j < n; j++)
    {
        temp += p[individual][j];
    }
    return temp;
}

int AssessFitness()
{
    int fitnbest = 0;
    int fitni = 0;
    int besti = 0;
    for (int i = 0; i < m; i++)
    {
        fitni = 0;
        for (int j = 0; j < n; j++)
        {
            fitni += p[i][j];
        }
        if (fitni > fitnbest)
        {
            fitnbest = fitni;
            besti = i;
        }
    }
    return besti;
}

int TournamentSelection(int tsize)
{
    int randi;
    int fitnrand;
    int besti;
    int fitnbest = 0;

    besti = (std::rand() % m);
    fitnbest = IndividualFitness(besti);
    for (int i = 0; i < tsize; i++)
    {
        randi = (std::rand() % m);
        fitnrand = IndividualFitness(randi);
        if (fitnrand > fitnbest)
        {
            besti = randi;
            fitnbest = fitnrand;
        }
    }
return besti;
}

void CrossoverVerbose()
{
    int c = 0;
    int individual1;
    int individual2;
    std::cout << "\nRunning Crossover (Verbose)\n"
              << std::endl;
    for (int i = 0; i < m; i += 2)
    {
        c = (std::rand() % n);
        individual1 = TournamentSelection(t);
        individual2 = TournamentSelection(t);
        for (int j = 0; j < c; j++)
        {
            q[i][j] = p[individual1][j];
            q[i + 1][j] = p[individual2][j];
        }

        for (int j = c; j < n; j++)
        {
            q[i][j] = p[individual2][j];
            q[i + 1][j] = p[individual1][j];
        }

        std::cout << "Crossover at chromosome " << c << ":" << std::endl;

        for (int j = 0; j < n; j++)
        {
            if (j == c)
            {
                std::cout << "|" << p[individual1][j];
            }
            else
            {
                std::cout << p[individual1][j];
            }
        }
        std::cout << " -> Parent 1 (Individual = " << individual1 << ")";
        std::cout << std::endl;
        for (int j = 0; j < n; j++)
        {
            if (j == c)
            {
                std::cout << "|" << p[individual2][j];
            }
            else
            {
                std::cout << p[individual2][j];
            }
        }
        std::cout << " -> Parent 2 (Individual = " << individual2 << ")";
        std::cout << std::endl;

        for (int j = 0; j < n; j++)
        {
            if (j == c)
            {
                std::cout << "|" << q[i][j];
            }
            else
            {
                std::cout << q[i][j];
            }
        }
        std::cout << " -> Child (i = " << i << "): ";
        std::cout << std::endl;

        for (int j = 0; j < n; j++)
        {
            if (j == c)
            {
                std::cout << "|" << q[i + 1][j];
            }
            else
            {
                std::cout << q[i + 1][j];
            }
        }
        std::cout << " -> Child (i = " << i + 1 << "): ";
        std::cout << std::endl;
    }
    return;
}

void Mutate()
{
    int c;
    int mu;

    std::cout << "\nRunning Mutate (Verbose)\n"
              << std::endl;

    for (int i = 0; i < m; i++)
    {
        std::cout << "Child: " << i << " | ";

        mu = (std::rand() % n);
        if (mu == 0)
        {
            c = (std::rand() % n);
            q[i][c] = 1 - q[i][c];
        }

        for (int j = 0; j < n; j++)
        {
            std::cout << q[i][j];
        }
        if (mu == 0)
        {
            std::cout << "* Mutation at chromosome " << c << std::endl;
        }
        else
        {
            std::cout << std::endl;
        }
    }
}

void NextGeneration(int verbose)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            p[i][j] = q[i][j];
        }
    }
    if (verbose == true)
    {
        std::cout << "\n Assigning next generation (Verbose)\n"
                  << std::endl;
        for (int i = 0; i < m; i++)
        {
            std::cout << "Individual: " << i << " | ";
            for (int j = 0; j < n; j++)
            {
                std::cout << p[i][j];
            }
            std::cout << " | Fitness: " << IndividualFitness(i) << std::endl;
        }
    }
}

int main(int argc, char *argv[])
{
    bool verbose = false;
    for (int counter = 0; counter < argc; counter++)
    {
        std::cout << "arg " << counter << " = " << argv[counter] << std::endl;
        if (*argv[counter] == 'v')
        {
            std::cout << "verbose = true" << std::endl;
            verbose = true;
        }
    }

    if (verbose == true)
    {
        std::cout << "Running Genetic Algorithm (Verbose)" << std::endl;
        std::cout << "Chromosome Size n = " << n << " " << std::endl;
        std::cout << "Population Size m = " << m << " " << std::endl;
        std::cout << "################### "
                  << "\n"
                  << std::endl;
    }

    int *a = RandomIndividual();

    for (int i = 0; i < n; i++)
    {
        std::cout << *(a + i);
    }
    std::cout << std::endl;

    int f = Fitness(a);
    std::cout << "Fitness: " << f << std::endl;

    RandomPopulation();

    if (verbose == true)
    {
        for (int i = 0; i < m; i++)
        {
            std::cout << "Individual: " << i << " | ";
            for (int j = 0; j < n; j++)
            {
                std::cout << p[i][j];
            }
            std::cout << " | Fitness: " << IndividualFitness(i) << std::endl;
        }
    }

    f = IndividualFitness(5);
    f = Fitness(*(p + 5));
    std::cout << "Fitness 5: " << f << std::endl;

    int bestfinti = AssessFitness();
    int bestfitn = IndividualFitness(bestfinti);
    int loops = 0;
    std::cout << "Initial Fittest Individual:" << bestfinti << ", Fitness: " << bestfitn << std::endl;

    while ((bestfitn!=n)&&(loops<maxloops))
    {
        CrossoverVerbose();
        Mutate();
        NextGeneration(verbose);
        bestfinti = AssessFitness();
        bestfitn = IndividualFitness(bestfinti);
        if (verbose == true)
        {
            std::cout << "Fittest Individual:" << bestfinti << ", Fitness: " << bestfitn << std::endl;
        }
        std::cout << "Loop: " << loops << ", Fitness: " << bestfitn << std::endl;
        loops++;
    }

    return 0;
}