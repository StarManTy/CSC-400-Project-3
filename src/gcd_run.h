#ifndef gcd_run_h
#define gcd_run_h
/*!
    \file gcd_run.h

    \brief Declarations for dirving functions for gcd program. 

    \authors Karl Miller, Ty Kress
*/

/*! Represents benchmark times for a ThreadCalcGCD execution. It also includes the time it took to initialize thread parameters and free any allocated memory. */
typedef struct {
    double time;
    int thread_count;
} BENCH_ThreadCalcGCD;


/*!
    Runs a number of threads to calculate the Greatest Common Denominator of all combinations between array 1 and array 2. 

    Prints all GCDs found over 100, as well as the thread # that found them. 

    Returns a bench mark result describing how long it took for all threads to complete. 

    \param n_threads The number of threads to create. The items in array 1 will be divided into this many evenly sized sections.
    \param arr_1 A pointer to an array
    \param l_array_1 The length of array 1
    \param arr_2 A pointer to the second array to calculate against.
    \param l_array_2 The length of array 2 
    \returns BENCH_ThreadCalcGCD representing the time it took for all threads to complete and join.

*/
BENCH_ThreadCalcGCD ThreadCalcGCD(int n_threads, int* arr1, int l_array_1, int * arr2, int l_array_2);

/*!
    Calls ThreadCalcGCD with the given parameters number_of_times times.

    Figures the average of the results of ThreadCalcGCD and uses that to populate a BENCH object, which it returns.

    \param n_threads The number of threads to create. The items in array 1 will be divided into this many evenly sized sections.
    \param arr_1 A pointer to an array
    \param l_array_1 The length of array 1
    \param arr_2 A pointer to the second array to calculate against.
    \param l_array_2 The length of array 2 
    \param number_of_times The number of times to call ThreadCalcGCD
    \returns BENCH_ThreadCalcGCD representing the average time it took for all threads to complete and join.

*/
BENCH_ThreadCalcGCD ThreadCalcGCDAverage(int n_threads, int* arr1, int l_array_1, int *arr2, int l_array2, int number_of_times);

/*!
    The parameters passed to each thread. They will be the parameters used in a call to CalculateSetAndPrint in gcd_util.

*/
typedef struct {
    /*! The first array */
    int *array1;
    /*! The index to start reading from in the first array*/
    int i_array1;
    /*! The number of items to calculate in the first array */
    int l_array1;
    /*! The second array*/
    int *array2;
    /*! The length of the second array*/
    int l_array2;
    /*! A threshhold over which to print the Greatest Common Denominator*/
    int print_threshhold;
    /*! The thread number which will be printed when a gcd over print_threshhold is found */
    int thread_number;

} THREAD_DATA;

/*!
    The function used to run an individual thread. 

    \param data Actually a pointer to a THREAD_DATA struct. 
*/
void * threadrunner(void * data);



/*!
    Prints a benchmark result average.
    \param bench A pointer to a benchmark result to print
    \param number_of_times The number of times averaged together.
*/
void printBenchAverage(BENCH_ThreadCalcGCD * bench, int number_of_times);

#endif