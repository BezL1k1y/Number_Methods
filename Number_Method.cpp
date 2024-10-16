#include <iostream>
#include <fstream>
#include <iomanip>
#include "EQUATION.h"
#include "BISECT.h"
#include "NEWTON.h"
#include "CHORD.h"
#include "NEWTON_CHORD.h"
#include "SITER.h"


using namespace std;


int main()
{
    reset_BISEC();
    reset_NEWTON();
    reset_CHORD();
    reset_NEWTON_CHORD();
    reset_SITER();

    cout << setprecision(20) << setw(20);

    double a = 1;
    double b = 3;
    double eps = 1e-10;
    int counter = 0;

    BISECT(a, b, eps, counter);
    NEW_TON(b,eps);
    CHORD(a, b, eps);
    NEWTON_CHORD(a, b, eps);
    SITER(a,eps);
}
