#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
//find 시간초과로 unordered_map 사용 해서
    unordered_map<string, int> index_map;
    for (int i = 0; i < players.size(); i++) {
        index_map[players[i]] = i;
    }

    for (string& call : callings) {
        int idx = index_map[call];

        if (idx > 0) { 

            swap(players[idx], players[idx - 1]);

            index_map[players[idx]] = idx;
            index_map[players[idx - 1]] = idx - 1;
        }
    }

    return players;
}
