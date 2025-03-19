#include "MutantStack.hpp"
#include <list>

int main() {
	{	MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << "Top: " << mstack.top() << std::endl;

		mstack.pop();

		std::cout << "Size: " << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		--it;
		while (++it != ite) {
			std::cout << *it << (it + 1 != ite? ", ": "\n");
		}
		
		std::stack<int> tmp(mstack);
		std::cout << std::endl;
	}
	{	std::list<int> alist;

		alist.push_back(5);
		alist.push_back(17);

		std::cout << "Top: " << alist.back() << std::endl;

		alist.pop_back();

		std::cout << "Size: " << alist.size() << std::endl;

		alist.push_back(3);
		alist.push_back(5);
		alist.push_back(737);
		alist.push_back(0);

		std::list<int>::iterator it = alist.begin();
		std::list<int>::iterator ite = alist.end();

		--it;
		while (++it != ite) {
			std::cout << *it++ << (it-- != ite? ", ": "\n");
		}
	}
	return 0;
}