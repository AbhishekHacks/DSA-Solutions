/*Write a function that calculates the corresponding day of the week for any particular date in the past or future.

For example, for the date 28th August 2020 happens to be Friday. Hence the expected output will be Friday.*/

//Time Complexity -- O(year*month*day)

#include<bits/stdc++.h>
string dayOfTheWeek(int day, int month, int year) 
{
    // Write your code here.

    vector<string>day_of_week={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
    int ptr=0;
    vector<int>totaldays_without_leap={31,28,31,30,31,30,31,31,30,31,30,31};
    vector<int>totaldays_with_leap={31,29,31,30,31,30,31,31,30,31,30,31};
    for(int y=1;y<=year;y++){
        if((y%4==0&&y%100!=0)||y%400==0){
            for(int m=1;m<=12;m++){
                for(int d=1;d<=totaldays_with_leap[m-1];d++){
                    if(y==year&&m==month&&d==day){
                        return day_of_week[ptr%7];
                    }
                    ptr++;
                }
            }
        }
        else{
            for(int m=1;m<=12;m++){
                for(int d=1;d<=totaldays_without_leap[m-1];d++){
                    if(y==year&&m==month&&d==day){
                        return day_of_week[ptr%7];
                    }
                    ptr++;
                }
            }
        }
    }
    return "";
}
