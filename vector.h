#ifndef VECTOR_H
#define VECTOR_H

#include <stdexcept>

template <typename Tr>
class Vector {
    public:
        typedef typename Tr::T T;
        typedef typename Tr::Operation Operation;
             
    private:
        T* data;
        int dataSize;

        int dimensions;
        int* dimensionSizes;
        Operation conv;

    public:
        Vector() : data(NULL) {};
             
        Vector(int dimensions, int* dimensionSizes) : 
            dimensions(dimensions), 
            dimensionSizes(dimensionSizes),
            dataSize(1) 
        {
            for(int i = 0; i < dimensions; i++)
            {
                dataSize *= *dimensionSizes;
                dimensionSizes++;
            }
            data = new T[dataSize];
        }
             
        void set(T datum, int* coordinates)
        {
            int position =conv(coordinates,dimensionSizes,dimensions);
            
            if (position >= dataSize)
            {
                throw std::out_of_range("out of range");
            }

            T* temporal = data+position;
            *temporal = datum;
            return;
        }
             
        T get(int* coordinates)
        {
            int position = conv(coordinates,dimensionSizes,dimensions);
            

            if (position >= dataSize)
            {
                throw std::out_of_range("out of range");
            }

            T* temporal = data+position;
            return *temporal;
        }
};

#endif
