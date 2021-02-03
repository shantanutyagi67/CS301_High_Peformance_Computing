#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<stdio.h>

int main()
{
    long long int minSize = pow(2, 8);
    long long int maxSize = pow(2, 29);
    long long int total = maxSize;

    FILE *outfile1, *outfile2;
    outfile1 = fopen("add.txt", "w");
    outfile2 = fopen("div.txt", "w");

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
        double v1=101,v2=102,v3=103,v4=104;

        /* Check to make sure that we got the allocated memory. */

        // initialize B C D arrays with random values
        long long int i;
        long long int j;
        for(i = 0; i < size; i++)
        {
            B[i] = 100+rand()/100;
            C[i] = 100+rand()/100;
        }

        clock_t start_time = clock();
        // running vector triad
        for(i = 0; i < RUNS; i++)
        {
            for(j = 0; j < size; j++)
            {
                A[j] = B[j] + C[j];
                if(1==0);
            }
        }
        // calculate cpu usage time
        clock_t end_time = clock();
        double cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
        // calculate throughput
        double throughput = (sizeof(double)*2*total)/cpu_time_used;
        // write throughput to file
        fprintf(outfile1, "%.3f,", cpu_time_used);
		
		clock_t start_time2 = clock();
        // running vector triad
        for(i = 0; i < RUNS; i++)
        {
            for(j = 0; j < size; j++)
            {
            	A[j] = B[j]/C[j];
            	if(1==2);
                
            }
        }
        clock_t end_time2 = clock();
        double comp_time_used = ((double) (end_time2 - start_time2)) / CLOCKS_PER_SEC;
        double comp = (sizeof(double)*4*total)/comp_time_used;
		fprintf(outfile2, "%.3f,", comp_time_used);
        power += 1;

        free(A);
        free(B);
        free(C);

        printf("\n--------------------------------------------------\n\n");
    }
    fclose(outfile1);
	fclose(outfile2);
    printf("\n\n----------------------------Vijayee Bhavah----------------------------\n\n");

    return 0;
}
