# COSC7052-A1
# Name: Tristan Burns
# Student Number: 42648493

1. Confirm user parameters (macros) in main.cpp file. The following parameters can be edited:

#define n 16                    // Chromosome size (number of genes per individual).
#define m 8                     // Population size (number of individuals).
#define seed 42                 // Psuedorandom number generator seed (std:srand(seed)).
#define maxgenerations 2000     // Maximum number of generations (while loop limit).
#define t 2                     // Tournament size (parents competing for selection).
#define verbose true            // Verbose output (cout) for verification.
#define printfitness false      // Best fitness per generation output (cout).

Warning: Setting verbose to true for large m or n (~>100) will result in very large output files and longer runtimes. 
Use verbose for small problem verification.

2. Compile the program using the makefile:
make 

The following make flags are defined in the makefile:

make o0      (-O0 optimisation flag)
make o1	     (-O1 optimisation flag)
make o2      (-O2 optimisation flag)
make o3      (-O3 optimisation flag)
make ofast   (-Ofast optimisation flag)
make gprof   (-pg flag)

4. Alternately you can compile using the command:
g++ -std=c++11 -O3 -funroll-loops -flto -fuse-linker-plugin functions.cpp main.cpp -o GeneticAlgorithm 

5. Run the program locally using the command:
./GeneticAlgorithm

Or alternatively, to produce an outputfile.txt.
./goslurm.sh

6. Alternatively you can run the program on getafix using the command:
sbatch goslurm.sh

7. When run using goslurm.sh, GeneticAlgorithm will write outputs to outputfile.txt.