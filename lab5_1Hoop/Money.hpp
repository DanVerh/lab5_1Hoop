//Money.hpp

#pragma once
#include <string>
using namespace std;

class Money {
private:
    int am500, am200, am100, am50, am20, am10, am5, am2, am1, am050, am025, am010, am005, am002, am001;
public:
    void SetAm500(const int am) { am500 = am; };
    void SetAm200(const int am) { am200 = am; };
    void SetAm100(const int am) { am100 = am; };
    void SetAm50(const int am) { am50 = am; };
    void SetAm20(const int am) { am20 = am; };
    void SetAm10(const int am) { am10 = am; };
    void SetAm5(const int am) { am5 = am; };
    void SetAm2(const int am) { am2 = am; };
    void SetAm1(const int am) { am1 = am; };
    void SetAm050(const int am) { am050 = am; };
    void SetAm025(const int am) { am025 = am; };
    void SetAm010(const int am) { am010 = am; };
    void SetAm005(const int am) { am005 = am; };
    void SetAm002(const int am) { am002 = am; };
    void SetAm001(const int am) { am001 = am; };

    int GetAm500() const { return am500; };
    int GetAm200() const { return am200; };
    int GetAm100() const { return am100; };
    int GetAm50() const { return am50; };
    int GetAm20() const { return am20; };
    int GetAm10() const { return am10; };
    int GetAm5() const { return am5; };
    int GetAm2() const { return am2; };
    int GetAm1() const { return am1; };
    int GetAm050() const { return am050; };
    int GetAm025() const { return am025; };
    int GetAm010() const { return am010; };
    int GetAm005() const { return am005; };
    int GetAm002() const { return am002; };
    int GetAm001() const { return am001; };



    bool Init(int newam500, int newam200, int newam100, int newam50, int newam20, int newam10, int newam5, int newam2, int newam1, int newam050, int newam025, int newam010, int newam005, int newam002, int newam001);
    double Sum();
    Money doubleMoney(double value);

    Money();
    Money(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int);
    Money(const Money&);

    Money& operator =(const Money&);
    friend istream& operator >>(istream&, Money&);
    friend ostream& operator <<(ostream&, Money a);
    operator string() const;

    Money operator+ (Money b);
    Money operator- (Money b);
    double operator / (Money b);
    Money operator *= (double value);
    Money operator /= (double value);
    bool operator < (Money b);
    bool operator > (Money b);
    bool operator == (Money b);
    bool operator != (Money b);
};
