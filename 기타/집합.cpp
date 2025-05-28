#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <climits>
#include <cstring>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    string order;

    vector<int> num;
    for (int i = 0; i < N; i++) {
        cin >> order;
        
        
        if (order == "add") {
            int a;
            cin >> a;
            if (binary_search(num.begin(), num.end(), a)) continue;
            num.push_back(a);
            sort(num.begin(), num.end());

        }
        else if (order == "remove") {
            int a;
            cin >> a;
            if (binary_search(num.begin(), num.end(), a)) {
                int b = lower_bound(num.begin(), num.end(), a) - num.begin();
                num.erase(num.begin() + b);
            }
        }
        else if (order == "check") {
            int a;
            cin >> a;
            if (binary_search(num.begin(), num.end(), a)) {
                cout << 1 << "\n";
            }
            else {
                cout << 0 << "\n";
            }
        }
        else if (order == "toggle") {
            int a;
            cin >> a;
            if (binary_search(num.begin(), num.end(), a)) {
                int b = lower_bound(num.begin(), num.end(), a) - num.begin();
                num.erase(num.begin() + b);
            }
            else {
                num.push_back(a);
                sort(num.begin(), num.end());
            }

        }
        else if (order == "all") {
            num.clear();
            for (int n = 1; n <= 20; n++) {
                num.push_back(n);
            }
        }
        else if (order == "empty") {
            num.clear();
        }
    }

    


    return 0;
}
