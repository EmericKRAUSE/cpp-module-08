#include "../colors.hpp"
#include "easyfind.hpp"

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>

template <typename T>
void	initContainer(T& container, int size)
{
	if (size > 100)
		size = 100;
	for (int i = 0; i < size; i++)
	{
		container.push_back(std::rand() % 100);
	}
}

template <typename T>
void	printContainer(const T &container, int toSearch)
{
	typename T::const_iterator it;
	int i = 0;
	it = container.begin();
	while (it != container.end())
	{
		if (*it == toSearch)
			std::cout << "[" << i << "] " << GRN << *it << RESET << std::endl;
		else
			std::cout << "[" << i << "] " << *it << std::endl;
		it++;
		i++;
	}
}

int main()
{
	int	lookingFor = 0;
	std::vector<int> numbers;
	//std::deque<int> numbers;

	std::srand(std::time(NULL));
	initContainer(numbers, 100);
	std::cout	<< CYN "Numbers in container: "<< RESET << std::endl;
	printContainer(numbers, lookingFor);
	std::cout	<< CYN "Number we're looking for: "<< RESET
				<< lookingFor << std::endl;
	try
	{
		std::cout	<< CYN << "Result: " << RESET
					<< *easyfind(numbers, lookingFor) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	return (0);
}