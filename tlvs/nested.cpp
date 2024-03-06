#include<bits/stdc++.h>
using namespace std;

void parsing(vector<uint8_t>& vec, int i){
    //cout<<"check flag1 "<<endl;
    //cout<<"The value of i "<<i<<endl;
    
    // checking nested
    bool nested = 0;
    if( (vec[i] & 0x20) == 0x20)
        nested=1;
    //cout<<"check flag2 nested : "<<nested<<endl;

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

    //cout<<"Check flag3 value of i "<<i<<endl;


    // length field
    int value_field_length=0;
    cout<<"The value of length field is: ";
    if( vec[i] & 0x80){
        //cout<<"check flag4 "<<endl;
        int length_value = (vec[i] & 0x7F);
        int till = i + length_value;
        i++;
        while(i <= till){
            value_field_length = (value_field_length << 8) | vec[i];
            cout<<hex<<static_cast<int>(vec[i])<<" ";
            i++;
        }
        cout<<endl;
    }
    else{
        value_field_length = (value_field_length << 8) | vec[i];
        cout<<hex<<static_cast<int>(vec[i])<<" "<<endl;
        i++;
    }
    int till2 = i + value_field_length ;

    // value field
    if(nested){
        parsing(vec,i);
    }
    else{
        //cout<<"Let's code !!"<<endl;
        cout<<"The actual data is: ";
        while(i < till2){
            cout<<hex<<static_cast<int>(vec[i])<<" ";
            i++;
        }
        cout<<endl;
    }
    
}





int main(){
    vector<uint8_t>temp_array={0xBF, 0x5E, 0x81, 0x0B, 0xBF, 0xA1, 0x65, 0x07, 0x9F, 0xA1, 0x67, 0x03, 0x00, 0xFF, 0x00};

    int sz = temp_array.size();
    int index = 0;
    parsing(temp_array,index);
}