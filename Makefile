all:
	g++ -std=c++11 -O1 -Wall GeneticAlgorithm.cpp -o GeneticAlgorithm 
clean:
	rm GeneticAlgorithm
	rm outputfile.txt 