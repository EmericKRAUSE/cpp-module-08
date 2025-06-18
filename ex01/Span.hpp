#pragma once

#include <vector>
#include <stdexcept>
#include <algorithm>

class Span
{
	private:
		std::vector<int> _numbers;
		unsigned int _size;
	public:
		//	####################
		//	Constructor & Destructor
		Span();
		Span(unsigned int size);
		~Span();
		//	####################
		//	Member Functions
		void addNumber(int n);
		int shortestSpan();
		int longestSpan();
};
