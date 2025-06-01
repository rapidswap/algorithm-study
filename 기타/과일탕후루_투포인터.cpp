#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> fruit(N);

    for (int i = 0; i < N; i++) {
        cin >> fruit[i];
    }

    int left = 0, maxLen = 0;
    unordered_map<int, int> count; 

    for (int right = 0; right < N; right++) {
        count[fruit[right]]++;

        while (count.size() > 2) {
            count[fruit[left]]--;
            if (count[fruit[left]] == 0) {
                count.erase(fruit[left]);
            }
            left++;
        }

        maxLen = max(maxLen, right - left + 1);
    }

    cout << maxLen << '\n';
    return 0;
}
