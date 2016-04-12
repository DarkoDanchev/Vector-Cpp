#pragma once
#include <iostream>
template <typename T>
class Vector
{
private:
   T* vec;
   size_t size;
   size_t currSize;

public:
   Vector();
   Vector(size_t);
   Vector(Vector const&);
   Vector& operator=(Vector const&);
   void Print() const;
   T operator[](size_t);
   void add(T);

   size_t getSize() const;
   size_t getCurrSize() const;
   void resize();
   ~Vector();
};

using namespace std;
template <typename T>
Vector<T>::Vector()
{
    this->size = 4;
    this->currSize = 0;
    this->vec = new T[this->size];
}
template <typename T>
Vector<T>::Vector(size_t size)
{
    this->size = size;
    this->currSize = 0;
    this->vec = new T[this->size];
}
template <typename T>
Vector<T>::Vector(Vector const& vec)
{
   this->size = vec.size;
   this->currSize = vec.currSize;
   this->vec = new T[this->size];
   for(size_t i = 0; i < this->currSize; i++)
   {
       this->vec[i] = vec.vec[i];
   }
}
template <typename T>
Vector<T>& Vector<T>::operator=(Vector const& vec)
{
    if(this != &vec)
    {
        this->size = vec.size;
        this->currSize = vec.currSize;
        delete [] this->vec;
        this->vec = new T[this->size];
        for(size_t i = 0; i < this->currSize;i++)
        {
            this->vec[i] = vec.vec[i];
        }
    }
    return *this;
}
template <typename T>
void Vector<T>::Print() const
{
    for(size_t i = 0; i < this->currSize; i++)
    {
        cout<<this->vec[i];
    }
}
template <typename T>
T Vector<T>::operator[](size_t index)
{
    return this->vec[index];
}
template <typename T>
void Vector<T>::add(T element)
{
    if(this->currSize == this->size) this->resize();
    this->vec[currSize++] = element;
}
template <typename T>
size_t Vector<T>::getSize() const
{
    return this->size;
}
template <typename T>
size_t Vector<T>::getCurrSize() const
{
    return this->currSize;
}
template <typename T>
void Vector<T>::resize()
{
    this->size =this->size*2+1;
    T* temp = new T[this->size];
    for(size_t i = 0; i < this->currSize;i++)
    {
        temp[i] = this->vec[i];
    }
    delete [] this->vec;

    this->vec = temp;
}
template <typename T>
Vector<T>::~Vector()
{
    delete [] this->vec;
}


