QUICKSORT (array A, start, end)     
{  
 1 if (start < end)     
 2 {  
3 p = partition(A, start, end)  
4 QUICKSORT (A, start, p - 1)    
5 QUICKSORT (A, p + 1, end)    
6 }   
}

PARTITION (array A, start, end)     
{  
 1 pivot ? A[end]     
 2 i ? start-1     
 3 for j ? start to end -1 {  
 4 do if (A[j] < pivot) {    
 5 then i ? i + 1     
 6 swap A[i] with A[j]   
 7  }}   
 8 swap A[i+1] with A[end]     
 9 return i+1  
}

#include<stdio.h>
#include<time.h>

int partition (int a[], int start, int end)
{  
    int pivot = a[end]; 
    int i = (start - 1);  
  
    for (int j = start; j <= end - 1; j++)  
    {  
        
        if (a[j] < pivot)  
        {  
            i++;  
            int t = a[i];  
            a[i] = a[j];  
            a[j] = t;  
        }  
    }  
    int t = a[i+1];  
    a[i+1] = a[end];  
    a[end] = t;
    return (i + 1);  
}  

void quick(int a[], int start, int end) 
{  
    if (start < end)  
    {  
        int p = partition(a, start, end);   
        quick(a, start, p - 1);  
        quick(a, p + 1, end);  
    }  
}  
  
  
void printa(int n,int a[n])
{
    for(int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    clock_t start_t ,end_t;
    double cpu_time_used;
    printf("Enter the number of elements:\n");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Unsorted array\n");
    printa(n,a);
    start_t = clock();
    quick(a,0,n-1);
    end_t = clock();
    cpu_time_used = (double)(end_t - start_t)/CLOCKS_PER_SEC;
    printf("Sorted array:\n");
    printa(n,a);
    printf("Execution time is %f\n",cpu_time_used);
    
}
