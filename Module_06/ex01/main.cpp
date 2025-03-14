#include "Serializer.hpp"

int main(void) { // You need to add some stuff to Data.
    Data    *data = new Data;
    uintptr_t   ptr;

    data->someData = "Hello world";
    data->someOtherData = "Hello other world";

    std::cout << "Before: " << std::endl;
    std::cout << "data ptr: " << data << std::endl;
    std::cout << data->someData << std::endl;
    std::cout << data->someOtherData << std::endl;

    ptr = Serializer::serialize(data);
    data = Serializer::deserialize(ptr);
    
    std::cout << "After: " << std::endl;
    std::cout << "uintptr_t: " << ptr << std::endl;
    std::cout << "data ptr: " << data << std::endl;
    std::cout << data->someData << std::endl;
    std::cout << data->someOtherData << std::endl;

    delete data;
    return 0;
}