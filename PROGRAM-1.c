PROGRAM-1 

#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
int main ()
{
  int n,m;
  printf("Enter the size of the matrix:");
  scanf("%d",&n);
  printf("Enter thre size of the vector:");
  scanf("%d",&m);
  if(m!=n)
  {
    printf("Multiplication is not possible.\n");
    exit(0);
  }
  int i= 0 , j = 0;
  int **arr=(int**)malloc(n*sizeof(int*));
  int*vec = (int*)malloc(n*sizeof(int));
  int*res = (int*)malloc(n*sizeof(int));
  omp_set_num_threads(n);
#pragma omp parallel private(j)  
{
  #pragma omp for
  for (i=0; i<n; i++)
  {
    srand(i);
    arr[i]=(int*)malloc(n*sizeof(int));
    vec[i]=rand()%100;
    for(j=0;j<n;j++)  
     arr[i][j]=rand()%100; 
   }
} 
#pragma omp parallel private(j)  
{
  #pragma omp for
  for (i=0; i<n; i++)
  {
   res[i]=0;
   for(j=0;j<n;j++)
    res[i]+=arr[i][j]*vec[j];
  }
}
printf("Matrix*Vector = Resultant Mtrix \n");
for(i=0;i<n;i++)
{
  for(j=0;j<n;j++)
   printf("%3d",arr[i][j]);
   if(i ==n/2)
    printf("* %3d =%6d\n", vec[i],res[i]);
   else
    printf("* %3d =%6d\n", vec[i],res[i]);
}
}
