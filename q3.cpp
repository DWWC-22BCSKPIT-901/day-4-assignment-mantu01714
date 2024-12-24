#include <iostream>
#include <queue>
using namespace std;
void reverseQueue(queue<int>& q) {
    if (q.empty()) {
        return;
    }

    int front = q.front();
    q.pop();

    reverseQueue(q);
    q.push(front);
}

int main() {
    queue<int> q1;
    vector<int> input1 = {5, 24, 9, 6, 8, 4, 1, 8, 3, 6};
    for (int i : input1) {
        q1.push(i);
    }

    cout << "Original Queue 1: ";
    queue<int> temp1 = q1;
    while (!temp1.empty()) {
        cout << temp1.front() << " ";
        temp1.pop();
    }
    cout << endl;

    reverseQueue(q1);

    cout << "Reversed Queue 1: ";
    while (!q1.empty()) {
        cout << q1.front() << " ";
        q1.pop();
    }
    cout << endl;

    queue<int> q2;
    vector<int> input2 = {8, 7, 2, 5, 1};
    for (int i : input2) {
        q2.push(i);
    }

    cout << "Original Queue 2: ";
    queue<int> temp2 = q2;
    while (!temp2.empty()) {
        cout << temp2.front() << " ";
        temp2.pop();
    }
    cout << endl;

    reverseQueue(q2);

    cout << "Reversed Queue 2: ";
    while (!q2.empty()) {
        cout << q2.front() << " ";
        q2.pop();
    }
    cout << endl;

    return 0;
}
