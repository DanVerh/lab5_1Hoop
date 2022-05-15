//Source.cpp

#include "AccountPr.hpp"
#include "Account.hpp"
#include "Money.hpp"
#include <iostream>
#include <string>
#include "Exc.hpp"
#include "ExcInh.hpp"

using namespace std;

void _unexpected_to_bad();

int main() {
    set_unexpected(_unexpected_to_bad);
    set_terminate(_unexpected_to_bad);
    
    Account a;
    try {
            a.Init("john", 0101, -1);
        }
        catch (invalid_argument a) {
            cerr << a.what() << endl;
        }
    
    Money b;
        try {
            cin >> b;
            cout << b;
        }
        catch (Exc b){
            cerr << b.what() << endl;
        }
    
    
    AccountPr c;
    try {
            c.Init("jim", 0102, 1.5, 2, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0);
        }
        catch (ExcInh &c){
            cerr << c.what() << endl;
        }
     
    AccountPr d;
        try {
            d.Init("jim", 0102, 1.5, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        }
        catch (ExcInh* d) {
            cerr << d->what() << endl;
        }
    
    
    return 0;
}


void _unexpected_to_bad() {
    cerr << "bad_exception" << endl;
    throw;
}
