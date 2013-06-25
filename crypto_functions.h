#include <fstream>

using namespace std;

int poWmod ( char *t, char *k, char *mod, char *res );
int NOD( char * ,char * , char * );
int NOD_rash( char * a, char * b, char * d, char * x, char * y );
int RobinTest(char *n);

// ���������� � ������� �� ������
superlong powm( superlong & sla, superlong & slb, superlong & slm )
{
    string str;
    char *t = new char [N];
    char *k = new char [N];
    char *mod = new char [N];
    char *res = new char [N];

    sla.give( str );
    strcpy( t, str.c_str() );
    slb.give( str );
    strcpy( k, str.c_str() );
    slm.give( str );
    strcpy( mod, str.c_str() );

    int result;
    result = poWmod( t, k, mod, res );

    superlong c;
    c.get( res );

    free(t);
    free(k);
    free(mod);
    free(res);

    return c;
}

// ���������� ����� �������� - �������� �������
superlong nod( superlong & sla, superlong & slb )
{
    string str;
    char *a = new char [N];
    char *b = new char [N];
    char *d = new char [N];

    sla.give( str );
    strcpy( a, str.c_str() );
    slb.give( str );
    strcpy( b, str.c_str() );

    int result;
    result = NOD( a, b, d );

    superlong c;
    c.get( d );

    free(a);
    free(b);
    free(d);

    return c;
}

// ���������� ����� �������� - ���������� �������� �������
superlong evklid_ext( superlong & sla, superlong & slb )
{
    string str;
    char *a = new char [N];
    char *b = new char [N];
    char *d = new char [N];
    char *x = new char [N];
    char *y = new char [N];

    sla.give( str );
    strcpy( a, str.c_str() );
    slb.give( str );
    strcpy( b, str.c_str() );

    int result;
    result = NOD_rash( a, b, d, x, y );

    superlong c;
    c.get( d );

    free(a);
    free(b);
    free(d);
    free(x);
    free(y);

    return c;
}

// ���������� ����� �������� - ���������� �������� �������
superlong evklid_ext_x( superlong & sla, superlong & slb )
{
    string str;
    char *a = new char [N];
    char *b = new char [N];
    char *d = new char [N];
    char *x = new char [N];
    char *y = new char [N];

    sla.give( str );
    strcpy( a, str.c_str() );
    slb.give( str );
    strcpy( b, str.c_str() );

    int result;
    result = NOD_rash( a, b, d, x, y );

    superlong c;
    c.get( y );
    if ( c < 0 ) {
        c = slb - c.abs();
    }

    free(a);
    free(b);
    free(d);
    free(x);
    free(y);

    return c;
}

// ��������� ����� �� ��������
bool isPrimitive( superlong & a ) {

    // ����������
    if ( a == 0 ) return 0;
    if ( a == 1 ) return 0;

    // ������� �������
    string str;
    superlong prime_number;
    ifstream prime_numbers( "prime_numbers.txt" );
    while ( prime_numbers >> str ) {
        prime_number.get( str );
        if ( a == prime_number ) {
            prime_numbers.close();
            return 1;
        }
        if ( a % prime_number == 0 ) {
            prime_numbers.close();
            return 0;
        }
    }
    prime_numbers.close();

//    // ���� ������-�������
//    a.give( str );
//    int test;
//    char *n = new char [N];
//    strcpy( n, str.c_str() );
//    for ( unsigned int i = 0 ; i < 5 ; i++ ) {
//        test = RobinTest( n );
//        if ( !test ) {
//            free( n );
//            return 0;
//        }
//    }
//    free( n );
    return 1;
}

// ������������� �����
superlong generate( superlong & n )
{
    string str;
    n.give( str );
    unsigned int strsize = str.size();
    superlong a;

    str.clear();
    for ( unsigned int i = 0; i < strsize ; i++ ) {
        str += rand() % 10 + '0';
    }
    a.get( str );
    a %= n;

    return a;
}

// ������������� ������� �����
superlong generatep( const char * charstr )
{
    string str = charstr;
    unsigned int strsize = str.size();
    superlong p, n;
    n.get( charstr );

    do
    {
        str.clear();
        for ( unsigned int i = 0; i < strsize ; i++ ) {
            str += rand() % 10 + '0';
        }
        p.get( str );
        p %= n;
    }
    while ( !isPrimitive( p ) );

    return p;
}

// ������������� ������� �����
superlong generatep( superlong & n )
{
    string str;
    n.give( str );
    unsigned int strsize = str.size();
    superlong p;

    do
    {
        str.clear();
        for ( unsigned int i = 0; i < strsize ; i++ ) {
            str += rand() % 10 + '0';
        }
        p.get( str );
        p %= n;
    }
    while ( !isPrimitive( p ) );

    return p;
}
