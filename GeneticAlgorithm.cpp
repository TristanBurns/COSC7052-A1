#include <iostream>
#include <chrono>
#include <ctime>
#include <vector>

#define n 128 //Chromosome size
#define m 128 //Population size
//#define seed (unsigned)time( NULL )
#define seed 42

int * RandomIndividual() {
   static int  r[n];

   std::srand(seed);
   
   for (int i = 0; i < n; ++i) {
      r[i] = ((int)std::rand() % 2);
   }

   return r;
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
    

   int *p = RandomIndividual();
   
   for ( int i = 0; i < n; i++ ) {
        std::cout << *(p + i);
   }   
   std::cout <<std::endl;

   int f = Fitness(p);
   std::cout <<"Fitness: "<<f<<std::endl;
   return 0;
}