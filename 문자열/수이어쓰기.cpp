#include<iostream>
#include<vector>
#include<string>

#include<algorithm>

using namespace std;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<string> v;
    string num;
    cin >> num;


    int i = 1;
    int idx = 0;
    for(int i=1;i<=30000;i++)
    {
        string c = to_string(i);
        for (int j = 0; j < c.size(); j++)
        {
            if (num[idx] == c[j])
            {
                idx++;
            }
            if (idx == num.size())
            {
                cout << i;
                return 0;
            }
        }
    }
    cout << i;
    return 0;
}
