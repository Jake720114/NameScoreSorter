#include "NameScoreSorter.h"

#include <sstream>
#include <string>
#include <fstream>

#include "NameScore.h"
#include "NameScoreSorter.h"

int main(int argc, char* argv[])
{
	std::ifstream inputfile;
	std::string line;
	NameScoreSorter sorter;
	std::size_t size;

	if (argc < 2) {
		std::cerr << "Usage: " << argv[0] << " filename" << std::endl;
		return 1;
	}

	std::string filename = std::string(argv[1]);

	inputfile.open(filename);
	if (inputfile.is_open()) {
		while (!inputfile.eof()) {
			std::getline(inputfile, line);
			sorter.pushline(line);
		}
		inputfile.close();
	}
	else {
		std::cout << "open failed";
		return 0;
	}

	std::cout << "Before sort" << std::endl;
	size = sorter.count();
	for (std::size_t i = 0; i < size; ++i)
		std::cout << sorter.getnthline(i) << std::endl;

	// sort
	sorter.sortDescOrderByScoreAndLastName();

	std::cout << "After sort" << std::endl;
	
	size = sorter.count();
	for (std::size_t i = 0; i < size; ++i)
		std::cout << sorter.getnthline(i) << std::endl;


	filename.replace(filename.find(".txt"), sizeof(std::string(".txt")) - 1 ,"-graded.txt");
	std::string justfilename = filename.substr(filename.find_last_of("/\\") + 1);

	std::ofstream outputfile;
	outputfile.open(justfilename);
	
	if (outputfile.is_open()) {
		size = sorter.count();
		for (std::size_t i = 0; i < size; ++i)
			outputfile << sorter.getnthline(i) << std::endl;

		  outputfile.close();
		  std::cout << "Finished: created " << justfilename << std::endl;
	  }
	  else 
		  std::cout << "Finished: not created " << justfilename << std::endl;

	return 0;
}
