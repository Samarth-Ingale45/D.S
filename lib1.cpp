#include <iostream>
using namespace std;

int book[5];
int searchid;
int i;

int main()
{
    cout << "Enter Book IDs: ";

    for(i = 0; i < 5; i++)
    {
        cin >> book[i];
    }

    cout << "Enter the Book ID to search: " << '\n';
    cin >> searchid;

    for(i = 0; i < 5; i++)
    {
        if(book[i] == searchid)
        {
            break;
        }
    }

    if(i < 5)
    {
        cout << "Book Found" << '\n';
    }
    else
    {
        cout << "Book Not Found" << '\n';
    }

    return 0;
}
