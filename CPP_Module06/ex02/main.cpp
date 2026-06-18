#include "Base.hpp"
#include <ctime>


int main()
{
	std::srand(std::time(0));
	for (int i = 0; i < 5; i++)
	{
		Base* obj = generate();
		std::cout << "identify(ptr): ";
		identify(obj);

		std::cout << "identify(ref): ";
		identify(*obj);

		delete obj;
	}

	return 0;
}
