#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <limits.h>
#include <cmath>
#include <algorithm>
#include <unordered_map>

using namespace std;
int board[501][501];
bool vst[501][501] = { false };
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string str;
    getline(cin, str);


    int zeroCnt = 0;
    int oneCnt = 0;
    bool sw;
    if(str[0]=='0')
        sw = true;
    else
        sw = false;

    for (int i = 1; i < str.size(); i++)
    {
        if (str[i] == '1' && sw)
        {
            
            zeroCnt++;
            sw = false;
        }
        else if (str[i] == '0' && !sw)
        {

            oneCnt++;
            sw = true;
        }
    }
    if (zeroCnt > 0 || oneCnt > 0)
    {
        if (sw)
            zeroCnt++;
        else
            oneCnt++;
    }


    int getMin = min(zeroCnt, oneCnt);

    cout << getMin;
  
    return 0;
}
