#ifndef gcd_util_h
#define gcd_util_h


/*!
    \file gcd_util.h

    \brief Declarations for calculation functions related to gcd program.
*/

/*!
    Calculate the GCD of a single pair using the Euclidean method. 

    \param n1 A number, nonzero.
    \param n2 A number, nonzero.
    \returns The Greatest Common Denominator of the two numbers.
*/
int CalculateGcd_Euclidean(int n1, int n2);


/*!
    Fills an array with a set of values starting at start_val and incrementing by increment.

    \param array A pointer to the array to fill.
    \param l_array The length of the array.
    \param start_val The starting value.
    \param increment The quantity to increment the value by at each index.

*/
void FillArrayIncremented(int * array, int l_array, int start_val, int increment) ;


/*!
    Calculates a set of GCDs of a given array and prints each time it finds a GCD greater than the threshold value. 

    It prints in the following format:

    'Thread <thread_no> : gcd(<n1>, <n2>) = <result>'

    It will check every combination of array1 and array2.

    \param array1 An array of numbers for one input into the GCD.
    \param i_array1 The index to start reading in array 1
    \param l_array1 The number of items to read in array1.
    \param array2 An array of the second numbers that will be input into the gcd. 
    \param l_array2 The length of array2.
    \param print_threshhold The threshhold that will cause a call to printf.
    \param thread_number The thread number to print.


*/
void CalculateSetAndPrint(int * array1, int i_array1, int l_array1, int* array2, int l_array2, int print_threshhold, int thread_number);

#endif