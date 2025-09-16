#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include<map>
using namespace std;
typedef long long ll;

int n, m;
int answer[10] = { 0 };
int arr[10];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

   
    cin >> n;

    priority_queue<int,vector<int>,greater<int>> pq;

    for (int i = 0; i < n * n; i++) {
        int a;
        cin >> a;

        pq.push(a);
        if (pq.size() > n) {
            pq.pop();
        }

    }
    

    cout << pq.top();
    return 0;
}
