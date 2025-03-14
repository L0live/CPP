#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

typedef struct s_Data {
    std::string someData;
    std::string someOtherData;
}	Data;

class Serializer {
private:
	Serializer();
	Serializer(Serializer &src);
	Serializer &operator=(Serializer &src);
	~Serializer();
public:
	static uintptr_t serialize(Data* ptr);
	static Data *deserialize(uintptr_t raw);
};

#endif