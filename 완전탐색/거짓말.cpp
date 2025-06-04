#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    vector<bool> knownPeople(N + 1, false);

    int known;
    cin >> known;
    for (int i = 0; i < known; i++) {
        int a;
        cin >> a;
        knownPeople[a] = true;
    }

    vector<vector<int>> parties(M);
    for (int i = 0; i < M; i++) {
        int a;
        cin >> a;
        for (int j = 0; j < a; j++) {
            int person;
            cin >> person;
            parties[i].push_back(person);
        }
    }


    bool changed = true;
    while (changed) {
        changed = false;

        for (int i = 0; i < M; i++) {
            bool hasKnownPerson = false;
            for (int person : parties[i]) {
                if (knownPeople[person]) {
                    hasKnownPerson = true;
                    break;
                }
            }

            if (hasKnownPerson) {
                for (int person : parties[i]) {
                    if (!knownPeople[person]) {
                        knownPeople[person] = true;
                        changed = true;  
                    }
                }
            }
        }
    }


    int answer = 0;
    for (int i = 0; i < M; i++) {
        bool canLie = true;
        for (int person : parties[i]) {
            if (knownPeople[person]) {
                canLie = false;
                break;
            }
        }
        if (canLie) {
            answer++;
        }
    }

    cout << answer << endl;

    return 0;
}
