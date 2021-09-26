#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "../complex_number.hpp"

#define BOOST_TEST_MAIN
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

const double    ACCURACY = 1e-7;

BOOST_AUTO_TEST_CASE(add)
{
    complex_number a (1.23, 4.56);
    complex_number b (7.89, 1.011);

    complex_number c = a + b;
    BOOST_REQUIRE_CLOSE (c.real_, a.real_ + b.real_, ACCURACY);
    BOOST_REQUIRE_CLOSE (c.img_ , a.img_  + b.img_ , ACCURACY);
}

BOOST_AUTO_TEST_CASE(addAss)
{
    complex_number a (1.23, 4.56);
    complex_number b (7.89, 1.011);

    a += b;
    BOOST_REQUIRE_CLOSE (a.real_, 9.12,  ACCURACY);
    BOOST_REQUIRE_CLOSE (a.img_ , 5.571, ACCURACY);
}

BOOST_AUTO_TEST_CASE(sub)
{
    complex_number a (1.23, 4.56);
    complex_number b (7.89, 1.011);

    complex_number c = a - b;
    BOOST_REQUIRE_CLOSE (c.real_, a.real_ - b.real_, ACCURACY);
    BOOST_REQUIRE_CLOSE (c.img_ , a.img_  - b.img_ , ACCURACY);
}

BOOST_AUTO_TEST_CASE(subAss)
{
    complex_number b (1.23, 4.56);
    complex_number a (7.89, 1.011);

    a -= b;
    BOOST_REQUIRE_CLOSE (a.real_, 6.66, ACCURACY);
    BOOST_REQUIRE_CLOSE (a.img_ , -3.549 , ACCURACY);
}

