#include <iostream>
#include <vector>
#include <algorithm> // sort를 위해 추가

using namespace std;

int n, m;
vector<int> num;   
vector<int> nums;  
vector<bool> vist; 
void dfs() {

    if (num.size() == m) {
        for (int val : num) {
            cout << val << ' ';
        }
        cout << '\n';
        return; 
    }


    for (int i = 0; i < n; i++) {
        if (!vist[i]) {
            vist[i] = true;            
            num.push_back(nums[i]);    
            dfs();                     

            num.pop_back();            
            vist[i] = false;           
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    nums.resize(n); 
    vist.resize(n, false);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    dfs();

    return 0;
}
