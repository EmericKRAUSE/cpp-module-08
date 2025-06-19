#include "../colors.hpp"
#include "Span.hpp"

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <fstream>

int main()
{
	srand (time(NULL));
	{
		std::cout << CYN << "Subject tests:" << RESET
				<< std::endl;
		Span sp(5);

		try
		{
			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;		
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		std::cout << CYN << "Copy constructor:" << RESET
				  << std::endl;
		Span sp(5);
		try
		{
			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
			Span spCopy(sp);
			for(int i = 0; i < 5; i++)
				std::cout << sp.getNumber(i) << std::endl;
			std::cout << "__________________" << std::endl;
			for (int i = 0; i < 5; i++)
				std::cout << spCopy.getNumber(i) << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		std::cout	<< CYN << "Test with 100 numbers using the addNumbers function (copying 100 elements from another container): " << RESET
					<< std::endl;
		std::vector<int> vector;
		Span sp(100);

		try
		{
			for (unsigned long i = 0; i < 100; i++)
				vector.push_back(rand() % 100);
			sp.addNumbers(vector.begin(), vector.end());

			std::cout	<< CYN << "vector numbers:" << RESET
						<< std::endl;
			for (unsigned long i = 0; i < 100; i++)
				std::cout << vector[i] << std::endl;

			std::cout	<< CYN << "span numbers:" << RESET
					  	<< std::endl;
			for (unsigned long i = 0; i < 100; i++)
				std::cout << sp.getNumber(i) << std::endl;

			std::cout	<< CYN << "shortes and longest span:" << RESET
					  	<< std::endl;
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		std::cout	<< CYN << "Test with 10 000 numbers using the addNumbers function:" << RESET
					<< std::endl;
		std::vector<int> vector;
		Span sp(10000);

		try
		{
			for (unsigned long i = 0; i < 10000; i++)
				vector.push_back(rand() % 1000);
			sp.addNumbers(vector.begin(), vector.end());
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		std::cout	<< CYN << "Test if the copy works:\n" << RESET
					<< "Use the following command:\n"
					<< "diff vector_file span_file" << std::endl;
		std::ofstream file1("vector_file");
		std::ofstream file2("span_file");
		if (!file1 || !file2)
		{
			std::cerr << "Error while opening files" << std::endl;
			return (1);
		}
		std::vector<int> vector;
		Span sp(10000);

		try
		{
			for (unsigned long i = 0; i < 10000; i++)
				vector.push_back(rand() % 1000);
			sp.addNumbers(vector.begin(), vector.end());
			for (unsigned long i = 0; i < 10000; i++)
				file1 << vector[i] << std::endl;
			for (unsigned long i = 0; i < 10000; i++)
				file2 << sp.getNumber(i) << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		file1.close();
		file2.close();
	}
	return (0);
}