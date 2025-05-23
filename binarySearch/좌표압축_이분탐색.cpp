#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

int n;
int x[1000001];
int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    vector<int> nums;
 
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        nums.push_back(x[i]);
    }

    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    for (int i = 0; i < n; i++) {
        cout << lower_bound(nums.begin(), nums.end(), x[i]) - nums.begin() << ' ';
    }
    

    return 0;
}
