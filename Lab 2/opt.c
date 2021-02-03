#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<stdio.h>

int main()
{
    long long int minSize = pow(2, 8);
    long long int maxSize = pow(2, 29);
    long long int total = maxSize;

    FILE *outfile1;
    outfile1 = fopen("opt.txt", "w");

    int power = 8;
    long long int size;
    for(size = minSize; size < maxSize; size = size*2)
    {
        printf("\n--------------------------------------------------\n");

        long long int RUNS = total/size;

        // allocate required memory to the arrays
        int *v = (int*)malloc(size * sizeof(int));
        double val = 1.11;


        // initialize B C D arrays with random values
        long long int i;
        long long int j;
        double** mat;
        double** s;
        mat =(double **)malloc(size*sizeof(double *));
    	mat[0] = (double *)malloc(size*size*sizeof(double));
    	s =(double **)malloc(size*sizeof(double *));
    	s[0] = (double *)malloc(size*size*sizeof(double));
		for(i=0; i<size; i++)
   		{
        	s[i] = s[0]+i*size;
    	}
    	
    	
        for(i = 0; i < size; i++)
        {
            v[i] = 100+rand()/100;
        }

        clock_t start_time = clock();
        for(i=0; i<size ; ++i) {
			for(j=0; j<size; ++j) {
				val = (double)(v[i] % 256);
				mat[j][i] = s[j][i]*(sin(val)*sin(val)-cos(val)*cos(val));
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
		
        power += 1;

        free(mat);
        free(s);
        free(v);

        printf("\n--------------------------------------------------\n\n");
    }
    fclose(outfile1);
    printf("\n\n----------------------------Vijayee Bhavah----------------------------\n\n");

    return 0;
}
