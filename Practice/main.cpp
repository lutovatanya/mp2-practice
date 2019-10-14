#include <iostream>
#include "TMatrix.h"
#include "Exception.h"
#include <iomanip>

int main()
{

    TVector<double> v1(4), v2(4), v3(2), v4;
    TMatrix<double> m1(3), m2(3), m3(4);

    cout << " enter Vector a = " << endl;
    cin >> v1;
    cout << " Vector a = " << v1 << endl;
    cout << " enter Vector b = " << endl;
    cin >> v2;
    cout << " Vector b = " << v2 << endl;
    cout << " enter Vector c = " << endl;
    cin >> v3;
    cout << " Vector c = " << v3 << endl;

    cout << "\n  Lenght of Vector a = " << v1.lenght() << endl;

    cout << "\n  Vector a * 3 = " << (v1 * 3) << endl;
    cout << "\n  Vector a + 45 = " << (v1 + 45) << endl;
    cout << "\n  Vector a - 34 = " << (v1 - 34) << endl;
    cout << "\n  Vector a * Vector b = " << (v1 * v2) << endl;
    cout << "\n  Vector a - Vector b = " << (v1 - v2) << endl;
    cout << "\n  Vector a + Vector b = " << (v1 + v2) << endl;

    cout << "Vector a = Vector b" << endl;
    cout << (v1 = v2) << endl;

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
        cout << (v1 + v3) << endl;
    }
    catch (C2& e)
    {
        cout << e.what() << endl;
    }

    cout << "\n  Vector a - Vector c = ";
    try
    {
        cout << (v1 - v3) << endl;
    }
    catch (C2& e)
    {
        cout << e.what() << endl;
    }
    cout << "enter Matrix A " << endl;
    cin >> m1;
    cout << " Matrix A = "  << m1 << endl;
    cout << "enter Matrix B " << endl;
    cin >> m2;
    cout << " Matrix B = " << m2 << endl;
    cout << "enter Matrix C " << endl;
    cin >> m3;
    cout << " Matrix С = " << m3 << endl;

    cout << "\n  Matrix A * 2 = " << (m1 * 2) << endl;
    cout << "\n  Matrix A + 34 = " << (m1 + 34) << endl;
    cout << "\n  Matrix A - 1 = " << (m1 - 1) << endl;
    cout << "\n  Matrix A - Matrix B = " << (m1 - m2) << endl;
    cout << "\n  Matrix A + Matrix B = " << (m1 + m2) << endl;
    try
    {
   
    cout << "\n  Matrix A * Matrix B = " << (m1 * m2) << endl;
    cout << "\n  Matrix C * Vector a = " << (m3 * v1) << endl;
    }
    catch (C3& e)
    {
        cout << e.what() << endl;
    }

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