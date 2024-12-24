#include <iostream>
#include <vector>
#include <set>
#include <stack>
using namespace std;

class DinnerPlates {
private:
    int capacity;                        
    vector<stack<int>> stacks;            
    set<int> available;                    

public:
    DinnerPlates(int cap) : capacity(cap) {}

    void push(int val) {
        if (available.empty() || *available.begin() >= stacks.size()) {
            stacks.push_back(stack<int>());
            available.insert(stacks.size() - 1);
        }
        int idx = *available.begin();
        stacks[idx].push(val);

        if (stacks[idx].size() == capacity) {
            available.erase(idx);
        }
    }

    int pop() {
        while (!stacks.empty() && stacks.back().empty()) {
            stacks.pop_back();
        }

        if (stacks.empty()) return -1; // All stacks are empty

        int val = stacks.back().top();
        stacks.back().pop();
        if (stacks.back().size() < capacity) {
            available.insert(stacks.size() - 1);
        }

        return val;
    }

    int popAtStack(int index) {
        if (index >= stacks.size() || stacks[index].empty()) return -1;

        int val = stacks[index].top();
        stacks[index].pop();

        if (stacks[index].size() < capacity) {
            available.insert(index);
        }

        return val;
    }
};

int main() {
    DinnerPlates D(2);

    D.push(1);
    D.push(2);
    D.push(3);
    D.push(4);
    D.push(5);

    cout << D.popAtStack(0) << endl; // Output: 2
    D.push(20);
    D.push(21);
    cout << D.popAtStack(0) << endl;
    cout << D.popAtStack(2) << endl; 
    cout << D.pop() << endl;         
    cout << D.pop() << endl;        
    cout << D.pop() << endl;         
    cout << D.pop() << endl;         
    cout << D.pop() << endl;        

    return 0;
}
