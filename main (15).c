#include <stdio.h>
#include<time.h>

int max(int a, int b)
{ 
    return (a > b) ? a : b; 
    
}
int knapSack(int W, int wt[], int val[], int n)
{
    
    if (n == 0 || W == 0)
        return 0;
 
    if (wt[n - 1] > W)
        return knapSack(W, wt, val, n - 1);
 

    else
        return max(
            val[n - 1]
                + knapSack(W - wt[n - 1], wt, val, n - 1),
            knapSack(W, wt, val, n - 1));
}

int main()
{
    clock_t end_t,start_t;
    double cpu_time_used;
    int i,n,val[20],wt[20],w;
    printf("Enter number of items:\n");
    scanf("%d",&n);
    printf("Enter value and weight of items:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&val[i],&wt[i]);
    }
    printf("Enter size of Kanpsack :\n");
    scanf("%d",&w);
    
    start_t = clock();
    int ans = knapSack(w, wt, val, n);
    end_t = clock();
    
    cpu_time_used=(double)(end_t - start_t)/CLOCKS_PER_SEC;
    
    printf("%d\n", ans);
    printf("Execution time is %f\n",cpu_time_used);
    return 0;
}
