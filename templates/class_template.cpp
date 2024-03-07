#include<bits/stdc++.h>
using namespace std;

/*class book{
    public:
    int book_no;
    string book_name;

    book(int d1, string d2){
        book_no = d1;
        book_name = d2;
    }

    public:
    void disp(){
        cout<<book_no<<endl;
        cout<<book_name<<endl;
    }


};

int main(){
    book obj1(1234, "economics");
    obj1.disp();
    
}
*/

template<typename T1,typename T2>
class calculator{
    public:
    T1 first_num;
    T2 second_num;


    public:
    calculator(T1 d1, T2 d2){
        first_num = d1;
        second_num = d2;
    }

    public:

    void add(){
        cout<<(first_num + second_num)<<endl;
    }

    void subtract(){
        cout<<(first_num - second_num)<<endl;
    }

    void multiply(){
        cout<<first_num * second_num<<endl;
    }

    void divide(){
        cout<<first_num / second_num<<endl;
    }
};

int main(){
    calculator<double ,double>obj (3.6, 1.2);
    obj.multiply();
    obj.divide();
}