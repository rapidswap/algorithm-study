#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    vector<int> running_servers;

    for (int num_players : players) {
        
        for (int& timeLeft : running_servers) {
            timeLeft--;
        }
        running_servers.erase(
            remove_if(running_servers.begin(), running_servers.end(), [](int time) {
                return time <= 0;
            }),
            running_servers.end()
        );


        int required_servers = num_players / m;
        
        int current_servers = running_servers.size();

        if (required_servers > current_servers) {
            int new_servers_needed = required_servers - current_servers;
            answer += new_servers_needed;
            for (int i = 0; i < new_servers_needed; ++i) {
                running_servers.push_back(k);
            }
        }
    }

    return answer;
}
