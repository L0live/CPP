#include "Serializer.hpp"

int main(void) { // You need to add some stuff to Data.
    Data    *data = new Data;
    uintptr_t   ptr;

    std::cout << "Data address on creation: " << data << std::endl;

    ptr = Serializer::serialize(data);
    data = Serializer::deserialize(ptr);

    std::cout << "uintptr_t (serialization): " << ptr << std::endl;
    std::cout << "Data address (deserialization): " << data << std::endl;
    
    return 0;
}