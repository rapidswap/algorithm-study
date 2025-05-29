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

    int testCase;
    cin >> testCase;

    for (int i = 0; i < testCase; i++) {
        string order;
        int n;
        string arrStr;
        cin >> order >> n >> arrStr;


        vector<int> arr;
        string num = "";
        bool inNumber = false;

        for (char c : arrStr) {
            if (isdigit(c)) {
                num += c;
                inNumber = true;
            }
            else if (c == ',' || c == ']') {
                if (inNumber && !num.empty()) {
                    arr.push_back(stoi(num));
                    num = "";
                    inNumber = false;
                }
            }
        }


        bool reversed = false;
        bool error = false;
        int front = 0, back = 0;  
        for (char c : order) {
            if (c == 'R') {
                reversed = !reversed;
            }
            else if (c == 'D') {
                if (front + back >= n) {
                    error = true;
                    break;
                }

                if (!reversed) {
                    front++;  
                }
                else {
                    back++;   
                }
            }
        }

        if (error) {
            cout << "error\n";
        }
        else {
            cout << '[';

            vector<int> result;
            for (int j = front; j < n - back; j++) {
                result.push_back(arr[j]);
            }

            if (reversed) {
                reverse(result.begin(), result.end());
            }

            for (int j = 0; j < result.size(); j++) {
                if (j > 0) cout << ',';
                cout << result[j];
            }

            cout << "]\n";
        }
    }

    return 0;
}
