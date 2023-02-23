#include "gcd_run.h"
#include "pthread.h"
#include "gcd_util.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>



BENCH_ThreadCalcGCD ThreadCalcGCD(int n_threads, int* arr1, int l_arrary_1, int * arr2, int l_array_2) {

    printf("\n\n Calculating with %d threads: \n", n_threads);

    BENCH_ThreadCalcGCD return_bench;

    return_bench.from = (double) clock();
    return_bench.thread_count = n_threads;


    /* an array for thread parameters and an array for thread ids */
    THREAD_DATA * datas = malloc(n_threads * sizeof(THREAD_DATA));
    pthread_t * thread_ids = malloc(n_threads * sizeof(pthread_t));

    /* The portion of the array each thread will get. */
    int increment = l_arrary_1/n_threads;

    int i = 0;
    while(i < n_threads) {
        datas[i].array1 = arr1; 
        datas[i].i_array1 = increment * i;
        datas[i].l_array1 = increment;
        datas[i].array2 = arr2 ;
        datas[i].l_array2 = l_array_2;
        datas[i].print_threshhold = 100;
        datas[i].thread_number = i + 1;
        pthread_create(&thread_ids[i], NULL, threadrunner, &datas[i]);
        i+=1;
    }
    i = 0;
    while(i < n_threads) {
        pthread_join(thread_ids[i], NULL);
        i+= 1;
    }

    free(datas);
    free(thread_ids);

    return_bench.to = (double) clock() ;

    return return_bench;
}


void * threadrunner(void * dataParam) {
    THREAD_DATA * data = (THREAD_DATA*) dataParam;
    CalculateSetAndPrint(
        data->array1,
        data->i_array1,
        data->l_array1,
        data->array2,
        data->l_array2,
        data->print_threshhold,
        data->thread_number
    );
}



void printBench(BENCH_ThreadCalcGCD * bench) {
    printf("\n\n%d threads completed in %f\n", bench->thread_count, (bench->to - bench->from)/CLOCKS_PER_SEC);
}