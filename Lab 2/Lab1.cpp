#include<bits/stdc++.h>
#include<math.h>
#include<time.h>
using namespace std;

int main()
{
	srand(time(NULL));
	FILE *outfile1;
    outfile1 = fopen("opt.txt", "w");
    long long int N;
    long long int minSize = pow(2, 10);
	long long int maxSize = pow(2, 11);
	for(N = minSize; N < maxSize; N = N*2)
    {
		double mat[N][N],s[N][N],val;
	
	    int i,j,v[N];
	    clock_t start_time,end_time;
	    cout<<"in"<<endl;
	    for(i=0;i<N;i++)
	    {
	        for(j=0;j<N;j++)
	        {
	            s[i][j]=rand();
	        }
	    }
	    start_time = clock();
	    for(i=0;i<N;i++)
	    {
	        double val=v[i]%256;
	        //v[i]=(cos(val)*cos(val) - sin(val)*sin(val));
	        v[i]=(-cos(2*val));
	    }
	    for(j=0;j<N;j++)
	    {
	        //val = (double)(v[i] % 256);
	        for(i=0;i<N;i++)
	        {
	            if(true)
	            {
	                mat[j][i] = s[j][i]*v[i];
	            }
	        }
	    }
	    end_time=clock()-start_time;
	    double wall_clock=(double)end_time/(double)(CLOCKS_PER_SEC);
	    fprintf(outfile1, "%.3f,", wall_clock);
	    cout<<wall_clock<<endl;
	}
	fclose(outfile1);
	return 0;
}
