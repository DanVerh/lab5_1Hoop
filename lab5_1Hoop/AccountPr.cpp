//Account.cpp

//invalid_arguments in functions
//Exc in operators
//ExcInh in Init

#include "AccountPr.hpp"
#include "Money.hpp"
#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
#include "Exc.hpp"
#include "ExcInh.hpp"

using namespace std;

void AccountPr::Init(string name1, int num1, double perc1, int newam500, int newam200, int newam100, int newam50, int newam20, int newam10, int newam5, int newam2, int newam1, int newam050, int newam025, int newam010, int newam005, int newam002, int newam001) {
    if (newam500 < 0 || newam200 < 0 || newam100 < 0 || newam50 < 0 || newam20 < 0 || newam10 < 0 || newam5 < 0 || newam2 < 0 || newam1 < 0 || newam050 < 0 || newam025 < 0 || newam010 < 0 || newam005 < 0 || newam002 < 0 || newam001 < 0)
        throw ExcInh();
    name = name1;
    num = num1;
    perc = perc1;
    if (perc1 < 0)
        throw invalid_argument("percent can't be < 0");
    this->Money::Init(newam500,  newam200,  newam100,  newam50,  newam20,  newam10,  newam5,  newam2,  newam1,  newam050,  newam025,  newam010,  newam005,  newam002,  newam001);
}

void AccountPr::Read() {
    cout << "name = "; cin >> name;
    cout << "number = "; cin >> num;
    cout << "percent = "; cin >> perc;
    if (perc < 0)
        throw invalid_argument("percent can't be < 0");
}

void AccountPr::Display() {
    cout << name << endl;
    cout << num << endl;
    cout << perc << endl;
    cout << this->GetSum()<< endl;
    cout << endl;
}

void AccountPr::Withdraw(Money value) {
    *this - value;
}

void AccountPr::TopUp(Money value) {
    *this + value;
}

void AccountPr::Interest() {
    *this *= 0.01 * perc;
}

void AccountPr::Dollar() {
    *this /= 32;
}

void AccountPr::Euro() {
    *this /= 35;
}

string AccountPr::toString() {
    string d;
    stringstream sout;
    sout << this->Sum() << endl;
    d = sout.str();
    d.replace(d.find("."), 1, ",");
    return d;
}

AccountPr& AccountPr::operator ++()
{
    ++perc;
    return *this;
}
AccountPr& AccountPr::operator --()
{
    --perc;
    if (perc < 0)
        throw Exc("percent can't be < 0");
    return *this;
}
AccountPr AccountPr::operator ++(int)
{
    AccountPr tmp = *this;
    this->perc++;
    return tmp;
}
AccountPr AccountPr::operator --(int)
{
    AccountPr tmp = *this;
    this->perc--;
    if (perc < 0)
        throw Exc("percent can't be < 0");
    return tmp;
}

ostream& operator <<(ostream& out, AccountPr a) {
    out << a.name << endl;
    out << a.num << endl;
    out << a.perc << endl;
    return out;
}

istream& operator >>(istream& in, AccountPr& a) {
    cout << " Name: "; in >> a.name;
    cout << " Number: "; in >> a.num;
    cout << " Percent: "; in >> a.perc;
    if (a.perc < 0)
        throw Exc("percent can't be < 0");
    return in;
}
