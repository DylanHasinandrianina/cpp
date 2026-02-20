#ifndef ARRAY_TPP
#define ARRAY_TPP

template <typename T>
Array<T>::Array() : _data(NULL), _size(0){}

/*the '()' in '_data = new T[n]()' here forces default initialization*/
template <typename T>
Array<T>::Array(unsigned int n) : _size(n){
    _data = new T[n]();
}

template <typename T>
Array<T>::Array(const Array& copy) : _size(copy._size){
    if (_size > 0){
        _data = new T[_size];
        for (size_t i = 0; i < copy._size; i++){
            _data[i] = copy._data[i];
        }
    }
    
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& copy){
    if (this != &copy){
        _size = copy._size;
        delete[] _data;
        if (_size > 0){
            _data = new T[_size];
            for (size_t i = 0; i < copy._size; i++){
                _data[i] = copy._data[i];
            }
        }
    }
    return *this;
}

template <typename T>
Array<T>::~Array(){
    delete[] _data;
}

template <typename T>
T& Array<T>::operator[](unsigned int index){
    if (index >= _size)
        throw std::out_of_range("Index out of bounds");
    return _data[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const{
    if (index >= _size)
        throw std::out_of_range("Index out of bounds");
    return _data[index];
}

template <typename T>
size_t Array<T>::size() const{
    return _size;
}

#endif