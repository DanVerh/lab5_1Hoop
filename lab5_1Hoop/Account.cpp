//Account.cpp


//invalid_arguments in functions
//Exc in operators

#include "Account.hpp"
#include "Money.hpp"
#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
#include "Exc.hpp"
#include "ExcInh.hpp"

using namespace std;

void Account::Init(string name1, int num1, double perc1) {
    if (perc1 < 0)
        throw invalid_argument("percent can't be < 0");
    name = name1;
    num = num1;
    perc = perc1;
}

void Account::Read() {
    cout << "name = "; cin >> name;
    cout << "number = "; cin >> num;
    cout << "percent = "; cin >> perc;
    if (perc < 0)
        throw invalid_argument("percent can't be < 0");
}

void Account::Display() {
    cout << name << endl;
    cout << num << endl;
    cout << perc << endl;
    cout << this->GetSum()<< endl;
    cout << endl;
}

void Account::Withdraw(Money value) {
    *this - value;
}

void Account::TopUp(Money value) {
    *this + value;
}

void Account::Interest() {
    *this *= 0.01 * perc;
}

void Account::Dollar() {
    *this /= 32;
}

void Account::Euro() {
    *this /= 35;
}

string Account::toString() {
    string d;
    stringstream sout;
    sout << this->Sum() << endl;
    d = sout.str();
    d.replace(d.find("."), 1, ",");
    return d;
}

Account& Account::operator ++()
{
    ++perc;
    return *this;
}
Account& Account::operator --()
{
    --perc;
    if (perc < 0)
        throw Exc("percent can't be < 0");
    return *this;
}
Account Account::operator ++(int)
{
    Account tmp = *this;
    this->perc++;
    return tmp;
}
Account Account::operator --(int)
{
    Account tmp = *this;
    this->perc--;
    if (perc < 0)
        throw Exc("percent can't be < 0");
    return tmp;
}

ostream& operator <<(ostream& out, Account a) {
    out << a.name << endl;
    out << a.num << endl;
    out << a.perc << endl;
    return out;
}

istream& operator >>(istream& in, Account& a) {
    cout << " Name: "; in >> a.name;
    cout << " Number: "; in >> a.num;
    cout << " Percent: "; in >> a.perc;
    if (a.perc < 0)
        throw Exc("percent can't be < 0");
    return in;
}

