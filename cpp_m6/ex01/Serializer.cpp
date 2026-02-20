#include "Serializer.hpp"

Serializer::Serializer(){}

Serializer::Serializer(const Serializer& copy){
    (void)copy;
}

Serializer& Serializer::operator=(const Serializer& copy){
    (void)copy;
    return *this;
}

Serializer::~Serializer(){}

uintptr_t Serializer::serialize(Data* ptr){

    uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
    return raw;
}

Data* Serializer::deserialize(uintptr_t raw){

    Data* d = reinterpret_cast<Data*>(raw);
    return d;
}

