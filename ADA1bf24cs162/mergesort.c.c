
#include<stdio.h>
#include<time.h>

void merge(int a[],int low,int high,int mid);
void mergeSort(int a[],int low,int high);


void merge(int a[],int low,int high,int mid){
    int i,j,k;
    int n1=mid-low+1;
    int n2=high-mid;

    int L[n1],R[n2];

    for(int i=0;i<n1;i++){
        L[i]=a[low+i];

    }
    for(int j=0;j<n2;j++){
        R[j]=a[mid+1+j];
    }
    i=0;
    j=0;
    k=low;
    while(i<n1 && j<n2){
        if(L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < n1){
        a[k] = L[i];
        i++;
        k++;
    }
    while(j < n2){
        a[k] = R[j];
        j++;
        k++;
    }
}



void mergeSort(int a[],int low,int high){
    int mid;
    if(low<high){
        mid=(low+high)/2;
        mergeSort(a,low,mid);
        mergeSort(a,mid+1,high);
        merge(a,low,high,mid);
    }
}

int main() {
    int n;
    static int arr[100000];
    clock_t start, end;
    double cpu_time;

    printf("Enter size: ");
    scanf("%d", &n);

    if (n > 100000) n = 100000;

    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100000;
    }

    start = clock();
    mergeSort(arr, 0, n - 1);
    end = clock();

    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Sorted (first 10): ");
    for (int i = 0; i < 10 && i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nTime taken = %f seconds\n", cpu_time);

    return 0;
}
