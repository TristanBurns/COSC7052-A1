#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void RandomPopulationVerbose(int *p, int n, int m);
void RandomPopulation(int *p, int n, int m);
int MaxFitnessVerbose(int *p, int n, int m);
int MaxFitness(int *p, int n, int m);
int IndividualFitness( int i, int *p, int n, int m);
int TournamentSelection(int tsize, int *p, int n, int m);
void CrossoverVerbose(int t, int *p, int *q, int n, int m);

#endif
