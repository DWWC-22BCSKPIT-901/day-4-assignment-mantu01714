#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int poisonousPlants(vector<int>& p) {
    stack<pair<int, int>> plantStack; 
    int maxDays = 0;

    for (int pesticide : p) {
        int days = 0;

        while (!plantStack.empty() && plantStack.top().first >= pesticide) {
            days = max(days, plantStack.top().second);
            plantStack.pop();
        }

        if (!plantStack.empty()) {
            days++;
        } else {
            days = 0;
        }

        plantStack.push({pesticide, days});

        maxDays = max(maxDays, days);
    }

    return maxDays;
}

int main() {
    vector<int> p1 = {3, 6, 2, 7, 5};
    cout << poisonousPlants(p1) << endl;

    vector<int> p2 = {6, 5, 8, 4, 7, 10, 9};
    cout << poisonousPlants(p2) << endl; // Output: 2

    return 0;
}
