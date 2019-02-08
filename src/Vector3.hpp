#ifndef VECTOR3_HPP
#define VECTOR3_HPP

#include <Arduino.h>

template<typename T>
class Vector3
{
public:
    Vector3(const Vector3<T>& copy) {
        data_x = copy.data_x;
        data_y = copy.data_y;
        data_z = copy.data_z;
    }

    Vector3(T x, T y, T z) {
        data_x = x;
        data_y = y;
        data_z = z;
    }

    Vector3 operator+(const Vector3<T>& rhs) const {
        Vector3 result { rhs };

        rhs.data_x += data_x;
        rhs.data_y += data_y;
        rhs.data_z += data_z; 

        return result;      
    }

    T operator[](size_t n) const {
        if(n == 0)
            return data_x;
        else if(n == 1)
            return data_y;
        else if(n == 2)
            return data_z;
        else
            throw String("Out of bound index.");     
    }

    T& operator[](size_t n) {
        if(n == 0)
            return data_x;
        else if(n == 1)
            return data_y;
        else if(n == 2)
            return data_z;
        else
            throw String("Out of bound index.");     
    }


private:
    T data_x;
    T data_y;
    T data_z;
};

#endif // VECTOR3_HPP