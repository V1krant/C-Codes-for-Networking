#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    long f1 = 0, f2 = 1 , sum = 0, prev, curr, answers[90] = {0}, temp;
    int n = -1;
    scanf("%d",&n);

    if (answers[n-1] != 0) {
        printf("%ld\n",answers[n-1]);
        return 0;
    }

    prev = f2;
    curr = f1;
    for(int i = 0; i < n ; i++){
        sum += curr;
        printf("%ld %ld --  ",prev,curr);
        temp = curr;
        curr = prev + temp;
        prev = temp;
        printf("%ld %ld\n",prev,curr);
    }
    answers[n-1] = sum;
    printf("%ld\n",sum);
    return 0;
}
