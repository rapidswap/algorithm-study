#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(const pair<int, string>& a, const pair<int, string>& b) {
    return a.second < b.second;
}

int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int p,m;
    cin >> p >> m;


    vector<pair<int, string>> players;

    vector<vector<pair<int, string>>> rooms(p,vector<pair<int,string>>(1,{0,"N"}));
    for (int i = 0; i < p; i++) {
        int lev;
        string name;
        cin >> lev >> name;
        players.push_back({ lev,name });

        if (i == 0) {
            rooms[0][0].first = lev;
            rooms[0][0].second = name;
        }
        else {
            for (int j = 0; j < p; j++) {
                

                if (rooms[j][0].first == 0 && rooms[j][0].second == "N") {
                    rooms[j][0].first = lev;
                    rooms[j][0].second = name;
                    break;
                }

                if (rooms[j].size() == m) continue;

                if (rooms[j][0].first - 10 > lev || rooms[j][0].first + 10 < lev) {
                    continue;
                }
                else {
                    rooms[j].push_back({ lev,name });
                    break;
                }
            }
        }

        
    }

    for (auto &room : rooms) {
        sort(room.begin(), room.end(), cmp);
    }

    for (auto a : rooms) {
        if (a[0].first == 0 && a[0].second == "N") continue;
        if (a.size() < m)
            cout << "Waiting!\n";
        else
            cout << "Started!\n";
        for (int i = 0; i < a.size(); i++) {
            cout << a[i].first << ' ' << a[i].second << '\n';
        }
    }
    
    return 0;
}
