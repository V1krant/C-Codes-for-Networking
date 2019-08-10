#include <stdio.h>
#include <math.h>

int merge_inv(int *A, int p,int q,int r){
    int L[50],R[50],l_index = 0, r_index = 0, inv = 0;
    for (int i=p; i<=q; i++) L[l_index++] = A[i];
    for (int i=q+1; i<=r; i++) R[r_index++] = A[i];
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
            inv += q - p + 1 - l ;
            r_p = r_p + 1;
        }
    }
    return inv;

}

int count_inv(int *A, int p,int r){
    int inv = 0;
    if(p<r){
        int q = (p+r)/2;
        inv += count_inv(A,p,q);
        inv += count_inv(A,q+1,r);
        inv += merge_inv(A,p,q,r);
    }
    return inv;
}

int main(){
    int array[5] = {5,4,1,5,6};
    int ans = count_inv(array,0,4);
    printf("%d",ans);
    printf("\n");
    return 0;
}
