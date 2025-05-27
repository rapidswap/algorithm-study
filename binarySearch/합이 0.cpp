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
    vector<int> nums(N);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());

    long long answer = 0;



    for (int i = 0; i < N-1; i++) {
        for (int j = i + 1; j < N; j++) {
            long long k = lower_bound(nums.begin() + j + 1, nums.end(), -(nums[i] + nums[j])) - nums.begin();

            if (k >= N || nums[k] != -(nums[i] + nums[j])) continue;

            long long u = upper_bound(nums.begin() + j + 1, nums.end(), -(nums[i] + nums[j])) - nums.begin();

            answer += u - k;
        }
    }




    cout << answer;
    return 0;
}
