#include "Base.hpp"

int main()
{
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
