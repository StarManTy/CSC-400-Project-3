#include "gcd_util.h"
#include <stdio.h>


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

void FillArrayIncremented(int * array, int l_array, int start_val, int increment) {
    int i = 0;
    int current = start_val;
    while(i < l_array) {
        array[i] = current;
        i += 1;
        current += increment;
    }
}


void CalculateSetAndPrint(int * array1, int i_array1, int l_array1, int* array2, int l_array2, int print_threshhold, int thread_number) {

    int end_index = i_array1 + l_array1;
    int val1, val2, result;
    while(i_array1 < end_index) {
        val1 = array1[i_array1];
        i_array1 += 1;
        int j = 0;
        while(j < l_array2) {
            val2 = array2[j];
            result = CalculateGcd_Euclidean(val1, val2);
            if(result >= print_threshhold) {
                printf("\nThread %d: gcd(%d, %d) = %d", thread_number, val1, val2, result);
            }
            j += 1;
        }

    }
}