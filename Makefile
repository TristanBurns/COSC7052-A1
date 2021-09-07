all:
	g++ -std=c++11 -O3 functions.cpp main.cpp -o GeneticAlgorithm
O0:
	g++ -std=c++11 -O0 functions.cpp main.cpp -o GeneticAlgorithm
O1:
	g++ -std=c++11 -O1 functions.cpp main.cpp -o GeneticAlgorithm
O3:
	g++ -std=c++11 -O3 functions.cpp main.cpp -o GeneticAlgorithm

proto:
	g++ -std=c++11 -O1 -Wall GeneticAlgorithm.cpp -o GeneticAlgorithm 
clean:
	rm GeneticAlgorithm
	rm outputfile.txt 
