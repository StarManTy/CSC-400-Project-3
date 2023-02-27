#ifndef gcd_util_test_c
#define gcd_util_test_c


#include "CuTest.h"
#include "gcd_util.h"
#include "tests.h"



void testEuclideanMethod(CuTest *tc) {
    int result = CalculateGcd_Euclidean(2, 1);
    CuAssertIntEquals(tc, 1, result);

    result = CalculateGcd_Euclidean(4, 2);
    CuAssertIntEquals(tc, 2, result);

    result = CalculateGcd_Euclidean(9, 3);
    CuAssertIntEquals(tc, 3, result);

    result = CalculateGcd_Euclidean(18, 24);
    CuAssertIntEquals(tc, 6, result);

    result = CalculateGcd_Euclidean(47655, 123456808);
    CuAssertIntEquals(tc, 353, result);

    result = CalculateGcd_Euclidean(47655, 123456825);
    CuAssertIntEquals(tc, 135, result);

    result = CalculateGcd_Euclidean(235, 123456780);
    CuAssertIntEquals(tc, 235, result);
}


void testFillArray(CuTest *tc) {
    int arr[] = {0,0,0,0,0,0,0};
    FillArrayIncremented(arr,7,1,1 );
    CuAssertIntEquals(tc, arr[0], 1);
    CuAssertIntEquals(tc, arr[6], 7);
}




CuSuite * getGcdUtilTestSuite() {
    CuSuite *suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, testEuclideanMethod);
    SUITE_ADD_TEST(suite, testFillArray);
    return suite; 
}


#endif




