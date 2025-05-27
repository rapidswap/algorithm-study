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
    for (int i = 0; i < N; i++) {
        int target = nums[i];

        int st = 0;
        int ed = N - 1;
        while (st < ed) {
            if (st == i) {
                st++;
                continue;
            }
            if (ed == i) {
                ed--;
                continue;
            }

            long long sum = nums[st] + nums[ed];
            if (nums[i] > sum) {
                st++;
            }
            else if (nums[i] < sum) {
                ed--;
            }
            else {
                answer++;
                break;
            }
        }
    }
    cout << answer;
    return 0;
}
