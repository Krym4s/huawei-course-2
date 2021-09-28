#include "complex_number.hpp"
#include <cmath>

complex_number :: complex_number () :
    realpart (0),
    imgpart (0)
{}

complex_number :: complex_number (double real) :
    realpart(real),
    imgpart(0)
{}

complex_number :: complex_number (double real, double img) :
    realpart(real),
    imgpart(img)
{}

//----------------------------------------------------------------------------------------------------------

complex_number :: ~complex_number()
{
    realpart = 0;
    imgpart  = 0;
}

//----------------------------------------------------------------------------------------------------------

const complex_number complex_number::operator+ (const complex_number& another) const
{
    return {realpart + another.realpart, imgpart + another.imgpart};
}

const complex_number complex_number::operator- (const complex_number& another) const
{
    return {realpart - another.realpart, imgpart - another.imgpart};
}

const complex_number complex_number::operator* (const complex_number& another) const
{
    return {realpart * another.realpart - imgpart * another.imgpart, imgpart * another.realpart + another.imgpart * realpart};
}

const complex_number complex_number::operator/ (const complex_number& another) const
{
    double sqrAbs2 = another.realpart * another.realpart + another.imgpart * another.imgpart;
    return {(realpart * another.realpart + imgpart * another.imgpart)/sqrAbs2, 
            (imgpart * another.realpart - another.imgpart * realpart)/sqrAbs2};
}

//----------------------------------------------------------------------------------------------------------

const complex_number complex_number :: operator+ (const double& another) const
{
    return {realpart + another, imgpart};
}

const complex_number complex_number :: operator- (const double& another) const
{
    return {realpart - another, imgpart};
}

const complex_number complex_number :: operator* (const double& another) const
{
    return {realpart * another, imgpart * another};
}

const complex_number complex_number :: operator/ (const double& another) const
{
    return {realpart / another, imgpart / another};
}

//----------------------------------------------------------------------------------------------------------

const complex_number operator+ (const double& thisvalue, const complex_number& another) 
{
    return {thisvalue + another.realpart, another.imgpart};
}
const complex_number operator- (const double& thisvalue, const complex_number& another) 
{
    return {thisvalue - another.realpart, - another.imgpart};
}
const complex_number operator* (const double& thisvalue, const complex_number& another) 
{
    return {thisvalue * another.realpart, thisvalue * another.imgpart};
}

const complex_number operator/ (const double& thisvalue, const complex_number& another) 
{
    double sqrAbs2 = another.realpart * another.realpart + another.imgpart * another.imgpart;
    return {(thisvalue * another.realpart)/sqrAbs2, 
            (- another.imgpart * thisvalue)/sqrAbs2};
}

//----------------------------------------------------------------------------------------------------------

const complex_number complex_number :: operator+() const
{
    return {realpart, imgpart};
}

const complex_number complex_number :: operator-() const
{
    return { - realpart, - imgpart};
}


//----------------------------------------------------------------------------------------------------------

complex_number& complex_number::operator+= (const complex_number& another)
{
    realpart = realpart + another.realpart;
    imgpart  = imgpart  + another.imgpart;
    return *this;
}

complex_number& complex_number::operator-= (const complex_number& another)
{
    realpart = realpart - another.realpart;
    imgpart  = imgpart  - another.imgpart;
    return *this;
}
complex_number& complex_number::operator*= (const complex_number& another)
{
    double tempreal = realpart;
    realpart = realpart * another.realpart - imgpart * another.imgpart;
    imgpart  = imgpart * another.realpart + another.imgpart * tempreal;
    return *this;
}

complex_number& complex_number::operator/= (const complex_number& another)
{
    double tempreal = realpart;
    double sqrAbs2 = another.realpart * another.realpart + another.imgpart * another.imgpart;
    realpart = (realpart * another.realpart + imgpart * another.imgpart)/sqrAbs2;
    imgpart  = (imgpart * another.realpart - another.imgpart * tempreal)/sqrAbs2;
    return *this;
}

//----------------------------------------------------------------------------------------------------------

complex_number& complex_number :: operator+= (const double& another) 
{
    realpart += another;
    return *this;
}

complex_number& complex_number :: operator-= (const double& another) 
{
    realpart -= another;
    return *this;
}

complex_number& complex_number :: operator*= (const double& another) 
{
    realpart *= another;
    imgpart  *= another;
    return *this;
}

complex_number& complex_number :: operator/= (const double& another) 
{
    realpart /= another;
    imgpart  /= another;
    return *this;
}

//----------------------------------------------------------------------------------------------------------

complex_number::complex_number(const complex_number& another) :
    realpart(another.realpart),
    imgpart(another.imgpart)
{}

complex_number& complex_number::operator= (const complex_number& another)
{
    realpart = another.realpart;
    imgpart  = another.imgpart;
    return *this;
}

//----------------------------------------------------------------------------------------------------------

double complex_number :: abs() const
{
    return sqrt(realpart * realpart + imgpart * imgpart);
}

double complex_number :: Re()  const
{
    return realpart;
}

double complex_number :: Im()  const
{
    return imgpart;
}

complex_number complex_number :: power (const double power) const
{
    double angle = Arg();

    double absV = this->abs();
    absV = pow (absV, power);

    angle *= power;
 
    return {absV * cos (angle), absV * sin (angle)};
}

double complex_number :: Arg() const
{
    double abs = this->abs();
    
    double sinAngle = asin (imgpart/abs);
    double cosAngle = acos (realpart/abs);
    double angle = 0;

    if (sinAngle >= 0)
        angle = cosAngle;
    else
        angle = -cosAngle;

    return angle;
}

complex_number complex_number :: ln () const
{
    return {log(abs()), Arg()};
}

//----------------------------------------------------------------------------------------------------------

void complex_number :: print () const
{
    if (imgpart >= 0)
        printf ("%lg+%lgi", realpart, imgpart);
    else
        printf ("%lg%lgi", realpart, imgpart);

}

std::ostream& operator<< (std::ostream& out, const complex_number& num)
{
    if (num.imgpart >= 0)
        out << num.realpart << "+" << num.imgpart << 'i';
    else
        out << num.realpart << num.imgpart << 'i';

    return out;
} 

//----------------------------------------------------------------------------------------------------------
