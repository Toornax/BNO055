#ifndef VECTOR3_HPP
#define VECTOR3_HPP

#include <Arduino.h>

template<typename T>
class Vector3<T>
{
public:
    Vector3(const Vector3<T>& copy) {
        this->data_x = copy.data_x;
        this->data_y = copy.data_y;
        this->data_z = copy.data_z;
    }

    Vector3(T x, T y, T z) {
        this->data_x = x;
        this->data_y = y;
        this->data_z = z;
    }

    Vector3 operator+(const Vector3<T>& rhs) const {
        Vector3 result { rhs };

        rhs.data_x += this->data_x;
        rhs.data_y += this->data_y;
        rhs.data_z += this->data_z; 

        return result;      
    }

    T operator[](size_t n) const {
        if(n == 0)
            return this->data_x;
        else if(n == 1)
            return this->data_y;
        else if(n == 2)
            return this->data_z;
        else
            throw String("Out of bound index.");     
    }

    T& operator[](size_t n) {
        if(n == 0)
            return this->data_x;
        else if(n == 1)
            return this->data_y;
        else if(n == 2)
            return this->data_z;
        else
            throw String("Out of bound index.");     
    }


private:
    T data_x;
    T data_y;
    T data_z;
};

#endif // VECTOR3_HPP