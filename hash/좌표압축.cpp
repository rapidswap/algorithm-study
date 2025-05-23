#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

int n;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    vector<int> nums(n);
 
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    vector<int> sortNums(nums.begin(), nums.end());
    sort(sortNums.begin(), sortNums.end(),greater<int>());

    set<int> num(sortNums.begin(), sortNums.end());
    map<int, int> ranking;
    int rank=0;
    for (int nn:num) {
        ranking[nn] = rank;
        rank++;
    }

    for (int i = 0; i < n; i++) {
        cout << ranking[nums[i]] << ' ';
    }

    return 0;
}
