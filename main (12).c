MERGE_SORT(arr, beg, end)  
  
if beg < end  
set mid = (beg + end)/2  
MERGE_SORT(arr, beg, mid)  
MERGE_SORT(arr, mid + 1, end)  
MERGE (arr, beg, mid, end)  
end of if  
  
END MERGE_SORT

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void merge(int a[],int l,int m,int r)
{
    int i,j,k;
    int n1 = m-l+1;
    int n2 = r-m;
    int L[n1];
    int R[n2];
    for(i=0;i<n1;i++)
        L[i] = a[ l+i];
    for(j = 0;j<n2;j++)
        R[j] = a[m+1+j];
    i = 0;
    j = 0;
    k = l;
    while(i<n1 && j<n2)
    {
        if(L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else{
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        a[k] = L[i];
        i++;
        k++;
    }
    while (j<n2)
    {
        a[k]<R[j];
        j++;
        k++;
    }
}

int mergesort(int a[], int l,int r)
{
    if(l<r){
        int m = l+(r-l)/2;
        mergesort(a,l,m);
        mergesort(a,m+1,r);
        merge(a,l,m,r);
    }
}

void printa(int a[],int size)
{
    int i;
    for(i=0;i<size;i++)
        printf("%d\t",a[i]);
    printf("\n");
}

int main()
{
    int n;
    clock_t Start_t,end_t;
    double cpu_time_used;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements:");
    for(int i= 0 ;i<n;i++){
        scanf("%d",&a[i]);
    }
    printa(a,n);
    Start_t = clock();
    mergesort(a,0,n-1);
    end_t = clock();
    cpu_time_used = (double)(end_t - Start_t)/CLOCKS_PER_SEC;
    printf("Sorted array");
    printa(a,n);
    printf("Exeecution time is %f\n",cpu_time_used);
}
