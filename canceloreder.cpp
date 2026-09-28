#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> cancelStack;

    cout << "Enter 5 canceled order numbers:- "<<'\n';
    for (int i = 0; i < 5; ++i) {
        int orderNum;
        cin >> orderNum;
        cancelStack.push(orderNum);
    }

    cout <<"Displaying canceled orders :- "<<'\n';
    while (!cancelStack.empty()) {
        cout << "Canceled Order: " << cancelStack.top() << '\n';
        cancelStack.pop();
    }

    return 0;
}
