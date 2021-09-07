all:
	g++ -std=c++11 -O3 -funroll-loops -flto -fuse-linker-plugin functions.cpp main.cpp -o GeneticAlgorithm 
o0:
	g++ -std=c++11 -O0 functions.cpp main.cpp -o GeneticAlgorithm
o1:
	g++ -std=c++11 -O1 functions.cpp main.cpp -o GeneticAlgorithm
o3:
	g++ -std=c++11 -O3 functions.cpp main.cpp -o GeneticAlgorithm
ofast:
	g++ -std=c++11 -Ofast functions.cpp main.cpp -o GeneticAlgorithm

gprof:
	g++ -pg -std=c++11  -O0 functions.cpp main.cpp -o GeneticAlgorithm

intel:
	icc -std=c++11 functions.cpp main.cpp -o GeneticAlgorithm 

proto:
	g++ -std=c++11 -O1 -Wall GeneticAlgorithm.cpp -o GeneticAlgorithm 
clean:
	rm GeneticAlgorithm
	rm outputfile.txt 

time:
	rm GeneticAlgorithm
	rm outputfile.txt
	g++ -std=c++11 -O3 -funroll-loops -flto -fuse-linker-plugin functions.cpp main.cpp -o GeneticAlgorithm 
	sbatch goslurm.sh 

