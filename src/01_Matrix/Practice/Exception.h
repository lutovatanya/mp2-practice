#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_

#include <exception>
#include <string>
 
using namespace std;

class C1 : exception
{
    const string what_str = "size less than 0";
public:
    const char* what() const { return what_str.c_str(); }
};

class C2 : exception
{
    const string what_str = "Different sizes or Indexes";
public:
    const char* what() const { return what_str.c_str(); }
};

class C3 : exception
{
    const string what_str = "Выход за границы массива";
public:
    const char* what() const { return what_str.c_str(); }
};

#endif
