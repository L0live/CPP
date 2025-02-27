#include	"MateriaSource.hpp"
#include	"Character.hpp"
#include	"Ice.hpp"
#include	"Cure.hpp"

int	main()
{
	IMateriaSource* src = new MateriaSource();

    for (size_t i = 0; i < 5; i++) {
        src->learnMateria(new Ice());
    }

	ICharacter* me = new Character("me");
	ICharacter* bob = new Character("bob");

	AMateria* tmp = src->createMateria("ice");
	me->equip(tmp);

	tmp = src->createMateria("cure");
	me->equip(tmp);

	src->learnMateria(new Cure());

	tmp = src->createMateria("s");
	me->equip(tmp);
	
	me->use(0, *bob);
	me->use(1, *bob);
	me->unequip(1);
	me->use(1, *bob);

	ICharacter* test = new Character("test");

	for (size_t i = 0; i < 100; i++)
	{
		tmp = src->createMateria("ice");
		test->equip(tmp);
		test->unequip(0);
        delete tmp;
	}
	test->use(0, *me);

	delete bob;
	delete me;
	delete test;
	delete src;
	return (0);
}