#include "complex_number.hpp"
complex_number::complex_number (double real) :
    real_(real),
    img_(0)
{}

complex_number::complex_number (double real, double img) :
    real_(real),
    img_(img)
{}

complex_number::~complex_number()
{}

complex_number complex_number::operator+ (const complex_number& another) const
{
    return {real_ + another.real_, img_ + another.img_};
}

complex_number complex_number::operator- (const complex_number& another) const
{
    return {real_ - another.real_, img_ - another.img_};
}

complex_number complex_number::operator* (const complex_number& another) const
{
    return {real_ * another.real_ - img_ * another.img_, img_ * another.real_ + another.img_ * real_};
}

complex_number complex_number::operator/ (const complex_number& another) const
{
    double sqrAbs2 = another.real_ * another.real_ + another.img_ * another.img_;
    return {(real_ * another.real_ + img_ * another.img_)/sqrAbs2, (img_ * another.real_ - another.img_ * real_)/sqrAbs2};
}

complex_number& complex_number::operator+= (const complex_number& another)
{
    real_ = real_ + another.real_;
    img_  = img_  + another.img_;
    return *this;
}

complex_number& complex_number::operator-= (const complex_number& another)
{
    real_ = real_ - another.real_;
    img_  = img_  - another.img_;
    return *this;
}
complex_number& complex_number::operator*= (const complex_number& another)
{
    real_ = real_ * another.real_ - img_ * another.img_;
    img_  = img_ * another.real_ + another.img_ * real_;
    return *this;
}

complex_number& complex_number::operator/= (const complex_number& another)
{
    double sqrAbs2 = another.real_ * another.real_ + another.img_ * another.img_;
    real_ = (real_ * another.real_ + img_ * another.img_)/sqrAbs2;
    img_  = (img_ * another.real_ - another.img_ * real_)/sqrAbs2;
    return *this;
}

complex_number::complex_number(const complex_number& another) :
    real_(another.real_),
    img_(another.img_)
{}

complex_number& complex_number::operator= (const complex_number& another)
{
    real_ = another.real_;
    img_  = another.img_;
    return *this;
}

double complex_number :: abs() const
{
    return sqrt(real_ * real_ + img_ * img_);
}

double complex_number :: Re()  const
{
    return real_;
}

double complex_number :: Im()  const
{
    return img_;
}

complex_number complex_number :: power (double power) const
{
    double angle = Arg();

    double abs = this->abs();
    abs = pow (abs, power);

    angle *= power;

    return {abs * cos (angle), abs * sin (angle)};
}

double complex_number :: Arg() const
{
    double abs = this->abs();
    
    double sinAngle = asin (img_/abs);
    double cosAngle = acos (real_/abs);
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

void complex_number :: print () const
{
    if (img_ >= 0)
        printf ("%lg+%lgi", real_, img_);
    else
        printf ("%lg%lgi", real_, img_);

}

std::ostream& operator<< (std::ostream& out, const complex_number& num)
{
    if (num.img_ >= 0)
        out << num.real_ << "+" << num.img_ << 'i';
    else
        out << num.real_ << num.img_ << 'i';
} 
