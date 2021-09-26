#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <math.h>
#include <iostream>

class complex_number
{
private:
    
public:
    double real_;
    double img_;

    complex_number (double real);
     //!-------------------------------------------------
     //! @brief Construct a new complex number object 
     //!
     //! @note  there is no default constructor, 
     //! as not defined complex number could cause ub. 
     //!-------------------------------------------------
    complex_number (double real, double img);
     //!-------------------------------------------------
     //! @brief Destroy the complex number object
     //! 
     //!-------------------------------------------------
    ~complex_number();
     //!-------------------------------------------------
     //! @brief Default copy constructor
     //! 
     //! @param another 
     //!-------------------------------------------------
    complex_number (const complex_number&);
     //!-------------------------------------------------
     //! @brief Default assign operator
     //! 
     //!-------------------------------------------------
    complex_number& operator= (const complex_number& another);  

     //!-------------------------------------------------
     //! @brief standart binar operators
     //! 
     //! @param another 
     //! @return complex_number 
     //!-------------------------------------------------
    complex_number operator+ (const complex_number& another) const;
    complex_number operator- (const complex_number& another) const;
    complex_number operator* (const complex_number& another) const;
    complex_number operator/ (const complex_number& another) const;

    complex_number& operator+= (const complex_number& another);
    complex_number& operator-= (const complex_number& another);
    complex_number& operator*= (const complex_number& another);
    complex_number& operator/= (const complex_number& another);

    bool operator<  (const complex_number&) = delete;
    bool operator>  (const complex_number&) = delete;
    bool operator<= (const complex_number&) = delete;
    bool operator>= (const complex_number&) = delete;

     //!-------------------------------------------------
     //! @brief an abs of complex number
     //! 
     //! @return double - abs
     //!-------------------------------------------------
    double abs() const;
     //!-------------------------------------------------
     //! @brief a real part of complex number
     //! 
     //! @return double - real part of complex number 
     //!-------------------------------------------------
    double Re()  const;
     //!-------------------------------------------------
     //! @brief a imaginary part of complex number
     //! 
     //! @return double - imaginary part of complex number
     //!-------------------------------------------------
    double Im()  const;
     //!-------------------------------------------------
     //! @brief an argument
     //! 
     //! @return double 
     //!-------------------------------------------------
    double Arg() const;

    complex_number power (double power) const;
    complex_number ln () const;

    void print() const;

     //!-------------------------------------------------
     //! @brief operator that helps to work with standart output
     //! 
     //! @param out - stream
     //! @param num - complex number
     //! @return std::ostream& 
     //!-------------------------------------------------
    friend std::ostream& operator<< (std::ostream& out, const complex_number& num);
};

bool operator<  (const double&, const complex_number&) = delete;
bool operator>  (const double&, const complex_number&) = delete;
bool operator<= (const double&, const complex_number&) = delete;
bool operator>= (const double&, const complex_number&) = delete;

bool operator<  (const complex_number&, const double&) = delete;
bool operator>  (const complex_number&, const double&) = delete;
bool operator<= (const complex_number&, const double&) = delete;
bool operator>= (const complex_number&, const double&) = delete;



