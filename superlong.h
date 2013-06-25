/**
    superlong.h - ����������, ������� ��������� ��������� ���������� ���� soperlong
    � �������� � ���� ��� � ������ ������� �����������. ������������ �� ������� ��
    ���������    ������������� ����� - ����������� �����. ����� ���� superlong �����
    ��������� � ���� �� SMAX ��������. � ������ ������� ���� ��������� ����� ��������
    ��� ������ � �������������� ������.
    �������������� �������:
        * ���������� a � ������� b. T � M - ������������� ���� (������� superlong)
            pow (T a, M b);
        * ����� - ���������� �������� � ����� a (superlong)
            a.length();
        * ���������� ����� a (superlong) � str (string)
            a.give(str);
        * �������� � a (superlong) ����� �� str (string)
            a.get(str);
**/

#define SMAX 20000

using namespace std;

template < class T > string stringOfInt( T n);
class superlong
{
private:
    long long arrayLength; // ����� �����
    short intArray[SMAX]; // ������, ���������� SUPERLONG
    bool sign; // 1 - ����� �������������, 0 - �������������
public:
    superlong()
    {
        arrayLength = 1;
        for (long long i = 0; i < SMAX + 1; i++) intArray[i] = 0;
        sign = 1;
    }
    superlong(string s)
    {
        arrayLength = 1;
        for (long long i = 0; i < SMAX + 1; i++) intArray[i] = 0;
        sign = 1;
        (*this).get(s);
    }
    superlong(const char* c)
    {
        arrayLength = 1;
        string s;
        for (long long i = 0; i < SMAX + 1; i++) intArray[i] = 0;
        sign = 1;
        while (*c)
        {
            s += *c;
            c++;
        }
        (*this).get(s);
    }
    superlong(long long n)
    {
        arrayLength = 1;
        for (long long i = 0; i < SMAX + 1; i++) intArray[i] = 0;
        sign = 1;
        (*this).get(stringOfInt(n));
    }
    superlong(long n)
    {
        arrayLength = 1;
        for (long long i = 0; i < SMAX + 1; i++) intArray[i] = 0;
        sign = 1;
        (*this).get(stringOfInt(n));
    }
    superlong(int n)
    {
        arrayLength = 1;
        for (long long i = 0; i < SMAX + 1; i++) intArray[i] = 0;
        sign = 1;
        (*this).get(stringOfInt(n));
    }
    superlong(char n)
    {
        arrayLength = 1;
        for (long long i = 0; i < SMAX + 1; i++) intArray[i] = 0;
        sign = 1;
        (*this).get(stringOfInt(n - '0'));
    }
    ~superlong()
    {
        delete []intArray;
    }

    void get();
    void get(string s);
    void getstr(char *s);
    void give();
    void give(string& s);
    void givestr(QString& s);
    long long length();
    superlong abs();
    template < class T > superlong shift( T n);


short& operator [] (long long n);

superlong operator +(superlong op2);
superlong operator -(superlong op2);
superlong operator *(superlong op2);
superlong operator /(superlong op2);

void operator --();
void operator ++();
void operator --(int);
void operator ++(int);

bool operator ==(superlong op2);
bool operator !=(superlong op2);
bool operator >=(superlong op2);
bool operator <=(superlong op2);
bool operator >(superlong op2);
bool operator <(superlong op2);

};


template < class T >
superlong operator +( T n, superlong op2);

template < class T >
superlong operator -( T n, superlong op2);

template < class T >
superlong operator *( T n, superlong op2);

template < class T >
superlong operator /( T n, superlong op2);

template < class T >
superlong operator %(superlong op1, T op2);

template < class T >
void operator +=(superlong& op1, T op2);

template < class T >
void operator -=(superlong& op1, T op2);

template < class T >
void operator *=(superlong& op1, T op2);

template < class T >
void operator /=(superlong& op1, T op2);

template < class T >
void operator %=(superlong& op1, T op2);

template < class T >
bool operator ==( T op1, superlong op2);

template < class T >
bool operator !=( T op1, superlong op2);

template < class T >
bool operator <( T op1, superlong op2);

template < class T >
bool operator >( T op1, superlong op2);

template < class T >
bool operator <=( T op1, superlong op2);

template < class T >
bool operator >=( T op1, superlong op2);

template < class T, class M >
superlong pow( M op1, T op2);


#include <sstream>
#include "functions.h"
#include "template_functions.h"
#include "crypto_functions.h"
