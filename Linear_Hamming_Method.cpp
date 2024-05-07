
#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#include<iostream>
#include <cstdlib>
#include <unistd.h>
using namespace std;



int main(){
    cout<<"Enter your 4 bit binary number :"<<endl;
    string s;
    cin>>s;
    cout<<"INPUT DATA :"<<s<<endl;
    int a[7];
    a[0]=s[0]-'0';
    a[1]=s[1]-'0';
    a[2]=s[2]-'0';
    a[3]=a[0]^a[1]^a[2];
    a[4]=s[3]-'0';
    a[5]=a[0]^a[1]^a[4];
    a[6]=a[0]^a[2]^a[4];
    srand(time(0));
    int e=rand()%7;
    a[7-e]=rand()%2;
    int c1,c2,c3;
    c1=a[0]^a[2]^a[4]^a[6];
    c2=a[0]^a[1]^a[4]^a[5];
    c3=a[0]^a[1]^a[2]^a[3];
    int d=c3*100+c2*10+c1;
    int data=d;
    int sum=0;
    int base=1;
    while(data){
        int digit=data%10;
        data=data/10;
        sum+=digit*base;
        base*=2;
    }
    cout.flush();
    sleep(2);
    cout<<"Encoding Data :"<<a[0]<<a[1]<<a[2]<<a[4]<<endl;
    if(sum==4||sum==1||sum==0||sum==2) {
    cout.flush();
    sleep(2);
    cout<<"NO ERROR"<<endl;
    }
    else{
     cout.flush();
     sleep(2);
         cout<<"Position at which your data has been changed"<<endl;
         if(sum==3) cout<<4<<endl;
         else cout<<8-sum<<endl;
    }
   
}
                
            
