#include<iostream>
using namespace std;

int main(){
    int tokens[5];

    cout<<"Enter 5 customers token of served customers"<<'\n';

    for(int i=0;i<5;i++)
    {
        cin>>tokens[i];
    }

    cout<<"Service History "<<'\n';

    for(int i=4;i>=0;i--)
    {
        cout<<"Token No: "<<tokens[i]<<'\n';
    }

    return 0;
}
