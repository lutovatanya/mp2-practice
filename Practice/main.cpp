#include <iostream>
#include "TMatrix.h"
#include "Exception.h"

int main()
{

    TVector<int>  v1(5, 0), v2(5, 0), v3(2, 0);
    TMatrix<int>m1(3), m2(3), m3(5);

    for (int i = 0; i < 5; i++)
    {
        v1.Random1();
        v2.Random1();
        v3.Random1();
    }
    cout << " Vector a = " << v1 << endl;
    cout << " Vector b = " << v2 << endl;
    try
    {
        cout << "\n  Lenght of Vector a = " << v1.lenght() << endl;
    }
    catch (C1& e)
    {
        cout << e.what() << endl;
    }
    cout << "\n  Vector a * 3 = " << (v1 * 3) << endl;
    cout << "\n  Vector a + 45 = " << (v1 + 45) << endl;
    cout << "\n  Vector a - 34 = " << (v1 - 34) << endl;
    cout << "\n  Vector a * Vector b = " << (v1 * v2) << endl;
    cout << "\n  Vector a - Vector b = " << (v1 - v2) << endl;
    cout << "\n  Vector a + Vector b = " << (v1 + v2) << endl;

    cout << "Vector c =" << v3 << endl;

    cout << "\n  Vector a * Vector c = ";
    try
    {
        cout << (v1 * v3) << endl;
    }
    catch (C2& e)
    {
        cout << e.what() << endl;
    }

    cout << "\n  Vector a + Vector c = ";
    try
    {
        cout  << (v1 + v3) << endl;
    }
    catch (C2& e)
    {
        cout << e.what() << endl;
    }

    cout << "\n  Vector a - Vector c = ";
    try
    {
        cout  << (v1 - v3) << endl;
    }
    catch (C2& e)
    {
        cout << e.what() << endl;
    }
    for (int i = 0; i < 5; i++)
    {
        m1.Random();
        m2.Random();
        m3.Random();
    }
    
    cout << " Matrix A = " << m1 << endl;
    cout << " Matrix B = " << m2 << endl;
    
    cout << "\n  Matrix A * 2 = " << (m1 * 2) << endl;
    cout << "\n  Matrix A + 34 = " << (m1 + 34) << endl;
    cout << "\n  Matrix A - 1 = " << (m1 - 1) << endl;
    cout << "\n  Matrix A - Matrix B = " << (m1 - m2) << endl;
    cout << "\n  Matrix A + Matrix B = " << (m1 + m2) << endl;
    cout << "\n  Matrix A * Matrix B = " << (m1 * m2) << endl;
    cout << "\n  Matrix C * Vector a = " << (m3 * v1) << endl;

    cout << "Matrix A * Vector a = ";
    try
    {
        cout  << (m1 * v1) << endl;
    }
    catch (C2& e)
    {
        cout << e.what() << endl;
    }

    cout << "Matrix A * Matrix C = ";
    try
    {
        cout  << (m1 * m3) << endl;
    }
    catch (C2& e)
    {
        cout << e.what() << endl;
    }

    cout << "Matrix A + Matrix C = ";
    try
    {
        cout  << (m1 + m3) << endl;
    }
    catch (C2& e)
    {
        cout << e.what() << endl;
    }
    cout << "Matrix A - Matrix C = ";
    try
    {
        cout << (m1 - m3) << endl;
    }
    catch (C2& e)
    {
        cout << e.what() << endl;
    }
    system("pause");
}