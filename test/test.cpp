#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cmath>
#include "../complex_number.hpp"

#define BOOST_TEST_MAIN
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

const double    ACCURACY = 1e-7;

BOOST_AUTO_TEST_CASE(addCmplCmpl)
{
    complex_number a (1.23, 4.56);
    complex_number b (7.89, 1.011);

    complex_number c = a + b;
    BOOST_REQUIRE_CLOSE (c.realpart, a.realpart + b.realpart, ACCURACY);
    BOOST_REQUIRE_CLOSE (c.imgpart , a.imgpart  + b.imgpart , ACCURACY);
}

BOOST_AUTO_TEST_CASE(addCmpldouble)
{
    complex_number a (1.23, 4.56);
    double b = 3;

    complex_number c = a + b;
    BOOST_REQUIRE_CLOSE (c.realpart, a.realpart + b, ACCURACY);
    BOOST_REQUIRE_CLOSE (c.imgpart , a.imgpart, ACCURACY);
}

BOOST_AUTO_TEST_CASE(adddoubleCmpl)
{
    complex_number a (1.23, 4.56);
    double b = 3;

    complex_number c = b + a;
    BOOST_REQUIRE_CLOSE (c.realpart, a.realpart + b, ACCURACY);
    BOOST_REQUIRE_CLOSE (c.imgpart , a.imgpart, ACCURACY);
}

//------------------------------------------------------------------------------

BOOST_AUTO_TEST_CASE(subCmplCmpl)
{
    complex_number a (1.23, 4.56);
    complex_number b (7.89, 1.011);

    complex_number c = a - b;
    BOOST_REQUIRE_CLOSE (c.realpart, a.realpart - b.realpart, ACCURACY);
    BOOST_REQUIRE_CLOSE (c.imgpart , a.imgpart  - b.imgpart , ACCURACY);
}

BOOST_AUTO_TEST_CASE(subCmpldouble)
{
    complex_number a (1.23, 4.56);
    double b = 3;

    complex_number c = a - b;
    BOOST_REQUIRE_CLOSE (c.realpart, a.realpart - b, ACCURACY);
    BOOST_REQUIRE_CLOSE (c.imgpart , a.imgpart, ACCURACY);
}

BOOST_AUTO_TEST_CASE(subdoubleCmpl)
{
    complex_number a (1.23, 4.56);
    double b = 3;

    complex_number c = b - a;
    BOOST_REQUIRE_CLOSE (c.realpart, -a.realpart + b, ACCURACY);
    BOOST_REQUIRE_CLOSE (c.imgpart , -a.imgpart, ACCURACY);
}

//--------------------------------------------------------------------

BOOST_AUTO_TEST_CASE(mulCmplCmpl)
{
    complex_number a (1, -1);
    complex_number b (24.2, 0.01);

    complex_number c = a * b;
    BOOST_REQUIRE_CLOSE (c.realpart,  24.21, ACCURACY);
    BOOST_REQUIRE_CLOSE (c.imgpart , -24.19, ACCURACY);
}

BOOST_AUTO_TEST_CASE(mulCmpldouble)
{
    complex_number a (1, -1);
    double b = 3;

    complex_number c = a * b;
    BOOST_REQUIRE_CLOSE (c.realpart,  3, ACCURACY);
    BOOST_REQUIRE_CLOSE (c.imgpart , -3, ACCURACY);
}

BOOST_AUTO_TEST_CASE(muldoubleCmpl)
{
    complex_number a (1, -1);
    double b = 3;

    complex_number c = b * a;
    BOOST_REQUIRE_CLOSE (c.realpart,  3, ACCURACY);
    BOOST_REQUIRE_CLOSE (c.imgpart , -3, ACCURACY);
}

//--------------------------------------------------------------------

BOOST_AUTO_TEST_CASE(divCmplCmpl)
{
    complex_number a (2.37, -1.11);
    complex_number b (3, 4);

    complex_number c = a / b;
    BOOST_REQUIRE_CLOSE (c.realpart,  0.1068, ACCURACY);
    BOOST_REQUIRE_CLOSE (c.imgpart , -0.5124, ACCURACY);
}

BOOST_AUTO_TEST_CASE(divCmpldouble)
{
    complex_number a (1, -1);
    double b = 3;

    complex_number c = a / b;
    BOOST_REQUIRE_CLOSE (c.realpart,  1.0/3, ACCURACY);
    BOOST_REQUIRE_CLOSE (c.imgpart , -1.0/3, ACCURACY);
}

BOOST_AUTO_TEST_CASE(divdoubleCmpl)
{
    complex_number a (1, -1);
    double b = 3;

    complex_number c = b / a;
    BOOST_REQUIRE_CLOSE (c.realpart,  1.5, ACCURACY);
    BOOST_REQUIRE_CLOSE (c.imgpart ,  1.5, ACCURACY);
}

//--------------------------------------------------------------------

BOOST_AUTO_TEST_CASE(addCmplAss)
{
    complex_number a (1.23, 4.56);
    complex_number b (7.89, 1.011);

    a += b;
    BOOST_REQUIRE_CLOSE (a.realpart, 9.12,  ACCURACY);
    BOOST_REQUIRE_CLOSE (a.imgpart , 5.571, ACCURACY);
}

BOOST_AUTO_TEST_CASE(adddoubleAss)
{
    complex_number a (1.23, 4.56);
    double b = 3;

    a += b;
    BOOST_REQUIRE_CLOSE (a.realpart, 4.23,  ACCURACY);
    BOOST_REQUIRE_CLOSE (a.imgpart , 4.56, ACCURACY);
}

//----------------------------------------------------------------------

BOOST_AUTO_TEST_CASE(subCmplAss)
{
    complex_number b (1.23, 4.56);
    complex_number a (7.89, 1.011);

    a -= b;
    BOOST_REQUIRE_CLOSE (a.realpart, 6.66, ACCURACY);
    BOOST_REQUIRE_CLOSE (a.imgpart , -3.549 , ACCURACY);
}

BOOST_AUTO_TEST_CASE(subdoubleAss)
{
    complex_number b (1.23, 4.56);
    double a = 1.1;

    b -= a;
    BOOST_REQUIRE_CLOSE (b.realpart, 0.13, ACCURACY);
    BOOST_REQUIRE_CLOSE (b.imgpart , 4.56 , ACCURACY);
}

//--------------------------------------------------------------------------

BOOST_AUTO_TEST_CASE(mulCmplAss)
{
    complex_number b (1.2, 4.5);
    complex_number a (-7.8, 1.0);

    a *= b;
    BOOST_REQUIRE_CLOSE (a.realpart, -13.86, ACCURACY);
    BOOST_REQUIRE_CLOSE (a.imgpart , -33.9 , ACCURACY);
}

BOOST_AUTO_TEST_CASE(muldoubleAss)
{
    complex_number b (1.2, 4.5);
    double a = 1.1;

    b *= a;
    BOOST_REQUIRE_CLOSE (b.realpart, 1.32, ACCURACY);
    BOOST_REQUIRE_CLOSE (b.imgpart , 4.95 , ACCURACY);
}

//--------------------------------------------------------------------------

BOOST_AUTO_TEST_CASE(divCmplAss)
{
    complex_number b (3, 4);
    complex_number a (-7.8, 1.0);

    a /= b;
    BOOST_REQUIRE_CLOSE (a.realpart, -0.776, ACCURACY);
    BOOST_REQUIRE_CLOSE (a.imgpart ,  1.368, ACCURACY);
}

BOOST_AUTO_TEST_CASE(divdoubleAss)
{
    complex_number b (1.2, 4.5);
    double a = 2;

    b /= 2;
    BOOST_REQUIRE_CLOSE (b.realpart, 0.6, ACCURACY);
    BOOST_REQUIRE_CLOSE (b.imgpart , 2.25 , ACCURACY);
}

//--------------------------------------------------------------------------

BOOST_AUTO_TEST_CASE(ABS)
{
    complex_number a (3, -4);
    BOOST_REQUIRE_CLOSE (a.abs(), 5, ACCURACY);
}

BOOST_AUTO_TEST_CASE(re)
{
    complex_number a (1.2245, 4.56543);
    BOOST_REQUIRE_CLOSE (a.Re(), 1.2245, ACCURACY);
}

BOOST_AUTO_TEST_CASE(im)
{
    complex_number a (1.2245, 4.56543);
    BOOST_REQUIRE_CLOSE (a.Im(), 4.56543, ACCURACY);
}

BOOST_AUTO_TEST_CASE(arg)
{
    complex_number a (1.0/2, sqrt(3)/2);
    BOOST_REQUIRE_CLOSE (a.Arg(), M_PI/3, ACCURACY);
}

BOOST_AUTO_TEST_CASE(power)
{
    complex_number a (sqrt(2)/2.0, -sqrt(2)/2.0);
    complex_number b = a.power(4); 
    BOOST_REQUIRE_CLOSE (b.realpart, -1, ACCURACY);
}

BOOST_AUTO_TEST_CASE(ln)
{
    complex_number a (sqrt(2), sqrt(2));
    complex_number b = a.ln();
    BOOST_REQUIRE_CLOSE (b.realpart, log(2), ACCURACY);
    BOOST_REQUIRE_CLOSE (b.imgpart,  M_PI/4, ACCURACY);
}

