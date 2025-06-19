#include <iostream>
#include <string>
#include <fstream>

std::string	replaceLine(std::string line, std::string prev, std::string newstr)
{
	std::string	newLine;
	size_t		found = line.find(prev);

	while (found != std::string::npos)
	{
		newLine += line.substr(0, found) + newstr;
		line = line.substr(found + prev.length());
		found = line.find(prev);
	}
	newLine += line;
	return (newLine);
}

bool	filesSetup(std::ifstream& inputFile, std::ofstream& outFile, std::string filename)
{
	inputFile.open(filename);
	if (!inputFile.is_open())
	{
		std::cout << "[Invalid file] failed to open " << filename << std::endl;
		return(false);
	}

	std::string		outfilename = filename + ".replace";
	outFile.open(outfilename);
	if (!outFile.is_open())
	{
		std::cout << "[Invalid file] failed to open " << outfilename << std::endl;
		inputFile.close();
		return(false);
	}
	return (true);
}

bool	fillOutfile(std::ifstream& inputFile, std::ofstream& outFile, std::string prev, std::string newstr)
{
	std::string	line;

	while (std::getline(inputFile, line))
	{
		if (prev == "")
			outFile << line << std::endl;
		else
			outFile << replaceLine(line, prev, newstr) << std::endl;
	}
	return (true);
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "[Invalid parameter] ./replace filename toBeReplaced newString" << std::endl;
		return (1);
	}

	std::ifstream	inputFile;
	std::ofstream	outFile;
	std::string		filename = argv[1];
	std::string		prevstr = argv[2];
	std::string		newstr = argv[3];

	if (filename.empty())
	{
		std::cout << "[Invalid parameter] Enter a valid filename" << std::endl;
		return (1);
	}

	if (!filesSetup(inputFile, outFile, filename))
		return (1);
	if (!fillOutfile(inputFile, outFile, prevstr, newstr))
		return (1);

	return (0);
}
