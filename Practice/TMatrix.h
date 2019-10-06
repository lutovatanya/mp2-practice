#ifndef _TMATRIX_H_ 
#define _TMATRIX_H_ 
#define RAND 4

#include <iostream>
#include "Exception.h"

using namespace std;

template<typename ValueType>
class TVector
{
protected:
    int size;
    ValueType* elements;
    int startIndex;
public:
    TVector(int n = 10, int startInd = 0);
    ~TVector();
    TVector(const TVector&);
    int GetSize() const;
    int GetIndex() const;
    ValueType lenght() const;
    TVector& operator=(const TVector&);
    TVector operator+(ValueType);
    TVector operator+(const TVector&);
    TVector operator-(ValueType);
    TVector operator-(const TVector&);
    TVector operator*(ValueType);
    TVector operator*(const TVector&);
    bool operator==(const TVector&)const;
    bool operator!=(const TVector&)const;
    ValueType& operator[](int); //на запись
    const ValueType& operator[](int) const; //на чтение
    void Random1();

    friend ostream& operator << (ostream & o, const TVector& x)
    {
        cout << "\n ";
        for (int i = 0; i < x.GetIndex(); i++)
            o << "  ";
        for (int i = 0; i < x.size; i++)
        {
            o << x.elements[i] << " ";
        }
        return o;
    }
    friend istream& operator >> (istream & o, TVector& x)
    {
        for (int i = 0; i < x.size; i++)
        {
            o >> x.elements[i] >> " ";
        }
        return o;
    }
};

template<typename ValueType>
void TVector<ValueType>::Random1()
{
    for (int i = 0; i < size; i++)
        elements[i] = rand() % RAND + 1;
}

template<typename ValueType>
TVector<ValueType>::TVector(int n, int startInd)
{
    if (n <= 0)
    {
        throw C1();
    }
    elements = new ValueType[n];
    size = n;
    startIndex = startInd;

}

template<typename ValueType>
TVector<ValueType>::~TVector()
{
    size = 0;
    startIndex = 0;
    delete[] elements;
    elements = nullptr;
}

template<typename ValueType>
TVector<ValueType>::TVector(const TVector& x)
{
    size = x.size;
    startIndex = x.startIndex;
    elements = new ValueType[size];
    for (int i = 0; i < size; i++)
        elements[i] = x.elements[i];
}

template<typename ValueType>
TVector<ValueType> & TVector<ValueType>::operator=(const TVector& vector)
{
    if (&vector != this)
    {
    if (size != vector.size)
    {
        delete[] elements;
        size = vector.size;
        elements = new ValueType[size];
    }
    startIndex = vector.startIndex;
    for (int i = 0; i < vector.size; i++)
        elements[i] = vector.elements[i];
    }
    return *this;
}
                                                                                                     
template<typename ValueType>
TVector<ValueType> TVector<ValueType>::operator+(const TVector& vector)
{
    if ((size != vector.size) || (startIndex != vector.startIndex))
    {
        throw C2();
    }
    TVector<ValueType> vector1(*this);
        for (int i = 0; i < size; i++)
            vector1.elements[i] = vector1.elements[i] + vector.elements[i];
    return vector1;
}

template<typename ValueType>
TVector<ValueType> TVector<ValueType>::operator-(const TVector& vector)
{
    if ((size != vector.size) || (startIndex != vector.startIndex))
    {
        throw C2();
    }
    TVector<ValueType> vector1(*this);
        for (int i = 0; i < size; i++)
            vector1.elements[i] = vector1.elements[i] - vector.elements[i];
    return vector1;
}

template<typename ValueType>
TVector<ValueType> TVector<ValueType>::operator*(const TVector& vector)
{
    if ((size != vector.size) || (startIndex != vector.startIndex))
    {
        throw C2();
    }
    TVector<ValueType> vector1(*this);
        for (int i = 0; i < size; i++)
            vector1.elements[i] = vector1.elements[i] * vector.elements[i];
    return vector1;
}

template<typename ValueType>
TVector<ValueType> TVector<ValueType>::operator+(ValueType a)
{
    TVector<ValueType> vector1(*this);
        for (int i = 0; i < size; i++)
            vector1.elements[i] = vector1.elements[i] + a;
    return vector1;
}

template<typename ValueType>
TVector<ValueType> TVector<ValueType>::operator-(ValueType a)
{
    TVector<ValueType> vector1(*this);
        for (int i = 0; i < size; i++)
            vector1.elements[i] = vector1.elements[i] - a;
    return vector1;
}

template<typename ValueType>
TVector<ValueType> TVector<ValueType>::operator*(ValueType a)
{
    TVector<ValueType> vector1(*this);
        for (int i = 0; i < size; i++)
            vector1.elements[i] = vector1.elements[i] * a;
    return vector1;
}

template<typename ValueType>
ValueType & TVector<ValueType>::operator[](int idx)
{
    if ((idx < 0) || (idx >= size))
        throw C3();
        return elements[idx];
}

template<typename ValueType>
const ValueType & TVector<ValueType>::operator[](int idx) const
{
    if ((idx < 0) || (idx >= size))
        throw C3();
        return elements[idx];
}

template<typename ValueType>
bool TVector<ValueType>::operator==(const TVector& v2)const
{
    if ((size != v2.size) || (startIndex != v2.startIndex))
        return false;
    for (int i = 0; i < size; i++)
    {
        if (v2.elements[i] != elements[i])
            return false;
    }
    return true;
}

template<typename ValueType>
bool TVector<ValueType>::operator!=(const TVector& v2)const
{
    if ((size != v2.size) || (startIndex != v2.startIndex))
        return false;
    for (int i = 0; i < size; i++)
    {
        if (v2.elements[i] == elements[i])
            return false;
    }
    return true;
}

template<typename ValueType>
ValueType TVector<ValueType>::lenght() const
{
    if (size <= 0)
    { 
        throw C1();
    }
    double res = 0;
    for (int i = 0; i < size; i++)
    {
        res += elements[i] * elements[i];
    }
    return sqrt(res);
}

template<class ValType>
int TVector<ValType>::GetSize() const
{
    return size;
}

template<class ValType>
int TVector<ValType>::GetIndex() const
{
    return startIndex;
}

//_____МАТРИЦА

template<typename ValueType>
class TMatrix :TVector<TVector<ValueType> >
{
public:
    TMatrix(int n = 10);
    ~TMatrix();
    TMatrix(const TMatrix&);
    TMatrix(const TVector<TVector<ValueType> >&);
    TMatrix& operator=(const TMatrix&);
    TMatrix operator+(ValueType);
    TMatrix operator+(const TMatrix&);
    TMatrix operator-(ValueType);
    TMatrix operator-(const TMatrix&);
    TMatrix operator*(ValueType);
    bool operator==(const TMatrix&)const;
    bool operator!=(const TMatrix&)const;
    TMatrix operator*(const TMatrix&);
    TVector<ValueType> operator*(const TVector<ValueType>&);
    void Random();

    friend ostream& operator << (ostream & o, const TMatrix& x)
    {
        for (int i = 0; i < x.size; i++)
        {
            cout << endl << x.elements[i] << " ";
   
        }
        return o;
    }

    friend istream& operator >> (istream & o, TMatrix& x)
    {
        for (int i = 0; i < x.size; i++)
        {
            cin >> x.elements[i] >> " ";
        }
        return o;
    }
};

template<typename ValueType>
TMatrix<ValueType>::TMatrix(int n): TVector<TVector<ValueType> >(n)
{
    for (int i = 0; i < n; i++)
       this->elements[i] = TVector<ValueType>(n - i, i);
}

template<typename ValueType>
TMatrix<ValueType>::~TMatrix()
{}

template<typename ValueType>
TMatrix<ValueType>::TMatrix(const TMatrix<ValueType>& m)
{
    this->size = m.size;
    this->elements = new TVector<ValueType>[m.size];
    for (int i = 0; i < m.size; i++)
       this->elements[i] = m.elements[i];
}


template<typename ValueType>
TMatrix<ValueType>::TMatrix(const TVector<TVector<ValueType> >& v) : TVector<TVector<ValueType> >(v)
{}

template<typename ValueType>
TMatrix<ValueType> TMatrix<ValueType>::operator+(const TMatrix& matrix)
{
    if (this->size != matrix.size)
    {
        throw C2();
    }
    TMatrix<ValueType> m(*this);
        for (int i = 0; i < this->size; i++)
            m.elements[i] = m.elements[i] + matrix.elements[i];
    return m;
}

template<typename ValueType>
TMatrix<ValueType> TMatrix<ValueType>::operator*(const TMatrix& m)
{
    if (this->size != m.size)
    {
        throw C2();
    }
        
    TMatrix<ValueType> Matrix(*this);
    for (int i = 0; i < this->size; i++)
        for (int j = this->elements[i].GetIndex(); j < this->size; j++)
            for (int k = i; k <= j; k++)
                Matrix.elements[i][j - i] += this->elements[i][k - i] * m.elements[k][j - k];
    return Matrix;
}

template<typename ValueType>
TVector<ValueType> TMatrix<ValueType>::operator*(const TVector<ValueType>& x)
{
    if (this->size != x.GetSize())
    {
        throw C2();
    }
    TVector<ValueType> Vec(this->size);
    for (int i = 0; i < this->size; i++)
    {
        Vec[i] = 0;
        for (int j = this->elements[i].GetIndex(); j < this->elements[i].GetSize(); j++)
            Vec[i] += this->elements[i][j] * x[i + j];
    }

    return Vec;
}

template<typename ValueType>
TMatrix<ValueType> TMatrix<ValueType>::operator-(const TMatrix& matrix)
{
    if (this->size != matrix.size)
    {
        throw C2();
    }
    TMatrix<ValueType> m(*this);
        for (int i = 0; i < this->size; i++)
            m.elements[i] = m.elements[i] - matrix.elements[i];
    return m;
}

template<typename ValueType>
TMatrix<ValueType> TMatrix<ValueType>::operator+(ValueType a)
{
    TMatrix<ValueType> m(*this);
        for (int i = 0; i < this->size; i++)
            m.elements[i] = m.elements[i] + a;
    return m;
}

template<typename ValueType>
TMatrix<ValueType> TMatrix<ValueType>::operator-(ValueType a)
{
    TMatrix<ValueType> m(*this);
        for (int i = 0; i < this->size; i++)
            m.elements[i] = m.elements[i] - a;
    return m;
}

template<typename ValueType>
TMatrix<ValueType> TMatrix<ValueType>::operator*(ValueType a)
{

    TMatrix<ValueType> m(*this);
        for (int i = 0; i < m.size; i++)
            m.elements[i] = m.elements[i] * a;
    return m;
}

template<typename ValueType>
bool TMatrix<ValueType>::operator!=(const TMatrix & mtr) const
{
    return !(mtr == (*this));
}

template<typename ValueType>
TMatrix<ValueType> & TMatrix<ValueType>::operator=(const TMatrix & mtr)
{
    if (this != &mtr)
    {
        if (this->size != mtr.size)
        {
            this->size = mtr.size;
            delete[] this->elements;
            this->elements = new TVector<ValueType>[mtr.size];
        }
        for (int i = 0; i < mtr.size; i++)
        {
            this->elements[i] = mtr.elements[i];
        }
    }
    return *this;
}

template<typename ValueType>
bool TMatrix<ValueType>::operator==(const TMatrix & mtr) const
{
    if (this->size != mtr.size)
        throw C2();
    for (int i = 0; i < mtr.size; i++)
    {
        if (this->elements[i] != mtr.elements[i])
            return false;
    }
    return true;
}

template<typename ValType>
void TMatrix<ValType>::Random()
{
    for (int i = 0; i < this->size; i++)
        this->elements[i].Random1();
        for(int j = 0; j < this->size; j++)
        this->elements[j].Random1();
}
#endif