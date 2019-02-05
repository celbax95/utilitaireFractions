#include <iostream>
#include "Fraction.h"

using namespace std;

int main()
{
    Fraction f1(3,2), f2(1,2);

    cout << (f1<=f2) << endl;
    return 0;
}
