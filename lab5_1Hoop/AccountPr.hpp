//AccountPr.hpp

#pragma once
#include <string>
#include "Money.hpp"
using namespace std;

class AccountPr:private Money {
private:
    string name;
    int num;
    double perc;
public:
    void SetName(string value) { name = value; }
    void SetNum(int value) { num = value; }
    void SetPerc(double value) { perc = value; }
    string GetName() { return name; }
    int GetNum() { return num; }
    double GetPerc() { return perc; }
    double GetSum() { return this->Sum(); }
    void Init(string name1, int num1, double perc1, int newam500, int newam200, int newam100, int newam50, int newam20, int newam10, int newam5, int newam2, int newam1, int newam050, int newam025, int newam010, int newam005, int newam002, int newam001);
    void Read();
    void Display();

    void ChangeName(string value) { name = value; }
    void Withdraw(Money value);
    void TopUp(Money value);
    void Interest();
    void Dollar();
    void Euro();

    string toString();

    AccountPr& operator ++();
    AccountPr& operator --();
    AccountPr operator ++(int);
    AccountPr operator --(int);
    
    friend istream& operator >>(istream&, AccountPr&);
    friend ostream& operator <<(ostream&, AccountPr a);
};
