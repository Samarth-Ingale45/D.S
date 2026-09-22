#include<iostream>
using namespace std;

int main()
{
    int marks[5];

    cout << "Enter the Marks Obtained by 5 students:- " << '\n';

    for(int i = 0; i < 5; i++)
    {
        cin >> marks[i];
    }

    cout << "The Entered 5 marks of the students are:- "<<'\n';

    for(int i = 0; i < 5; i++)
    {
        cout << marks[i] << " "<<'\n';
    }

    
    for(int i = 0; i < 5; i++)
    {
        for(int j = i + 1; j < 5; j++)
        {
            if(marks[i] < marks[j])
            {
                int temp = marks[i];
                marks[i] = marks[j];
                marks[j] = temp;
            }
        }
    }

    cout << "Marks in Descending Order: "<<'\n';

    for(int i = 0; i < 5; i++)
    {
        cout << "Student " << i + 1 << " :- " << marks[i] << '\n';
    }

    return 0;
}
