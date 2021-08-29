all:
	g++ -std=c++11 -O1 GeneticAlgorithm.cpp -o GeneticAlgorithm
clean:
	rm GeneticAlgorithm
	rm outputfile.txt 