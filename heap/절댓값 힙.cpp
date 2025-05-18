#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;


class cmp {
public:
    bool operator() (int a, int b) {
        if (abs(a) != abs(b)) return abs(a) > abs(b);
        return a>0&&b<0;
    }
};
int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int n;
    cin >> n;
    
    priority_queue<int,vector<int>,cmp> heap;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        if (a == 0) {
            if (heap.empty()) cout << 0<<"\n";
            else {
                cout << heap.top()<<"\n";
                heap.pop();
            }
        }
        else {
            heap.push(a);
        }
    }

    

    return 0;
}
