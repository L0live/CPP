#include "Span.hpp"

Span::Span() : _sizeMax(10000) {}

Span::Span(unsigned int N) : _sizeMax(N) {}

Span::Span(Span &src) {*this = src;}

Span	&Span::operator=(Span &src) {
	_vectorStore = src._vectorStore;
	_sizeMax = src._sizeMax;
	return *this;
}

Span::~Span() {}

void	Span::addNumber(int number) {
	if (_vectorStore.size() >= _sizeMax)
		throw IsFullException();
	_vectorStore.push_back(number);
}

void	Span::addSomeNumbers(std::vector<int> numbers) {
	if (_vectorStore.size() + numbers.size() > _sizeMax)
		throw IsFullException();
	_vectorStore.insert(_vectorStore.end(), numbers.begin(), numbers.end());
}

int	Span::shortestSpan() {
	if (_vectorStore.size() <= 1)
		throw NotEnoughException();
	std::vector<int> tmp = _vectorStore;

	std::sort(tmp.begin(), tmp.end());
	int	shortest = *(tmp.begin() + 1) - *(tmp.begin());
	for (std::vector<int>::iterator i = tmp.begin() + 1; i + 1 < tmp.end(); ++i) {
		if (*(i + 1) - *i < shortest)
			shortest = *(i + 1) - *i;
	}
	return shortest;
}

int	Span::longestSpan() {
	if (_vectorStore.size() <= 1)
		throw NotEnoughException();
	return *(std::max_element(_vectorStore.begin(), _vectorStore.end())) - *(std::min_element(_vectorStore.begin(), _vectorStore.end()));
}