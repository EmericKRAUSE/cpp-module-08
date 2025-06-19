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
		Span(const Span& obj);
		~Span();

		//	####################
		//	Overload operator
		Span& operator=(const Span& obj);

		//	####################
		//	Member Functions
		void addNumber(int n);
		template <typename Iterator>
		void addNumbers(Iterator begin, Iterator end)
		{
			if (std::distance(begin, end) > static_cast<long>(this->_size - _numbers.size()))
				throw std::overflow_error("Not enough space left in the span");
			for (; begin != end; begin++)
				this->_numbers.push_back(*begin);
		}
		int shortestSpan();
		int longestSpan();
		int	getNumber(unsigned int n) const;
};
