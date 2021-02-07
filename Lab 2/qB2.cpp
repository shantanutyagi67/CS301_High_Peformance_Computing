#include<bits/stdc++.h>
#include<math.h>
#include<time.h>
#include<sys/time.h>

using namespace std;

int main()
{
    srand(time(NULL));
	FILE *outfile1;
    outfile1 = fopen("b2.txt", "w");
    int minSize = pow(2,4);
    int maxSize = pow(2,15);
    double val;

    struct timespec start,end;
    for(int size =minSize; size<maxSize; size*=2){
            int i,j;
            int *v;
            double *mat, *s;
            v = (int*)malloc(size * sizeof(int));
            mat = (double*)malloc(size * size * sizeof(double));
            s = (double*)malloc(size * size * sizeof(double));

            for(i=0;i<size;i++)
            {
                v[i] = rand();
                for(j=0;j<size;j++)
                {
                    s[i*size + j]=rand();
                }
            }

            clock_gettime(CLOCK_MONOTONIC, &start);

            for(j=0;j<size;j++)
            {
                for(i=0;i<size;i++)
                {
                    if(true)
                    {
                            double val=v[i]%256;
                            mat[j*size + i] = s[j*size + i]*(-cos(2*val));
                    }
                }
            }
            clock_gettime(CLOCK_MONOTONIC, &end);
            double time;
            time = (end.tv_sec - start.tv_sec) * 1e9;
            time = (time + (end.tv_nsec - start.tv_nsec)) * 1e-9;
            cout<<size<<" "<<time<<endl;
            fprintf(outfile1, "%.5f,", time);

            free(v);
            free(mat);
            free(s);
    }
	fclose(outfile1);
	return 0;
}
