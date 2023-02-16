#include "gcd_run.h"
#include "gcd_util.h"

#include <stdio.h>



/*! Program entry point. */
int main(int argc, char * argv[]) {

    int X[] = {374656575, 197565, 37464657, 47655, 2847462, 235, 45763568, 4756, 98476456, 736454, 72648, 99999999, 345465, 13847456, 3746465, 58474785, 3746, 8743646, 777777, 9011003, 765346, 35364, 163545464, 87465357};

    int Y[100];

    FillArrayIncremented(Y, 100, 123456780, 1);
    
    CalculateSetAndPrint(X, 0, 24, Y, 100, 100, 1);
}