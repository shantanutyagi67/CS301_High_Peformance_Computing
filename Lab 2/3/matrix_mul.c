
#include <stdio.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>

int main()
{
    //int N=300;
    
    //
    // ... v[] and s[][] --assumed to contain valid data
    //
    double start_time,end_time;
    int t;
    for(t=128;t<4096;t*=2){  
        int r=t,c=t,N=t;
        double **mat ,**a,**b,*ptr,*ptr2,*ptr3;
        
        int count = 0,i,j,k,len=0; 
        
      
        len = sizeof(double *) * r + sizeof(double) * c * r; 
        mat = (double **)malloc(len); 
        a = (double **)malloc(len); 
        b = (double **)malloc(len); 
        ptr = (double *)(mat + r); 
        ptr2 = (double *)(a + r); 
        ptr3 = (double *)(b + r); 
        for(i = 0; i < r; i++) {
            mat[i] = (ptr + c * i);
            a[i] = (ptr2 + c * i);
            b[i] = (ptr3 + c * i);
        }
            
            
    
        start_time=clock();
        for(k=0;k<N;k++){
            for(j=0; j<N; ++j) {
                count=0.0;
                for(i=0; i<N ; ++i) {
                    count+=a[i][k]*b[k][j];
                }
                mat[k][j]=count;
            }
        }
        end_time=(clock()-start_time)/CLOCKS_PER_SEC;
        printf("%lf,",(end_time));
        free(mat);
        free(a);
        free(b);
    }

    return 0;
}
