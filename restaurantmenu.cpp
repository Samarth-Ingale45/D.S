#include<iostream>
using namespace std;

void menu(){
    int choice;

    do
    {
        cout<<"*************RESTAURANT MENU*************"<<'\n';
        cout<<"1. Dal Fry"<<'\n';
        cout<<"2. Jeera Rice"<<'\n';
        cout<<"3. Dalcha Rice"<<'\n';
        cout<<"4. Paneer Masala"<<'\n';
        cout<<"5. Veg Fried Rice"<<'\n';
        cout<<"6. Exit"<<'\n';

        cout<<"Enter Your Choice:- ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                cout<<"You selected Dal Fry"<<'\n';
                break;

            case 2:
                cout<<"You selected Jeera Rice"<<'\n';
                break;

            case 3:
                cout<<"You selected Dalcha Rice"<<'\n';
                break;

            case 4:
                cout<<"You selected Paneer Masala"<<'\n';
                break;

            case 5:
                cout<<"You selected Veg Fried Rice"<<'\n';
                break;

            case 6:
                cout<<"Thank You, VISIT AGAIN"<<'\n';
                break;

            default:
                cout<<"Invalid Choice"<<'\n';
        }

    } while(choice != 6);
}

int main(){
    menu();
    return 0;
}
