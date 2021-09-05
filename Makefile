all:
	g++ -std=c++11 -O1 -Wall GeneticAlgorithm.cpp -o GeneticAlgorithm 
O3:
	g++ -std=c++11 -O3 -Wall GeneticAlgorithm.cpp -o GeneticAlgorithm 
multi:
	g++ -std=c++11 -O1 functions.cpp main.cpp -o GeneticAlgorithm 
clean:
	rm GeneticAlgorithm
	rm outputfile.txt 
