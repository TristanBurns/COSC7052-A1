#include <iostream>
#include <chrono>
#include <ctime>
#include <vector>

#define n 8 //Chromosome size
#define m 8 //Population size
//#define seed (unsigned)time( NULL )
#define seed 42

int  p[n][m];



int * RandomIndividual() {
   static int  r[n];

   std::srand(seed);
   
   for (int i = 0; i < n; ++i) {
      r[i] = ((int)std::rand() % 2);
   }

   return r;
}

void RandomPopulation() {
   
   std::srand(seed);
   
   for(int j = 0; j < m; j++){
        for (int i = 0; i < n; ++i) {
            p[i][j] = ((int)std::rand() % 2);
        }
    }

   return;
}

int Fitness(int * individual) {
    int temp = 0;
    for ( int i = 0; i < n; i++ ) {
        temp+= *(individual + i);
    }  
   return temp;
}



int main(int argc, char *argv[]) {
    bool verbose = false;
    for(int counter=0;counter<argc;counter++){
        std::cout << "arg " << counter << " = " << argv[counter] << std::endl;
        if(*argv[counter]=='v'){
            std::cout << "verbose = true"<< std::endl;
            verbose = true;
        }
    }

    if(verbose==true){
        std::cout << "Running Genetic Algorithm (Verbose)" << std::endl;
        std::cout <<"Problem Size n = "<< n << " " << std::endl;
    }
    

   int *a = RandomIndividual();
   
   for ( int i = 0; i < n; i++ ) {
        std::cout << *(a + i);
   }   
   std::cout <<std::endl;

   int f = Fitness(a);
   std::cout <<"Fitness: "<<f<<std::endl;


    RandomPopulation();
   for (int j = 0; j < m; j++ ) {
        for ( int i = 0; i < n; i++ ) {
            std::cout << p[i][j];
        }   
        std::cout <<std::endl;
   }


   f = Fitness(*(p+7));
   std::cout <<"Fitness: "<<f<<std::endl;

   return 0;
}