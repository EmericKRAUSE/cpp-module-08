#include "Span.hpp"

//	####################
//	Constructor & Destructor
Span::Span()
{

}

Span::Span(unsigned int size)
	: _size(size)
{

}

Span::Span(const Span& obj)
{
	*this = obj;
}

Span::~Span()
{

}

//	####################
//	Overload operator
Span& Span::operator=(const Span &obj)
{
	if (this != &obj)
	{
		this->_size = obj._size;
		this->_numbers = obj._numbers;
	}
	return (*this);
}

//	####################
//	Member Functions
void Span::addNumber(int n)
{
	if (this->_numbers.size() >= this->_size)
		throw std::overflow_error("Size overflow");
	this->_numbers.push_back(n);
}

int Span::shortestSpan()
{
	if (this->_numbers.size() < 2)
		throw std::overflow_error("No span can be found");
	std::vector<int> tmp = this->_numbers;
	std::vector<int>::const_iterator it = tmp.begin();
	int	shortest;

	std::sort(tmp.begin(), tmp.end());
	shortest = (*(it + 1)) - (*it);
	while (it != tmp.end() - 1)
	{
		if ((*(it + 1)) - (*it) < shortest)
			shortest = (*(it + 1)) - (*it);
		it++;
	}
	return (shortest);
}

int Span::longestSpan()
{
	std::vector<int>::const_iterator min;
	std::vector<int>::const_iterator max;

	if (this->_numbers.size() < 2)
		throw std::overflow_error("No span can be found");
	min = std::min_element(this->_numbers.begin(), this->_numbers.end());
	max = std::max_element(this->_numbers.begin(), this->_numbers.end());
	return (*max - *min);
}

int Span::getNumber(unsigned int n) const
{
	if (n >= this->_size)
		throw std::overflow_error("Index is out of bounds");
	return (this->_numbers[n]);
}