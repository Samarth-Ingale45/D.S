#include<iostream>
using namespace std;

int main()
{
    int roll[5];
    int search;
    bool found = false;

    cout << "Enter the Rollno of 5 students:- " << '\n';

    for (int i = 0; i < 5; i++)
    {
        cin >> roll[i];
    }

    cout << "Entered Rollno of 5 students are: " << '\n';

    for (int i = 0; i < 5; i++)
    {
        cout << roll[i] << " " << '\n';
    }

    cout << "Enter a Rollno to Search:- " << '\n';
    cin >> search;

    for (int i = 0; i < 5; i++)
    {
        if (roll[i] == search)
        {
            cout << "Found" << '\n';
            found = true;

        }
    }

    if (found == false)
    {
        cout << "Not Found" << '\n';
    }

    return 0;
}
