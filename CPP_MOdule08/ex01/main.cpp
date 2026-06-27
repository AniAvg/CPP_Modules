#include "Span.hpp"

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	// full span
	std::cout << std::endl;
	try
	{
		sp.addNumber(42);
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	// few numbers
	std::cout << std::endl;
	try
	{
		Span sp2(1);
		sp2.addNumber(5);
		sp2.shortestSpan();
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	// addNumbersRange
	std::cout << std::endl;
	std::vector<int> src;
	src.push_back(100);
	src.push_back(50);
	src.push_back(75);
	src.push_back(200);
	src.push_back(10);

	Span sp3(5);
	sp3.addNumbersRange(src.begin(), src.end());
	std::cout << "Shortest span: " << sp3.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp3.longestSpan() << std::endl;

	// 10000 numbers
	std::cout << std::endl;
	srand(time(0));

	std::vector<int> bigSrc;
	for (int i = 0; i < 10000; i++)
		bigSrc.push_back(rand() % 1000000);

	Span bigSpan(10000);
	bigSpan.addNumbersRange(bigSrc.begin(), bigSrc.end());

	std::cout << "Sortest span: " << bigSpan.shortestSpan() << std::endl;
	std::cout << "Longest span: " << bigSpan.longestSpan() << std::endl;


	// range overflow
	std::cout << std::endl;
	std::vector<int> v;
	for (int i = 0; i < 6; i++)
		v.push_back(i);
	try
	{
		Span sp4(5);
		sp4.addNumbersRange(v.begin(), v.end());
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
