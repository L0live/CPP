#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(new T[0]) {}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n) {}

template <typename T>
Array<T>::Array(Array<T> &src) : _array(NULL) {*this = src;}

template <typename T>
Array<T> &Array<T>::operator=(Array<T> &src) {
    if (_array)
        delete []_array;
    _size = src.size();
    _array = new T[_size];
    for (size_t i = 0; i < _size; i++)
        _array[i] = src[i];
    return *this;
}

template <typename T>
Array<T>::~Array() {delete []_array;}

template <typename T>
T	&Array<T>::operator[](unsigned int index) {
    if (index >= _size)
        throw OutOfBoundsException();
    return _array[index];
}

template <typename T>
unsigned int	Array<T>::size() const {return _size;}