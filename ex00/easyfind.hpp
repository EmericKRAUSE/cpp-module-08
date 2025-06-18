#pragma once

#include <algorithm>
#include <exception>

class NotInContainer : public std::exception
{
	public:
		const char *what() const throw()
		{
			return ("This element is not in the container");
		}
};

template <typename T>
typename T::const_iterator	easyfind(const T& container, int toSearch)
{
	typename T::const_iterator it;
	it = std::find(container.begin(), container.end(), toSearch);
	if (it == container.end())
		throw NotInContainer();
	return (it);
}
