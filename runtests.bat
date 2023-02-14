gcc -Isrc -Itests/lib -Itests src/gcd_run.c src/gcd_util.c tests/lib/CuTest.c tests/lib/std_swapper.c tests/main.test.c tests/gcd_util.test.c -otests -ansi
tests