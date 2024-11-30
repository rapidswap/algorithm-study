#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <limits.h>
#include <cmath>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, P;
    long long newPoint;
    cin >> N >> newPoint >> P;

    unordered_map<long long, int> m;
    vector<long long> Point;

    for (int i = 0; i < N; i++) {
        long long a;
        cin >> a;
        Point.push_back(a);
        m[a]++;
    }
    if (!Point.empty())
    {
        long long getMin = *min_element(Point.begin(), Point.end());
        if (getMin < newPoint || Point.size()<P) {
            Point.push_back(newPoint);
        }
        else {

            cout << -1;
            return 0;
        }
    }
    else
    {
        cout << 1;
        return 0;
    }

    
    sort(Point.begin(), Point.end(), greater<long long>());
    Point.erase(unique(Point.begin(), Point.end()), Point.end()); 

    vector<pair<long long, int>> ranking;
    int cnt = 0;
    int rank = 1;

    for (int i = 0; i < Point.size(); i++) {
        cnt += m[Point[i]];
        ranking.push_back({ Point[i], rank });

        rank += cnt;
        cnt = 0; 
        
    }

    for (auto a : ranking) {
        if (a.first == newPoint) {
            if (a.second > P) {

                cout << -1;
                return 0;
            }
            else {
                cout << a.second;
                break;
            }
        }
    }

    return 0;
}
