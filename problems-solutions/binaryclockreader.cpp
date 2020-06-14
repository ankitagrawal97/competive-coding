/*convert a binary clock to human readable clock. "111:10:1" 
First part is hour, 
second part is minute, t
hird is am or pm i.e 0 for am ,1 is pm.*/
#include <bits/stdc++.h>

using namespace std;

int todecimal(string str){

    int num = stoi(str); //casting string to int
    int count  = 0;
    int sum = 0;
    int rem;
    while(num!=0){
        rem = num%10;
        num = num/10;
        sum = sum + rem*pow(2,count);
        count++;
    }

    return sum;

}

void converttoreadable(string time){
    int len = time.length();
    string hour_binary; //capture hour from string
    string minute_binary; //capture minute from string
    
    int index = 0;
    for (int i = 0; i < len; i++)
    {
        if(time[i]!=':'){
            hour_binary=hour_binary+time[i];
            index++;
            
        }else if(time[i]==':'){
            break;
        }
    }
    for (int i = index+1; i < len; i++)
    {
         if(time[i]!=':'){
            index++;
            minute_binary=minute_binary+time[i];
        }
        else if(time[i]==':'){
            break;
        }
    }
    
    char amorpminbin = time[len-1]; //capture 1 or 0
    
    int hour_readable = todecimal(hour_binary);
    int minute_readable = todecimal(minute_binary);
    string amorpm;
    
    if(hour_readable<1 || hour_readable>12 || minute_readable > 59|| minute_readable<0){
        cout<<"invalid input"<<endl;
        return;
    }
    if(amorpminbin=='1'){
        amorpm = "PM";
    }else
    {
        amorpm = "AM";
    }
    
    
    
    cout<<hour_readable<<":"<<minute_readable<<" "<<amorpm;
    
}



int main() 
{   
    string timeinbinary = "101:100011:1"; //5:35 PM
    converttoreadable(timeinbinary);
    cout<<"\n";

    timeinbinary = "1101:11010:0";//13:26 AM
    converttoreadable(timeinbinary); //invalid output
    cout<<"\n";
    
    timeinbinary = "1100:11010:0"; //12:26 AM
    converttoreadable(timeinbinary); 
    cout<<"\n";
    
    timeinbinary = "1100:111110:0";//12:62 AM
    converttoreadable(timeinbinary); //invalid output
    cout<<"\n";
    
    return 0; 
} 
