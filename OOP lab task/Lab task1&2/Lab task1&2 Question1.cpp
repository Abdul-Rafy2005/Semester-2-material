
#include<iostream>
using namespace std;

int main() {

    int second,minutes,hour,days;

       cout << "Enter number of seconds: ";
       cin >> second;

       if (second >= 60 && second < 3600) {
          minutes = second / 60;
          second %= 60;
         cout << minutes << " minutes and " << second << " seconds";
          }

   else if (second >= 3600 && second < 86400) {
     hour = second / 3600;
     second %= 3600;
      minutes = second / 60;
     second %= 60;
     cout << hour << " hours " << minutes << " minutes and " << second << " seconds";
    }

  else if (second >= 86400) {
    days = second / 86400;
     second %= 86400;
      hour = second / 3600;
      second %= 3600;
      minutes = second / 60;
        second %= 60;
     cout << days << " days " << hour << " hours " << minutes << " minutes and " << second << " seconds";
    }

    return 0;
}
