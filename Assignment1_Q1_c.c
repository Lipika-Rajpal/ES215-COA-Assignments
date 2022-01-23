#include <stdio.h>   
int memo[1000];   //I have chosen the length of the memo to be 1000 as I already know that the input is 100. 

int func(int n){
    if (n<=1){  
        memo[n] = 1;
        return 1;  
    }  
    else {   
        if (memo[n] != 0){
            return memo[n];
        }  
        else{
        memo[n] = func(n-1) + func(n-2);  
        return memo[n];
        }
    }
}

int main(){  
    for (int i=0; i<100; i++){
        printf("%d ", func(i));
    }

    return 0;
}