// Determine how many students are unable to eat given their preferences and the order of sandwiches in the stack.
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int countStudents(vector<int>& students, vector<int>& sandwiches) {
    queue<int> studentQueue; 
    queue<int> sandwichStack;  

    for (int student : students) {
        studentQueue.push(student);
    }
    for (int sandwich : sandwiches) {
        sandwichStack.push(sandwich);
    }

    int count = 0;

    while (!studentQueue.empty() && !sandwichStack.empty()) {
        if (studentQueue.front() == sandwichStack.front()) {
            studentQueue.pop();
            sandwichStack.pop();
            count = 0; // Reset the loop count
        } else {
            int student = studentQueue.front();
            studentQueue.pop();
            studentQueue.push(student);
            count++;

            if (count == studentQueue.size()) {
                break;
            }
        }
    }

    return studentQueue.size();
}

int main() {
    vector<int> students1 = {1, 1, 0, 0};
    vector<int> sandwiches1 = {0, 1, 0, 1};
    cout << countStudents(students1,
    vector<int> students2 = {1, 1, 1, 0, 0, 1};
    vector<int> sandwiches2 = {1, 0, 0, 0, 1, 1};
    cout << countStudents(students2, sandwiches2) << endl; // Output: 3

    return 0;
}
