#include "MutantStack.hpp"
#include <list>


int main()
{
	std::cout << " Subject Test " << std::endl;

	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "Top: " << mstack.top() << std::endl;

	mstack.pop();

	std::cout << "Size: " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	std::cout << "Elements:" << std::endl;

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::stack<int> s(mstack);

	std::cout << "\n Copy Constructor " << std::endl;

	MutantStack<int> copy(mstack);

	for (MutantStack<int>::iterator i = copy.begin();
			i != copy.end();
			++i)
		std::cout << *i << " ";

	std::cout << std::endl;

	std::cout << "\n Assignment Operator " << std::endl;

	MutantStack<int> assign;

	assign = mstack;

	for (MutantStack<int>::iterator i = assign.begin();
			i != assign.end();
			++i)
		std::cout << *i << " ";

	std::cout << std::endl;

	std::cout << "\n Const Iterator " << std::endl;

	const MutantStack<int> constStack(mstack);

	for (MutantStack<int>::const_iterator i = constStack.begin();
			i != constStack.end();
			++i)
		std::cout << *i << " ";

	std::cout << std::endl;

	std::cout << "\n Reverse Iterator " << std::endl;

	for (MutantStack<int>::reverse_iterator i = mstack.rbegin();
			i != mstack.rend();
			++i)
		std::cout << *i << " ";

	std::cout << std::endl;

	std::cout << "\n std::list Comparison " << std::endl;

	std::list<int> lst;

	lst.push_back(5);
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);

	for (std::list<int>::iterator i = lst.begin();
			i != lst.end();
			++i)
		std::cout << *i << " ";

	std::cout << std::endl;

	return 0;
}
