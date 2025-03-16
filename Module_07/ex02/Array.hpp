#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template <typename T>
class Array {
private:
	T   *_array;
	unsigned int	_size;
public:
	Array() : _array(new T[0]) {}
	Array(unsigned int n) : _array(new T[n]), _size(n) {}
	Array(Array &src) : _array(NULL) {*this = src;}
	Array &operator=(Array &src) {
		if (_array)
			delete []_array;
		_size = src.size();
		_array = new T[_size];
		for (size_t i = 0; i < _size; i++)
			_array[i] = src[i];
		return *this;
	}
	~Array() {delete []_array;}

	class OutOfBoundsException : public std::exception {
	public:
		OutOfBoundsException() {}
		const char* what() const throw() {return "Error: index is OutOfBounds";}
	};

	T	&operator[](unsigned int index) {
		if (index >= _size)
			throw OutOfBoundsException();
		return _array[index];
	}
	unsigned int	size() const {return _size;}
};

#endif