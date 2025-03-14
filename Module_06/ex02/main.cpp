#include "Base.hpp"

Base    *generate(void) {
	srand(time(NULL));
	switch (rand() % 3) {
	case 0:
		return new A;
	case 1:
		return new B;
	case 2:
		return new C;
	}
	return NULL;
}

void	identify(Base *p) {
	if (dynamic_cast<A *>(p))
		std::cout << "p: A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "p: B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "p: C" << std::endl;
	else
		std::cout << "Error: impossible to identify ptr" << std::endl;
}

void	identify(Base &p) {
	try {A &ref = dynamic_cast<A &>(p);
		std::cout << "p: A" << std::endl;
		(void)ref;
		return ;
	} catch(...) {}
	try {B &ref = dynamic_cast<B &>(p);
		std::cout << "p: B" << std::endl;
		(void)ref;
		return ;
	} catch(...) {}
	try {C &ref = dynamic_cast<C &>(p);
		std::cout << "p: C" << std::endl;
		(void)ref;
		return ;
	} catch(...) {}
	std::cout << "Error: impossible to identify ref" << std::endl;
}

int main(void) {
	Base	*base = generate();

	identify(base);
	identify(*base);

	delete base;
	return 0;
}