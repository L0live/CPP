#include "Brain.hpp"

Brain::Brain() {std::cout << "Brain default constructor called" << std::endl;}

Brain::Brain(const Brain &src) {
	copyIdeas(src);
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain::~Brain() {std::cout << "Brain destructor called" << std::endl;}

Brain &Brain::operator=(const Brain &src) {
	if (this == &src) {
		return *this;
	}
	copyIdeas(src);
	return *this;
}

void Brain::setIdea(std::string idea, int index) {
	if (index >= 0 && index < 100) {
		ideas[index] = idea;
	}
	else
		std::cout << "Index out of range" << std::endl;
}

std::string Brain::getIdea(int index) const {
	if (index >= 0 && index < 100) {
		return ideas[index];
	}
	else
		std::cout << "Index out of range" << std::endl;
	return "";
}

void Brain::copyIdeas(const Brain &src) {
	for (int i = 0; i < 100; i++) {
		ideas[i] = src.ideas[i];
	}
}