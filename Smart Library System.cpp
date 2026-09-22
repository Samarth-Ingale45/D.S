#include <iostream>
using namespace std;

int main()
{
    int book[10];
    int n = 0;
    int searchid;
    int choice;

    do
    {
        cout << "\n******* SMART LIBRARY MANAGEMENT SYSTEM *********"<<'\n';
        cout << "1. Add Book ID "<<'\n';
        cout << "2. Display Book IDs"<<'\n';
        cout << "3. Search Book ID"<<'\n';
        cout << "4. Exit"<<'\n';
        cout << "Enter Your Choice: ";
        cin >> choice;

        if (choice == 1)
        {
            if (n < 10)
            {
                cout << "Enter Book ID: ";
                cin >> book[n++];
                cout << "BOOK ADDED\n";
            }
            else
            {
                cout << "Library is full!\n";
            }
        }

        else if (choice == 2)
        {
            cout << "All Book IDs:\n";

            for (int i = 0; i < n; i++)
            {
                cout << book[i] << '\n';
            }
        }

        else if (choice == 3)
        {
            bool found = false;

            cout << "Enter Book ID to Search: ";
            cin >> searchid;

            for (int i = 0; i < n; i++)
            {
                if (book[i] == searchid)
                {
                    cout << "Book Found with Book ID: " << searchid << '\n';
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                cout << "Book Not Found\n";
            }
        }

        else if (choice == 4)
        {
            cout << "THANK YOU\n";
        }

        else
        {
            cout << "Invalid Choice!\n";
        }

    } while (choice != 4);

    return 0;
}
