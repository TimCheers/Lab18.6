#include <iostream>
#include "container.h"
using namespace std;
int main()
{
    container A(5);
    cout << A << endl;
    cout << ">>:\n";
    cin >> A;
    cout << "\n------------------------------------------------\n";
    cout << A << endl;
    cout << "\n------------------------------------------------\n";
    cout << *A.first() << endl;
    cout << "\n------------------------------------------------\n";
    for (iter i = A.first(); i != A.last(); ++i)
    {
        cout << *i << "\t";
    }

}