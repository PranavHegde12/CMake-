#include<bits/stdc++.h>
using namespace std;

void parsing(vector<uint8_t>& vec, int i){
    cout<<"check flag1 "<<endl;
    cout<<"The value of i "<<i<<endl;
    
    // checking nested
    bool nested  =0;
    if( (vec[i] & 0x20) == 0x20)nested=1;
    cout<<"check flag2 nested : "<<nested<<endl;

    //  tag field
    cout<<"Tag value is: ";
    if((vec[i] & 0x1F) == 0x1F){
        cout<<hex<<static_cast<int>(vec[i])<<" ";
        i++;
        //cout<<hex<<static_cast<int>(vec[i])<<" ";
        while( vec[i] & 0x80){
            cout<<hex<<static_cast<int>(vec[i])<<" ";
            i++;
        }
        cout<<hex<<static_cast<int>(vec[i])<<" ";
        i++;
        cout<<endl;
    }
    else{
        cout<<hex<<static_cast<int>(vec[i])<<" "<<endl;
        i++;
    }

    cout<<"Check flag3 value of i "<<i<<endl;

    
    // length field
    cout<<"The value of length field is: ";
    if( vec[i] & 0x80){
        cout<<"check flag4 "<<endl;
        int length_value = (vec[i] & 0x7F);
        int till = i+ length_value;
        i++;
        while(i <= till){
            cout<<hex<<static_cast<int>(vec[i])<<" ";
            i++;
        }
        cout<<endl;
    }
    else{
        cout<<hex<<static_cast<int>(vec[i])<<" "<<endl;
        i++;
    }

    // value field
    if(nested){
        parsing(vec,i);
    }
    else{
        cout<<"Let's code !!"<<endl;
    }
    
}





int main(){
    vector<uint8_t>temp_array={0xBF, 0x5E, 0x81, 0x04, 0x9F, 0x21, 0x01, 0xFF};

    int sz = temp_array.size();
    int index = 0;
    parsing(temp_array,index);
}