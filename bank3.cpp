#include <iostream>
using namespace std;

int main()
{
    int tokens[100];
    int front = 0;
    int rear = 0;
    int tokenNumber = 1;
    int choice;

    do
    {
        cout << "\n----- TOKEN QUEUE SYSTEM -----\n";
        cout << "1. Issue Token\n";
        cout << "2. Display Waiting Tokens\n";
        cout << "3. Serve Customer\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                if (rear < 100)
                {
                    tokens[rear] = tokenNumber;

                    cout << "Token issued successfully: "
                         << tokenNumber << endl;

                    rear++;
                    tokenNumber++;
                }
                else
                {
                    cout << "Token queue is full.\n";
                }
                break;

            case 2:
                if (front == rear)
                {
                    cout << "No customers are waiting.\n";
                }
                else
                {
                    cout << "\nWaiting Tokens:\n";

                    for (int i = front; i < rear; i++)
                    {
                        cout << tokens[i] << " ";
                    }

                    cout << endl;
                }
                break;

            case 3:
                if (front == rear)
                {
                    cout << "No customer to serve.\n";
                }
                else
                {
                    cout << "Serving customer with Token Number: "
                         << tokens[front] << endl;

                    front++;
                }
                break;

            case 4:
                cout << "Exiting the program. Thank you!\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}
