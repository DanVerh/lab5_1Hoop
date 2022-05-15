//Account.hpp

#pragma once
#include <string>
#include "Money.hpp"
using namespace std;

class Account:public Money {
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
    void Init(string name1, int num1, double perc1);
    void Read();
    void Display();

    void ChangeName(string value) { name = value; }
    void Withdraw(Money value);
    void TopUp(Money value);
    void Interest();
    void Dollar();
    void Euro();

    string toString();

    Account& operator ++();
    Account& operator --();
    Account operator ++(int);
    Account operator --(int);
    
    friend istream& operator >>(istream&, Account&);
    friend ostream& operator <<(ostream&, Account a);
};
