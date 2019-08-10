#include <stdio.h>
#include <math.h>

void merge(int *A, int p,int q,int r){
    // for(int i = 0; i < 5; i++) {
    //     printf("%d ",A[i]);
    // }
    // printf("\n-----\n");
    int L[50],R[50],l_index = 0, r_index = 0;
    for (int i=p; i<=q; i++) L[l_index++] = A[i];
    for (int i=q+1; i<=r; i++) R[r_index++] = A[i];
    // for(int i = 0; i < l_index; i++) {
    //     printf("%d ",L[i]);
    // }
    // printf("\n-----\n");
    // for(int i = 0; i < l_index; i++) {
    //     printf("%d ",R[i]);
    // }
    // printf("\n----------------------->\n");
    L[l_index] = 1000;
    R[r_index] = 1000;
    int l=0, r_p=0;
    for(int i = p; i <= r; i++){
        if(L[l]<=R[r_p]){
            A[i] = L[l];
            l = l + 1;
        }
        else{
            A[i] = R[r_p];
            r_p = r_p + 1;
        }
    }

}

void merge_sort(int *A, int p,int r){
    if(p<r){
        int q = (p+r)/2;
        merge_sort(A,p,q);
        merge_sort(A,q+1,r);
        merge(A,p,q,r);
    }
    else{
        return;
    }
    // printf("%d\n",A[4]);
}



int main(){
    int array[5] = {1,2,100,8,7};
    merge_sort(array,0,4);
    for(int i = 0; i < 5; i++) {
        printf("%d ",array[i]);
    }
    printf("\n");
    return 0;
}