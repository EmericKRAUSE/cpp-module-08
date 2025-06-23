#include "../colors.hpp"
#include "MutantStack.hpp"

#include <iostream>


int main()
{
	MutantStack<int> ms;
	ms.push(1);
	ms.push(2);
	ms.push(3);

	MutantStack<int>::iterator it = ms.begin();
	while (it != ms.end())
	{
		std::cout << *it << std::endl;
		it++;
	}
}