#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<stdio.h>

int main()
{
    long long int minSize = pow(2, 8);
    long long int maxSize = pow(2, 29);
    long long int total = maxSize;

    FILE *outfile1, *outfile2, *outfile3;
    outfile1 = fopen("total.txt", "w");
    outfile2 = fopen("mem.txt", "w");
    outfile3 = fopen("comp.txt", "w");

    int power = 8;
    long long int size;
    for(size = minSize; size < maxSize; size = size*2)
    {
        printf("\n--------------------------------------------------\n");

        long long int RUNS = total/size;

        // allocate required memory to the arrays
        double *A = (double*)malloc(size * sizeof(double));
        double *B = (double*)malloc(size * sizeof(double));
        double *C = (double*)malloc(size * sizeof(double));
        double *D = (double*)malloc(size * sizeof(double));
        double v1,v2,v3,v4;

        /* Check to make sure that we got the allocated memory. */
        if (D == NULL) {
            fprintf(stderr, "Unable to allocate enough memory for array!\n");
            return -1;
        } else {
            double allocated = (double)(size * sizeof(double) * 4)/(1024*1024);
            printf("Memory Allocated: %.3f MB\n", allocated);
        }

        // initialize B C D arrays with random values
        long long int i;
        long long int j;
        for(i = 0; i < size; i++)
        {
            B[i] = 100+rand()/100;
            C[i] = 100+rand()/100;
            D[i] = 100+rand()/100;
        }

        clock_t start_time = clock();
        // running vector triad
        for(i = 0; i < RUNS; i++)
        {
            for(j = 0; j < size; j++)
            {
                A[j] = B[j] + C[j]*D[j];
            }
        }
        // calculate cpu usage time
        clock_t end_time = clock();
        double cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
        // calculate throughput
        double throughput = (sizeof(double)*2*total)/cpu_time_used;
        printf("\npower: %d\tsize: %lld\tthroughput: %.2f\n", power, size, throughput);
        // write throughput to file
        fprintf(outfile1, "%.2f,", throughput);
		
		clock_t start_time2 = clock();
        // running vector triad
        for(i = 0; i < RUNS; i++)
        {
            for(j = 0; j < size; j++)
            {
                v2= B[j];
                v3= C[j];
                v4= D[j];
                
            }
        }
        clock_t end_time2 = clock();
        double mem_time_used = ((double) (end_time2 - start_time2)) / CLOCKS_PER_SEC;
        double mem = (sizeof(double)*4*total)/mem_time_used;
		double comp_time_used = cpu_time_used - mem_time_used;
		double comp = (sizeof(double)*2*total)/mem_time_used;
		fprintf(outfile2, "%.2f,", mem);
		fprintf(outfile3, "%.2f,", comp);
        power += 1;

        free(A);
        free(B);
        free(C);
        free(D);

        printf("\n--------------------------------------------------\n\n");
    }
    fclose(outfile1);
	fclose(outfile2);
	fclose(outfile3);
    printf("\n\n----------------------------Vijayee Bhavah----------------------------\n\n");

    return 0;
}
