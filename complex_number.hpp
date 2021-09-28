#ifndef ISE_COMPLEX_NUMBER_HPP
#define ISE_COMPLEX_NUMBER_HPP

#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <iostream>

struct complex_number
{
    double realpart;
    double imgpart;

    complex_number ();
    complex_number (double real);
    complex_number (double real, double img);

    ~complex_number();
     
    complex_number (const complex_number& another);
    complex_number& operator= (const complex_number& another);  

    const complex_number operator+ (const complex_number& another) const;
    const complex_number operator- (const complex_number& another) const;
    const complex_number operator* (const complex_number& another) const;
    const complex_number operator/ (const complex_number& another) const;

    const complex_number operator+ (const double& another) const;
    const complex_number operator- (const double& another) const;
    const complex_number operator* (const double& another) const;
    const complex_number operator/ (const double& another) const;

    const complex_number operator+() const;
    const complex_number operator-() const;

    complex_number& operator+= (const complex_number& another);
    complex_number& operator-= (const complex_number& another);
    complex_number& operator*= (const complex_number& another);
    complex_number& operator/= (const complex_number& another);

    complex_number& operator+= (const double& another);
    complex_number& operator-= (const double& another);
    complex_number& operator*= (const double& another);
    complex_number& operator/= (const double& another);

    bool operator<  (const complex_number&) = delete;
    bool operator>  (const complex_number&) = delete;
    bool operator<= (const complex_number&) = delete;
    bool operator>= (const complex_number&) = delete;

    bool operator<  (const double&) = delete;
    bool operator>  (const double&) = delete;
    bool operator<= (const double&) = delete;
    bool operator>= (const double&) = delete;

    double abs() const;
    double Re()  const;
    double Im()  const;
    double Arg() const;
    complex_number power (double power) const;
    complex_number ln () const;

    void print() const;
};

std::ostream& operator<< (std::ostream& out, const complex_number& num);

bool operator<  (const double&, const complex_number&) = delete;
bool operator>  (const double&, const complex_number&) = delete;
bool operator<= (const double&, const complex_number&) = delete;
bool operator>= (const double&, const complex_number&) = delete;

const complex_number operator+ (const double& thisvalue, const complex_number& another);
const complex_number operator- (const double& thisvalue, const complex_number& another);
const complex_number operator* (const double& thisvalue, const complex_number& another);
const complex_number operator/ (const double& thisvalue, const complex_number& another);

#endif





