// Реализуйте шаблонную версию класса Array. Список всех операций, которые должен поддерживать класс Array, приведен в шаблоне кода.

#include <cstddef>


template <typename T>
class Array {
public:
    explicit Array(size_t size = 0, const T& value = T());
    Array(Array const& other);
    ~Array();
    Array<T> & operator=(Array const& other);
    size_t size() const;
    T & operator[](size_t index);
    const T & operator[](size_t index) const ;

private:
    T * arr;
    size_t size_;
};

template<typename T>
Array<T>::Array(size_t size, const T & value) : size_(size), arr(new T[size]) {
    for (size_t i = 0; i < this->size_; ++i)
        arr[i] = value;
}

template<typename T>
Array<T>::Array(Array const &other) : size_(other.size_), arr(new T[other.size_]) {
    for (size_t i = 0; i < this->size_; ++i)
        this->arr[i] = other.arr[i];
}

template<typename T>
Array<T>::~Array() {
    delete [] arr;
}

template<typename T>
Array<T> & Array<T>::operator=(Array const & other) {
    if (this != &other) {
        delete [] this->arr;
        this->size_ = other.size_;
        this->arr = new T[this->size_];
        for (auto i = 0; i < this->size_; ++i)
            this->arr[i] = other.arr[i];
    }
    return *this;
}

template<typename T>
size_t Array<T>::size() const {
    return this->size_;
}

template<typename T>
T & Array<T>::operator[](size_t index) {
    return this->arr[index];
}

template<typename T>
const T & Array<T>::operator[](size_t index) const {
    return this->arr[index];
}
