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

int dy[] = { 0,1,0,-1 };
int dx[] = { -1,0,1,0 };

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    
    


    
    for (int i = 0; i < N; i++) {
        vector<pair<int, int>> nums(41);
        nums[0].first = 1;
        nums[0].second = 0;
        nums[1].first = 0;
        nums[1].second = 1;
        int fibo;
        cin >> fibo;
        for (int j = 2; j <= fibo; j++) {
            nums[j] = make_pair(nums[j-1].first + nums[j-2].first,
                                nums[j-1].second + nums[j-2].second);
        }
        cout << nums[fibo].first << ' ' << nums[fibo].second<<'\n';
        

    }
    


    return 0;
}
