#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <exception>
#include <vector>

class Span {
private:
	std::vector<int>	_vectorStore;
	unsigned int	_sizeMax;
public:
	Span();
	Span(unsigned int N);
	Span(Span &src);
	Span &operator=(Span &src);
	~Span();

	class IsFullException : public std::exception {
	public:
		IsFullException() {}
		const char* what() const throw() {return "Error: Span is full";}
	};

	class NotEnoughException : public std::exception {
	public:
		NotEnoughException() {}
		const char* what() const throw() {return "Error: Span not have enough integers";}
	};

	void	addNumber(int number);
	void	addSomeNumbers(std::vector<int> numbers);
	int	shortestSpan();
	int	longestSpan();
};

#endif