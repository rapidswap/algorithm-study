#include <iostream>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int testCase;
    cin >> testCase;

    for (int i = 0; i < testCase; i++) {
        multiset<int> dq;

        int a;
        cin >> a;

        for (int j = 0; j < a; j++) {
            char c;
            int b;
            cin >> c >> b;

            if (c == 'I') {
                dq.insert(b);
            }
            else if (c == 'D' && !dq.empty()) {
                if (b == 1) { 
                    dq.erase(prev(dq.end()));
                }
                else if (b == -1) { 
                    dq.erase(dq.begin());
                }
            }
        }

        if (dq.empty()) {
            cout << "EMPTY\n";
        }
        else {
            cout << *dq.rbegin() << ' ' << *dq.begin() << '\n';
        }
    }

    return 0;
}
