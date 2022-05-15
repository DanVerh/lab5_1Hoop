//Money.cpp


//invalid_argument in Init, constructors, operator =
//Exc in operator >>
//ExcInh in operator -

#include <iostream>
#include <string>
#include <sstream>
#include "Money.hpp"
#include "Exc.hpp"
#include "ExcInh.hpp"


using namespace std;


bool Money::Init(int newam500, int newam200, int newam100, int newam50, int newam20, int newam10, int newam5, int newam2, int newam1, int newam050, int newam025, int newam010, int newam005, int newam002, int newam001) {
    if (newam500 < 0 || newam200 < 0 || newam100 < 0 || newam50 < 0 || newam20 < 0 || newam10 < 0 || newam5 < 0 || newam2 < 0 || newam1 < 0 || newam050 < 0 || newam025 < 0 || newam010 < 0 || newam005 < 0 || newam002 < 0 || newam001 < 0){
        throw invalid_argument("bill can't be < 0");
        return false;
        
    }

    am500 = newam500;
    am200 = newam200;
    am100 = newam100;
    am50 = newam50;
    am20 = newam20;
    am10 = newam10;
    am5 = newam5;
    am2 = newam2;
    am1 = newam1;
    am050 = newam050;
    am025 = newam025;
    am010 = newam010;
    am005 = newam005;
    am002 = newam002;
    am001 = newam001;
    return true;
}

double Money::Sum() {
    return 500 * am500 + 200 * am200 + 100 * am100 + 50 * am50 + 20 * am20 + 10 * am10 + 5 * am5 + 2 * am2 + am1 + 0.5 * am050 + 0.25 * am025 + 0.1 * am010 + 0.05 * am005 + 0.02 * am002 + 0.01 * am001;
}

Money Money::doubleMoney(double value)
{
    Money a;

    a.SetAm500((int)value / 500);
    value -= (int)value / 500 > 0 ? 500 * (int)(value / 500) : 0;

    a.SetAm200((int)value / 200);
    value -= (int)value / 200 > 0 ? 200 * (int)(value / 200) : 0;

    a.SetAm100((int)value / 100);
    value -= (int)value / 100 > 0 ? 100 * (int)(value / 100) : 0;

    a.SetAm50((int)value / 50);
    value -= (int)value / 50 > 0 ? 50 * (int)(value / 50) : 0;

    a.SetAm20((int)value / 20);
    value -= (int)value / 20 > 0 ? 20 * (int)(value / 20) : 0;

    a.SetAm10((int)value / 10);
    value -= (int)value / 10 > 0 ? 10 * (int)(value / 10) : 0;

    a.SetAm5((int)value / 5);
    value -= (int)value / 5 > 0 ? 5 * (int)(value / 5) : 0;

    a.SetAm2((int)value / 2);
    value -= (int)value / 2 > 0 ? 2 * (int)(value / 2) : 0;

    a.SetAm1((int)value / 1);
    value -= (int)value / 1 > 0 ? 1 * (int)(value / 1) : 0;

    value *= 100;

    a.SetAm050((int)value / 50);
    value -= (int)value / 50 > 0 ? 50 * (int)(value / 50) : 0;

    a.SetAm025((int)value / 25);
    value -= (int)value / 25 > 0 ? 25 * (int)(value / 25) : 0;

    a.SetAm010((int)value / 10);
    value -= (int)value / 10 > 0 ? 10 * (int)(value / 10) : 0;

    a.SetAm005((int)value / 5);
    value -= (int)value / 5 > 0 ? 5 * (int)(value / 5) : 0;

    a.SetAm002((int)value / 2);
    value -= (int)value / 2 > 0 ? 2 * (int)(value / 2) : 0;

    a.SetAm001((int)value / 1);
    value -= (int)value / 1 > 0 ? 1 * (int)(value / 1) : 0;

    return a;
}


Money::Money() {}
Money::Money(int newam500, int newam200, int newam100, int newam50, int newam20, int newam10, int newam5, int newam2, int newam1, int newam050, int newam025, int newam010, int newam005, int newam002, int newam001){
    if (newam500 < 0 || newam200 < 0 || newam100 < 0 || newam50 < 0 || newam20 < 0 || newam10 < 0 || newam5 < 0 || newam2 < 0 || newam1 < 0 || newam050 < 0 || newam025 < 0 || newam010 < 0 || newam005 < 0 || newam002 < 0 || newam001 < 0)
        throw invalid_argument("bill can't be < 0");
    
    am500 = newam500;
    am200 = newam200;
    am100 = newam100;
    am50 = newam50;
    am20 = newam20;
    am10 = newam10;
    am5 = newam5;
    am2 = newam2;
    am1 = newam1;
    am050 = newam050;
    am025 = newam025;
    am010 = newam010;
    am005 = newam005;
    am002 = newam002;
    am001 = newam001;
}
Money::Money(const Money& a) {
    *this = a;
}

Money& Money::operator =(const Money& a) {
    if (a.am500 < 0 || a.am200 < 0 || a.am100 < 0 || a.am50 < 0 || a.am20 < 0 || a.am10 < 0 || a.am5 < 0 || a.am2 < 0 || a.am1 < 0 || a.am050 < 0 || a.am025 < 0 || a.am010 < 0 || a.am005 < 0 || a.am002 < 0 || a.am001 < 0)
        throw invalid_argument("bill can't be < 0");
    am500 = a.am500;
    am200 = a.am200;
    am100 = a.am100;
    am50 = a.am50;
    am20 = a.am20;
    am10 = a.am10;
    am5 = a.am5;
    am2 = a.am2;
    am1 = a.am1;
    am050 = a.am050;
    am025 = a.am025;
    am010 = a.am010;
    am005 = a.am005;
    am002 = a.am002;
    am001 = a.am001;
    return *this;
}

istream& operator >>(istream& in, Money& a) {
    cout << " am500: "; in >> a.am500;
    cout << " am200: "; in >> a.am200;
    cout << " am100: "; in >> a.am100;
    cout << " am50: "; in >> a.am50;
    cout << " am20: "; in >> a.am20;
    cout << " am10: "; in >> a.am10;
    cout << " am5: "; in >> a.am5;
    cout << " am2: "; in >> a.am2;
    cout << " am1: "; in >> a.am1;
    cout << " am050: "; in >> a.am050;
    cout << " am025: "; in >> a.am025;
    cout << " am010: "; in >> a.am010;
    cout << " am005: "; in >> a.am005;
    cout << " am002: "; in >> a.am002;
    cout << " am001: "; in >> a.am001;
    if (a.am500 < 0 || a.am200 < 0 || a.am100 < 0 || a.am50 < 0 || a.am20 < 0 || a.am10 < 0 || a.am5 < 0 || a.am2 < 0 || a.am1 < 0 || a.am050 < 0 || a.am025 < 0 || a.am010 < 0 || a.am005 < 0 || a.am002 < 0 || a.am001 < 0)
        throw Exc("bill can't be < 0");
    return in;
}

ostream& operator <<(ostream& out, Money a) {
    out << double(a.Sum()) << endl;
    return out;
}

Money::operator string() const {
    Money a = *this;
    stringstream ss;
    ss << a.Sum();
    return ss.str();
}

Money Money::operator + (Money a) {
    am500 += a.am500;
    am200 += a.am200;
    am100 += a.am100;
    am50 += a.am50;
    am20 += a.am20;
    am10 += a.am10;
    am5 += a.am5;
    am2 += a.am2;
    am1 += a.am1;
    am050 += a.am050;
    am025 += a.am025;
    am010 += a.am010;
    am005 += a.am005;
    am002 += a.am002;
    am001 += a.am001;
    return *this;
}

Money Money::operator - (Money a) {
    am500 -= a.am500;
    am200 -= a.am200;
    am100 -= a.am100;
    am50 -= a.am50;
    am20 -= a.am20;
    am10 -= a.am10;
    am5 -= a.am5;
    am2 -= a.am2;
    am1 -= a.am1;
    am050 -= a.am050;
    am025 -= a.am025;
    am010 -= a.am010;
    am005 -= a.am005;
    am002 -= a.am002;
    am001 -= a.am001;
    if (am500 < 0 || am200 < 0 || am100 < 0 || am50 < 0 || am20 < 0 || am10 < 0 || am5 < 0 || am2 < 0 || am1 < 0 || am050 < 0 || am025 < 0 || am010 < 0 || am005 < 0 || am002 < 0 || am001 < 0)
        throw ExcInh();
    return *this;
}

double Money::operator / (Money b) {
    return this->Sum() / b.Sum();
}

Money Money::operator *= (double value) {
    double mult = this->Sum() * value + this->Sum();
    *this = doubleMoney(mult);
    return *this;
}

Money Money::operator /= (double value) {
    double mult = this->Sum() / value;
    *this = doubleMoney(mult);
    return *this;
}

bool Money::operator < (Money b) {
    return this->Sum() < b.Sum();
}

bool Money::operator > (Money b) {
    return this->Sum() > b.Sum();
}

bool Money::operator == (Money b) {
    return this->Sum() == b.Sum();
}

bool Money::operator != (Money b) {
    return this->Sum() != b.Sum();
}
