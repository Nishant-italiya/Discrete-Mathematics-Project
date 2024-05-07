
#include<bits/stdc++.h>
#include <cstdlib>
#include <unistd.h>
using namespace std;
#define fi(l, r) for(int  i = l; i < r; i++)
#define fj(l, r) for(int j = l; j < r; j++)
#define fk(l, r) for(int  k = l; k < r; k++)
#define pb push_back
void Decoding_process(int a[4][4]){
    vector<int>v;
    int count=0;
    fi(0,4){
        fj(1,4){
            if(j!=2)
             if(a[i][j]==1) count++;
        }
    }
    if(count&1) v.pb(1);
    else v.pb(0);
    count=0;
    fi(0,4){
        fj(2,4){
             if(a[i][j]==1) count++;
        }
    }
    if(count&1) v.pb(1);
    else v.pb(0);
    count=0;
    fi(1,4){
        fj(0,4){
            if(i!=2)
             if(a[i][j]==1) count++;
        }
    }
   if(count&1) v.pb(1);
    else v.pb(0);
    count=0;
     fi(2,4){
        fj(0,4){
                if(a[i][j]==1) count++;
            }
    }
    if(count&1) v.pb(1);
    else v.pb(0);
    int arr[4];
    for(int i=v.size()-1;i>=0;i--) arr[3-i]=v[i];
    int d=0;
    for(int i=0;i<4;i++){
        d+=arr[i]*pow(10,3-i);
    }
    int data=d;
    int sum=0;
    int base=1;
    while(data){
        int digit=data%10;
        data=data/10;
        sum+=digit*base;
        base*=2;
    }
    if(sum==3) sum=sum-2;
    if(sum>4 && sum<8) sum=sum-3;
    if(sum>8) sum=sum-4;
    if(sum==0) {
    cout.flush();
    sleep(2);
    cout<<"NO ERROR"<<endl;
    }
    else{
    cout.flush();
    sleep(2);
    cout<<"Position at which your data has been changed"<<endl;
    cout<<sum<<endl;
    }
}
void Encoding_process(string s){
    int a[4][4]={0};
    a[0][3]=s[0]-'0';
    int k=1;
    fi(1,3){
        fj(1,4){
            a[i][j]=s[k]-'0';
            k++;
        }
    }
    fi(0,4) {
        a[3][i]=s[k]-'0';
        k++;
    }
    int count=0;
    fi(0,4){
        fj(2,4){
             if(a[i][j]==1) count++;
        }
    }
    if(count%2!=0) a[0][2]=1;
    count=0;
    fi(0,4){
        fj(1,4){
            if(j!=2)
             if(a[i][j]==1) count++;
        }
    }
    if(count%2!=0) a[0][1]=1;
    count=0;
    fi(2,4){
        fj(0,4){
             if(a[i][j]==1) count++;
        }
    }
    if(count%2!=0) a[2][0]=1;
     count=0;
    fi(1,4){
        fj(0,4){
            if(i!=2)
             if(a[i][j]==1) count++;
        }
    }
    if(count%2!=0) a[1][0]=1;
    count=0;
    fi(0,4){
        fj(0,4){
                if(a[i][j]==1) count++;
            }
    }
    if(count%2!=0) a[0][0]=1;
    srand(time(0));
    int n=rand();
    int m=rand();
    n=n%4;
    m=m%4;
    if((n==0 && m==0)||(n==0 && m==1)||(n==0 && m==2)||(n==1 && m==0)||(n==2 && m==0)){
        cout.flush();
        sleep(2);
        cout<<"Encoding Data :";
        cout<<s<<endl;
        cout.flush();
        sleep(2);
        cout<<"NO ERROR"<<endl;
        return;
    }
    a[n][m]=rand()%2;
    string z;
    z.pb(a[0][3]+'0');
    z.pb(a[1][1]+'0');
    z.pb(a[1][2]+'0');
    z.pb(a[1][3]+'0');
    z.pb(a[2][1]+'0');
    z.pb(a[2][2]+'0');
    z.pb(a[2][3]+'0');
    z.pb(a[3][0]+'0');
    z.pb(a[3][1]+'0');
    z.pb(a[3][2]+'0');
    z.pb(a[3][3]+'0');
    cout.flush();
    sleep(2);
    cout<<"Encoding Data :"<<z<<endl;
    Decoding_process(a);
}

int main(){
    cout<<"Enter your 11 bit binary number :"<<endl;
    string s;
    cin>>s;
    cout<<"Input Data :"<<s<<endl;
    Encoding_process(s);
   
}
                
            
