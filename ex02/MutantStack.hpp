#pragma once

#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T>
{
	private:

	public:
		MutantStack() {}
		MutantStack(const MutantStack &obj) : std::stack<T>(obj) {}
		~MutantStack() {}

		MutantStack& operator=(const MutantStack &obj)
		{
			if (this != &obj)
				std::stack<T>::operator=(obj);
			return (*this);
		}

		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		iterator begin()
		{ return  this->c.begin(); }
		const_iterator begin() const
		{ return this->c.begin(); }

		iterator end()
		{ return  this->c.end(); }
		const_iterator end() const
		{ return this->c.end(); }

		reverse_iterator rbegin()
		{ return this->c.rbegin(); }
		const_reverse_iterator rbegin() const
		{ return this->c.rbegin(); }

		reverse_iterator rend()
		{ return this->c.rend(); }
		const_reverse_iterator rend() const
		{ return this->c.rend(); }
};
