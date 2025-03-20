#include <stdio.h>
#include <omp.h>
#include <time.h>

int main() {
    int i;
    int sum = 0;


    // Get the start time
    double start_time = time(NULL);
    printf("\n start_time :-%f",start_time);
    // Parallelize the following loop
    #pragma omp parallel for reduction(+:sum)
     for(i = 0; i < 99999999; i++) {
        sum += i;
    }
     for(i = 0; i < 99999999; i++) {
        sum += i;
    }
       for(i = 0; i < 99999999; i++) {
        sum += i;
    }
     for(i = 0; i < 99999999; i++) {
        sum += i;
    }

    // Get the end time
    double end_time = time(NULL);
    printf("\n end_time :-%f",end_time);
    // Print the total sum and execution time
    printf("Total sum: %d\n", sum);
    printf("Execution time: %f seconds\n", end_time - start_time);

    return 0;
}
