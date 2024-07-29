#include<stdio.h>
int main(void){

 int i,j,k,l;
 
 
 printf(" Enter the number of rows\n");
 scanf("%d",&k);
 
 
   for (i = 1; i <= k;i++){
 
   for (j=k;j>=1;j--){
   
   if (i >= j)
     printf("* ");
   else
    printf(" ");
   }
  printf("\n"); 
} 
   
   for (i = k - 1; i >= 1; i--) {
   
    for (j = k; j >= 1; j--) {
   
               if (i >= j)
   
                printf("* ");
   
              else
                 printf(" ");
        }
        printf("\n");
    }

   
return 0;
}
