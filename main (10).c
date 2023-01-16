
START
Procedure Hanoi(disk, source, dest, aux)

   IF disk == 1, THEN
      move disk from source to dest             
   ELSE
      Hanoi(disk - 1, source, aux, dest)     // Step 1
      move disk from source to dest          // Step 2
      Hanoi(disk - 1, aux, dest, source)     // Step 3
   END IF
   
END Procedure
STOP



#include<stdio.h>
#include <time.h>

void towerofhanoi(int n,char a,char b,char c)
{
    if(n>0)
    {
        towerofhanoi(n-1,a,c,b);
        printf("%c-->",a);
        printf("%c\n",c);
        towerofhanoi(n-1,b,a,c);
    }
}

int main()
{
    int n;
    clock_t start_t,end_t;
    double clock_time_used;
    printf("Enter the number of disks:\n");
    scanf("%d",&n);
    start_t=clock();
    towerofhanoi(n,'a','b','c');
    end_t=clock();
    clock_time_used=(double)(end_t - start_t)/CLOCKS_PER_SEC;
    printf("Execution time is %f\n",clock_time_used);
    
    
}


