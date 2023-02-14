#include "CuTest.h"
#include <stdio.h>
#include "tests.h"

/*! Loads and runs test suites using CuTest. */
void RunAllTests(void) {
    CuString *output = CuStringNew();
    CuSuite * suite = CuSuiteNew();
    CuSuiteAddSuite(suite, getGcdUtilTestSuite());
    CuSuiteRun(suite);
    CuSuiteSummary(suite, output);
    CuSuiteDetails(suite, output);
    printf("%s\n", output -> buffer);
}

int main(void) {
    RunAllTests();
}