#include "Serializer.hpp"

int main(){
    Data data;
    data.i = 42;

    uintptr_t raw = Serializer::serialize(&data);
    Data* ptr = Serializer::deserialize(raw);

    std::cout << "Raw value of the pointer : " << raw << std::endl;

    std::cout << "Original adress : " << &data << std::endl;
    std::cout << "Deserialized adress : " << ptr << std::endl;

    return 0;

}