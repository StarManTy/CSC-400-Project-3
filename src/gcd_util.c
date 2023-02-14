#include "gcd_util.h"



int CalculateGcd_Euclidean(int n1, int n2) {
    if(n1 < 0) {
        n1 *= -1;
    }
    if(n2 < 0) {
        n2 *= -1;
    }
    while(n1 != 0 && n2 != 0) {
        if(n1 > n2) {
            n1 = n1 % n2;
        } else if(n2 > n1) {
            n2 = n2 % n1; 
        }
    }

    int return_value = 0;
    if(n1 > n2) {
        return_value = n1;
    } else {
        return_value = n2;
    }
    return return_value;
}