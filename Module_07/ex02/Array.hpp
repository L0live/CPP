#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template <typename T>
class Array {
private:
	T   *_array;
	unsigned int	_size;
public:
	Array();
	Array(unsigned int n);
	Array(Array<T> &src);
	Array<T> &operator=(Array<T> &src);
	~Array();

	class OutOfBoundsException : public std::exception {
	public:
		OutOfBoundsException() {}
		const char* what() const throw() {return "Error: index is OutOfBounds";}
	};

	T	&operator[](unsigned int index);
	unsigned int	size() const;
};

#include "Array.tpp"

#endif