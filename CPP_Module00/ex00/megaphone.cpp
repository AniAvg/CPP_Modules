#include <iostream>
#include <cctype>

void	str_toupper(char *str)
{
	int	i = 0;

	while (str[i])
	{
		std::cout << (char)toupper(str[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i = 1;

	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		while (i < argc)
		{
			str_toupper(argv[i]);
			i++;
		}
	}
	std::cout << std::endl;
	return (0);
}
