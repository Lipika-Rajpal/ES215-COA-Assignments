#include <stdio.h>   

void func(int n, int c, int b){
    
    if (n>0){   
        int a; 
        a = c;
        c = c+b;  
        b = a;
        printf("%d ", c);
        func(n-1, c, b);
    }
}

int main(){
    func(100, 0, 1);

    return 0;
}