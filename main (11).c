
#include <stdio.h>
#include <time.h>

int bs(int n,int a[n],int s ,int e,int ele)
{
    if(e>=s)
    {
        int mid=(s+e)/2;
        if(a[mid]==ele)
        return mid-1;
        else if(a[mid] > ele)
        bs(n,a,mid,e,ele);
        else
        bs(n,a,s,mid,ele);
    }
    return -1;
}

void sort(int n,int a[n])
{
    for(int i=0;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(a[i] >a[j]){
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int main()
{
    clock_t start_t,end_t;
    double cpu_time_used;
    int n;
    int ele;
    int b;
    printf("enter the number of elements in array:\n");
    scanf("%d",&n);
    int a[n];
    printf("Enter the array:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(n,a);
    int s = 0;
    int e = n-1;
    printf("Enter the element to search:\n");
    scanf("%d",&ele);
    start_t = clock();
    b =bs(n,a,s,e,ele);
    end_t = clock();
    printf("%d\n",b);
    cpu_time_used = (double)(end_t - start_t)/CLOCKS_PER_SEC;
    printf("%f",cpu_time_used);
}

