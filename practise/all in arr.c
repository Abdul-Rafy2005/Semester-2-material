#include<stdio.h>

int mini(int arr[],int number);
int maxi(int arr[],int number);
float mean(int arr[], int number);
int last_E(int arr[], int number);
int Index_2(int arr[], int number);
void Count(int arr[], int number);
void reverse(int arr[], int number);
int main(){
  int number;
  number = 10;
   int arr[number];
   printf("Enter 10 elements in array\n");
   for (int i = 0;i<number;i++){
       scanf("%d",&arr[i]);
   }
   
    printf("Minimum value in array is : %d\n",mini(arr,number));
      printf("Maximum value in array is : %d\n",maxi(arr,number));
         printf("Average of array is : %f\n",mean(arr,number));
           printf("Value at index 2 is : %d\n",Index_2(arr,number));
            printf("Last element of array is : %d\n",last_E(arr,number));
        
             Count(arr,number);
return 0;
}


int  mini(int arr[],int number){
 int a = arr[0];
    for (int j = 1; j < number;j++){
    
    if ( a > arr[j] ){
       a = arr[j];
    }
    
 }
  
   maxi(arr,number);
   return a;
  }

   int  maxi(int arr[],int number){
    int b = arr[0];
    for (int k = 1; k < number;k++){
    
    if ( b < arr[k] ){
       b = arr[k];
    }
    
 }
        mean(arr,number);
       return b; 
  }

     float mean(int arr[], int number){
    
     int sum = 0; 
    for(int l = 0; l < number; l++){
    
        sum += arr[l]; 
        
    }
        float average;
        average = ((float)sum/number);
        last_E(arr,number);
        return average;
  }

     int last_E(int arr[], int number){
     
     int last_number = arr[number-1];
     Index_2(arr,number);
     return last_number;
 }


  int Index_2(int arr[], int number){
  
     int index_2 = arr[2];
    return index_2;
  }
  void Count(int arr[], int number){
      
       int count  = 0; 
    for(int m = 0; m < number; m++){
       if (arr[m] % 2 == 0){
        count += 1;}
   }
   
    printf("Odd elements count : %d\n",number - count);
    printf("Even elements count : %d\n",count);
     
     reverse(arr,number);
   }
   
   void reverse(int arr[], int number){
     printf("Array in reverse order\n");
   for(int i = number - 1; i >= 0;i--){
        printf("%d ",arr[i]);
   }
   printf("\n");
   }
