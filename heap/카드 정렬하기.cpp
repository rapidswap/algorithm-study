#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;



int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int n;
    cin >> n;
    
    priority_queue<int,vector<int>,greater<int>> heap;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        heap.push(a);
    }

    int answer = 0;
    while (heap.size()>1) {
        int a = heap.top(); heap.pop();
        int b = heap.top(); heap.pop();
        answer += a + b;
        heap.push(a+b);
    }
    
    cout << answer;
    return 0;
}
