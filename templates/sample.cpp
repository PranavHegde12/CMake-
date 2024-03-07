#include<bits/stdc++.h>
using namespace std;

template<typename T1, typename T2>
T1 add(T1 a, T2 b){
    cout<<"first "<<endl;
    return (a+b);
}

template<typename T1>
T1 add(T1 a, T1 b){
    cout<<"2nd "<<endl;
    return a+b;
}


int main(){
    int a=10,b=9;
    float x=5.3,y=6.6;
    cout<<add(a,b)<<endl;
    return 0;
}