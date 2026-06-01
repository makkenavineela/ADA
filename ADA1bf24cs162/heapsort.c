#include<stdio.h>
#include<time.h>

void swap(int *a ,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void heapify(int arr[],int n,int i){
    int larg=i;
    int left=2*i+1;
    int right=2*i+2;

    if(left<n && arr[left]>arr[larg]){
        larg=left;
    }
    if(right<n && arr[right]>arr[larg]){
        larg=right;
    }
    if(larg!=i){
        swap(&arr[larg],&arr[i]);
        heapify(arr,n,larg);
    }
}
void heapsort(int arr[],int n){
    int i;
    for(i=n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }
    for(int i=n-1;i>0;i--){
        swap(&arr[0],&arr[i]);
        heapif(arr,i,0);
    }
}
int main(){
    int arr[1000],n,i;
    clock_t start,end;
    double CPU_time;
    printf("%d",&n);
    start=clock();
    heapsort(arr,n);
    end=clock();
    CPU_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("sorted ele are:");
    for(i=0;i<n;i++){
        printf("%d",arr[i]);
    }
    printf("time taken=%f seconds, CPU_time");
    return 0;

}
