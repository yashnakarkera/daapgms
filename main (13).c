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
