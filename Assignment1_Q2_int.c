#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int n; 
    scanf("%d", &n); 
    unsigned long long int mat1[n][n]; 
    unsigned long long int mat2[n][n]; 
    unsigned long long int ans[n][n];
    for (int i=0; i<n; i++){
        for (int j= 0; j<n; j++){
            mat1[i][j] = rand();  
        }
    }      
     for (int i=0; i<n; i++){
        for (int j= 0; j<n; j++){
            mat2[i][j] = rand();  
        }
    }   
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <n; j++) {
         ans[i][j] = 0;
      }
   }
   
    struct timespec ts;
    char buff[100];
    
    timespec_get(&ts, TIME_UTC);
    unsigned long long  int start = ts.tv_nsec;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            for (int k=0; k<n; k++){
                ans[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    timespec_get(&ts, TIME_UTC);
    unsigned long long int end = ts.tv_nsec;
    strftime(buff, sizeof buff, "%D %T", gmtime(&ts.tv_sec));
    
    for (int i=0 ;i<n; i++){
        for (int j=0; j<n; j++){
            if (j != n-1){
                printf("%llu ", ans[i][j]);
            }  
            else{
                printf("%llu\n", ans[i][j]);
            }
        }
    }

    printf("Time- %llu nsec\n", end - start);
    return 0; 
}
