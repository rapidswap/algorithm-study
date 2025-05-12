#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;


int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    priority_queue<int,vector<int>,greater<int>> heap;
    vector<int> answer;

    for (int i = 0; i < N; i++) {
        int order;
        cin >> order;

        if (order == 0) {
            if (heap.empty()) {
                answer.push_back(0);
            }
            else {
                answer.push_back(heap.top());
                heap.pop();
            }
        }
        else {
            heap.push(order);
        }
    }

    for (int n : answer) {
        cout << n << '\n';
    }
    return 0;
}
