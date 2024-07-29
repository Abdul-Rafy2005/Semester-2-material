#include<iostream>
using namespace std;
class TestScores{
    private:
   int  Test_score1,Test_score2,Test_score3,sum;
    float average;
    public:
    // default constructor 
    TestScores(){
        Test_score1 = 0;
        Test_score2 = 0;
        Test_score3 = 0;
        sum = 0;
        average = 0.0;
    }

    void set_1st(int score){
        Test_score1 = score;
    }
    void set_2nd(int score){
        Test_score2 = score;
    }
    void set_3rd(int score){
        Test_score3 = score;
    }
    float  get_average(){
         sum = Test_score1 + Test_score2 + Test_score3;
         average = sum / 3.0;
         return average;
    }
    
};
int main(){
    int  Test_score1,Test_score2,Test_score3;
   do { 
     cout << "Enter 1st test score : ";
     cin >> Test_score1;
         } while (Test_score1 < 0);
 do {  cout << "Enter 2nd test score : ";
     cin >> Test_score2;
      } while (Test_score2 < 0);
   do { cout << "Enter 3rd test score : ";
     cin >> Test_score3; 
      } while (Test_score3 < 0);
     
    TestScores scores;
    scores.set_1st(Test_score1);
    scores.set_2nd(Test_score2);
    scores.set_3rd(Test_score3);

   cout << "Average score is : "<< scores.get_average();
   return 0;
}