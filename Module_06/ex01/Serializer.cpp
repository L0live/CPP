#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(Serializer &src) {*this = src;}

Serializer &Serializer::operator=(Serializer &src) {
    (void)src;
    return *this;
}

Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data* ptr) {return reinterpret_cast<uintptr_t>(ptr);}

Data *Serializer::deserialize(uintptr_t raw) {return reinterpret_cast<Data *>(raw);}