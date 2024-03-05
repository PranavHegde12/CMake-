#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<uint8_t>temp_array={0x57, 0x13, 0x54, 0x13, 0x33, 0x00, 0x89, 0x70, 0x01, 0x25, 0xd4, 0x91, 0x22, 0x06, 0x01, 0x23, 
    0x45, 0x67, 0x89, 0x01, 0x2f, 0x5a, 0x08, 0x54, 0x13, 0x33, 0x00, 0x89, 0x70, 0x01, 0x25, 0x5f, 
    0x24, 0x03, 0x49, 0x12, 0x31, 0x5f, 0x25, 0x03, 0x18, 0x05, 0x01, 0x5f, 0x28, 0x02, 0x00, 0x56, 
    0x5f, 0x34, 0x01, 0x49, 0x8c, 0x21, 0x9f, 0x02, 0x06, 0x9f, 0x03, 0x06, 0x9f, 0x1a, 0x02, 0x95, 
    0x05, 0x5f, 0x2a, 0x02, 0x9a, 0x03, 0x9c, 0x01, 0x9f, 0x37, 0x04, 0x9f, 0x35, 0x01, 0x9f, 0x45, 
    0x02, 0x9f, 0x4c, 0x08, 0x9f, 0x34, 0x03, 0x8d, 0x0c, 0x91, 0x0a, 0x8a, 0x02, 0x95, 0x05, 0x9f, 
    0x37, 0x04, 0x9f, 0x4c, 0x08, 0x8e, 0x12, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x41, 
    0x03, 0x44, 0x03, 0x42, 0x03, 0x5e, 0x03, 0x5f, 0x03, 0x9f, 0x07, 0x02, 0xff, 0x00, 0x9f, 0x08, 
    0x02, 0x00, 0x02, 0x9f, 0x0d, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9f, 0x0e, 0x05, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x9f, 0x0f, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9f, 0x42, 0x02, 0x09, 0x78, 0x9f, 0x4a, 0x01, 0x82};

    int size = temp_array.size();

    bool nested =0;
    if(temp_array[0] & 32){
        nested = 1;
    }

    int i=0;
    vector<uint8_t>tag_array;
    if(((temp_array[0]) & 0x1F)== 0x1F){
        i++;
        tag_array.push_back(temp_array[i] & 0x7F);
        while(temp_array[i] & 128){
            i++;
            tag_array.push_back(temp_array[i] & 0x7F);
        }
        i++;
    }

    int length_size;
    vector<int>length_array;
    if(temp_array[i] & 0x80){
        length_size = temp_array[i] & 0x7F;
        int till = i+length_size;
        i++;
        while(i <= till){
            length_array.push_back(temp_array[i] & 0xFF);
            i++;
        }
    }

    vector<int> values_array;
    while(i<size){
        values_array.push_back(temp_array[i] & 0xFF);
    }

    cout<<"The tag value is: ";
    for(int i=0; i<tag_array.size();i++){
        cout<<tag_array[i]<<" ";
    }
    cout<<endl;

    cout<<"The length value is: ";
    for(int j=0;j<length_array.size();j++){
        cout<<length_array[j]<<" ";
    }
    cout<<endl;

    cout<<"The data is: ";
    for(int k=0;k<values_array.size();k++){
        cout<<values_array[k]<<" ";
    }
    cout<<endl;

    return 0;
}