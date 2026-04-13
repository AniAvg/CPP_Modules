#include "Point.hpp"

int main()
{
	Point	a(0, 0);
	Point	b(5, 0);
	Point	c(0, 5);

	Point p1(1, 1);
	std::cout << "Test (1,1) - should be true:  " << bsp(a, b, c, p1) << std::endl;

	Point p2(5, 5);
	std::cout << "Test (5,5) - should be false: " << bsp(a, b, c, p2) << std::endl;

	Point p3(2.5, 0);
	std::cout << "Test (2.5,0) on edge - should be false: " << bsp(a, b, c, p3) << std::endl;

	Point p4(0, 0);
	std::cout << "Test (0,0) on vertex - should be false: " << bsp(a, b, c, p4) << std::endl;

	Point p5(0.1, 0.1);
	std::cout << "Test (0.1,0.1) near edge - should be true: " << bsp(a, b, c, p5) << std::endl;

	Point p6(-1, -1);
	std::cout << "Test (-1,-1) - should be false: " << bsp(a, b, c, p6) << std::endl;

	return 0;
}
