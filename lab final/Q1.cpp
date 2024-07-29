#include<iostream>
using namespace std;
class orion_space_Station_23p_0560{
   
      int * wrench;
      int * screwdriver;
      int *Scoldering_Iron;
      int size_wrench;
      int size_screwdriver;
      int size_Scoldering;


      public :
      orion_space_Station_23p_0560() : size_wrench(0) , size_screwdriver(0) , size_Scoldering(0) {
        wrench = new int(++size_wrench) ;
        screwdriver = new int(++size_screwdriver);
        Scoldering_Iron = new int(++size_Scoldering) ;
      }

      ~orion_space_Station_23p_0560(){
               delete []  wrench;
               delete []  screwdriver;
               delete []  Scoldering_Iron;
      }


 
       void adding_wrench(){
        int Temp = new int (++size_wrench);
        for (int i = 0; i < size_wrench  - 1 ; i++){
            temp[i] = wrench[i];
        
        }

        Temp [size_wrench - 1] = 1; // adding new one item
        delete [] wrench;
        wrench = Temp;
       } 


       void adding_screwdriver(){
        int Temp = new int (++size_screwdriver);
        for (int i = 0; i < size_screwdriver  - 1 ; i++){
            temp[i] = screwdriver[i];
        
        }

        Temp [size_screwdriver- 1] = 1; // adding new one item
        delete [] screwdriver;
        screwdriver = Temp;
       }


       void adding_Scoldering_Iron(){
        int Temp = new int (++size_Scoldering);
        for (int i = 0; i < size_Scoldering  - 1 ; i++){
            temp[i] = screwdriver[i];
        
        }

        Temp [size_Scoldering- 1] = 1; // adding new one item
        delete [] Scoldering_Iron;
        Scoldering_Iron = Temp;
       }



       void removing_wrench(){
        int Temp = new int (--size_wrench);
        for (int i = 0; i < size_wrench ; i++){
            temp[i] = wrench[i];
        
        }
        delete [] wrench;
        wrench = Temp;
       } 

       void removing_Scoldering_Iron(){
        int Temp = new int (--size_Scoldering);
        for (int i = 0; i < size_Scoldering  ; i++){
            temp[i] = screwdriver[i];
        
        }
        delete [] Scoldering_Iron;
        Scoldering_Iron = Temp;
       }

       void removing_screwdriver(){
        int Temp = new int (size_screwdriver);
        for (int i = 0; i < size_screwdriver ; i++){
            temp[i] = screwdriver[i];
        
        }


        delete [] screwdriver;
        screwdriver = Temp;
       }



};