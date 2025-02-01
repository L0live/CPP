#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; i++) {
        _source[i] = NULL;
    }
}

MateriaSource::MateriaSource(MateriaSource const & src) {
    *this = src;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++) {
        if (_source[i]) {
            delete _source[i];
        }
    }
}

MateriaSource & MateriaSource::operator=(MateriaSource const & src) {
    if (this != &src) {
        for (int i = 0; i < 4; i++) {
            if (_source[i]) {
                delete _source[i];
            }
            _source[i] = src._source[i]->clone();
        }
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria* m) {
    for (int i = 0; i < 4; i++) {
        if (!_source[i]) {
            _source[i] = m;
            return;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; i++) {
        if (_source[i] && _source[i]->getType() == type) {
            return _source[i]->clone();
        }
    }
    return NULL;
}