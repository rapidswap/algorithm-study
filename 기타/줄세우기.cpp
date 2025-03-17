#include<iostream>
#include<vector>
#include<string>

#include<algorithm>

using namespace std;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case ++)
    {
        int n;
        cin >> n;

        vector<int> height;
        vector<int>original;
        for (int i = 0; i < 20; i++)
        {
            int a;
            cin >> a;

            height.push_back(a);
            original.push_back(a);
        }
        int cnt = 0;
        int idx = 0;
        for (int i = 0; i < 20; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (original[i] < height[j])
                {
              
                    height.erase(remove(height.begin(),height.end(),original[i]),height.end());
                    height.insert(height.begin() + j, original[i]);
       
                    cnt += (i+1)- (j + 1);
                    break;
                }
            }
        }
        cout <<test_case << " " << cnt << "\n";
    }
    

    return 0;
}
