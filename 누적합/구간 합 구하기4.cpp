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

    int N,M;
    cin >> N>>M;

    vector<int> nums(N);
    int sum = 0;
    vector<int> sums;
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
        sum += nums[i];
        sums.push_back(sum);
    }

    for (int i = 0; i < M; i++) {
        int a, b;
        int answer;
        cin >> a >> b;

        if (a == 1) {
            answer = sums[b-1];
        }
        else
            answer = sums[b - 1] - sums[a - 2];

        if (a == b) {
            cout << nums[a-1] << '\n';
        }
        else {
            cout << answer << '\n';
        }
    }



    


    return 0;
}
