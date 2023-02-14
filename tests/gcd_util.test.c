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
}




CuSuite * getGcdUtilTestSuite() {
    CuSuite *suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, testEuclideanMethod);
    return suite; 
}


#endif




