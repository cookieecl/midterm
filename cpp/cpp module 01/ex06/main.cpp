#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl	harl;
	if (argc != 2)
	{
		std::cout << "[Invalid parameter] ./harlFilter log_level" << std::endl;
		return (1);
	}

	harl.complain(argv[1]);
	return (0);
}
