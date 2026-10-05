#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> q;
    int token;

    cout << "Enter the Token Numbers of the 5 Customers:- " << '\n';

    for (int i = 0; i < 5; i++)
    {
        cin >> token;
        q.push(token);
    }

    cout << "Customers are Waiting " << '\n';

    while (!q.empty())
    {
        cout << "Token Number " << q.front() << '\n';
        q.pop();
    }

    return 0;
}
