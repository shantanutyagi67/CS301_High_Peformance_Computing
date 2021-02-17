
#include<stdio.h>
#include<math.h>
#include<omp.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>

#define min(x, y) (((x) < (y)) ? (x) : (y))
//  Using the MONOTONIC clock 
#define CLK CLOCK_MONOTONIC

/* Function to compute the difference between two points in time */
struct timespec diff(struct timespec start, struct timespec end);

/* 
   Function to computes the difference between two time instances

   Taken from - http://www.guyrutenberg.com/2007/09/22/profiling-code-using-clock_gettime/ 

   Further reading:
http://stackoverflow.com/questions/6749621/how-to-create-a-high-resolution-timer-in-linux-to-measure-program-performance
http://stackoverflow.com/questions/3523442/difference-between-clock-realtime-and-clock-monotonic
 */
struct timespec diff(struct timespec start, struct timespec end){
	struct timespec temp;
	if((end.tv_nsec-start.tv_nsec)<0){
		temp.tv_sec = end.tv_sec-start.tv_sec-1;
		temp.tv_nsec = 1000000000+end.tv_nsec-start.tv_nsec;
	}
	else{
		temp.tv_sec = end.tv_sec-start.tv_sec;
		temp.tv_nsec = end.tv_nsec-start.tv_nsec;
	}
	return temp;
}


int main(int argc, char* argv[])
{
	struct timespec start_e2e, end_e2e, start_alg, end_alg, e2e, alg;
	/* Should start before anything else */
	clock_gettime(CLK, &start_e2e);

	/* Check if enough command-line arguments are taken in. */
	if(argc < 3){
		printf( "Usage: %s n p \n", argv[0] );
		return -1;
	}

	int N=atoi(argv[1]);	/* size of input array */
	int P=atoi(argv[2]);	/* number of processors*/
	char *problem_name = "Matrix_multiplication";
	char *approach_name = "Normal";
//	char buffer[10];
//	FILE* inputFile;
	FILE* outputFile;
	//	inputFile = fopen(argv[3],"r");

	char outputFileName[50];		
	sprintf(outputFileName,"output/%s_%s_%s_%s_output.txt",problem_name,approach_name,argv[1],argv[2]);	

	//**********************
	srand(NULL);
	int *a[N], *b[N], *c[N];
	int i,j,k,l,m;
	for(i = 0;i < N;i++){
		a[i] = (int *) malloc(sizeof(int)*N);
		b[i] = (int *) malloc(sizeof(int)*N);
		c[i] = (int *) malloc(sizeof(int)*N);
		for(j = 0; j < N; j++){
			a[i][j] = rand();	
			b[i][j] = rand();
			c[i][j] = 0;
		}
	}
	//**********************
	omp_set_num_threads(P);
	clock_gettime(CLK, &start_alg);	/* Start the algo timer */

	/*----------------------Core algorithm starts here----------------------------------------------*/
	int block_size = 8;
	omp_set_num_threads(P);

	//Matrix multiplication
	#pragma omp parallel shared(a,b,c) private(i,j,k,l,m,n)
	{
		#pragma omp for schedule(static)
		for (i = 0; i < N; i += block_size)
		{
			for (j = 0; j < N; j += block_size)
			{
				for (k = 0; k < block_size; k++)
				{
					for (l = 0; l < block_size; l++)
					{
						for (m = 0; m < N; m++)
						{
							c[i + k][j + l] += a[i + k][m] * b[m][j + l];
						}
					}
				}
			}
		}
	}
	/*----------------------Core algorithm finished--------------------------------------------------*/

	clock_gettime(CLK, &end_alg);	/* End the algo timer */
	/* Ensure that only the algorithm is present between these two
	   timers. Further, the whole algorithm should be present. */


	/* Should end before anything else (printing comes later) */
	clock_gettime(CLK, &end_e2e);
	e2e = diff(start_e2e, end_e2e);
	alg = diff(start_alg, end_alg);
	

	/* problem_name,approach_name,n,p,e2e_sec,e2e_nsec,alg_sec,alg_nsec
	   Change problem_name to whatever problem you've been assigned
	   Change approach_name to whatever approach has been assigned
	   p should be 0 for serial codes!! 
	 */
	printf("%s,%s,%d,%d,%d,%ld,%d,%ld\n", problem_name, approach_name, N, P, e2e.tv_sec, e2e.tv_nsec, alg.tv_sec, alg.tv_nsec);

	return 0;

}
