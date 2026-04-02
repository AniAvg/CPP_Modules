#include <iostream>
#include <fstream>
#include <string>


int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Wrong arguments" << std::endl;
		std::cerr << "Usage: ./a.out filename str1 str2" << std::endl;
		return (1);
	}

	std::ifstream file(argv[1]);
	if (!file.is_open())
	{
		std::cerr << "Couldn't open file" << std::endl;
		return (1);
	}

	std::ofstream	outfile(std::string(argv[1]) + ".replace");
	if (!outfile.is_open())
	{
		std::cerr << "Couldn't create output file" << std::endl;
		return (1);
	}

	std::string	s1 = argv[2];
	std::string	s2 = argv[3];

	if (s1.empty())
	{
		std::cerr << "s1 cannot be empty";
		return (1);
	}

	std::string	line;
	while (std::getline(file, line))
	{
		std::string	newline;
		size_t	pos = 1;
		size_t found;
		while ((found = line.find(s1, pos)) != std::string::npos)
		{
			newline += line.substr(pos, found - pos);
			newline += s2;
			pos = found + s1.length();
		}
		newline += line.substr(pos);
		outfile << newline << '\n';
	}

	file.close();
	outfile.close();
	return (0);
}