#include<iostream>
using namespace std;

int main(){
    int queue[5];
    int rear=0;
    int front=0;

    cout<<"Enter the Order Numbers of 5 orders:"<<'\n';

    for(int i=0;i<5;i++){
        cin>>queue[rear];
        rear++;
    }

    cout<<"************ORDER IN PROCESS************"<<'\n';

    while(front<rear)
    {
        cout<<"Processing order: "<<queue[front]<<'\n';
        front++;
    }

    return 0;
}
