#include <iostream>
#include <cstring>
#include <queue>
#include <tuple>
#include <unordered_map>
using namespace std;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N,M;
    cin >> N >> M;

    unordered_map<string, string> password;
    for (int i = 0; i < N; i++) {
        string adr, pwd;
        cin >> adr >> pwd;
        password[adr] = pwd;
    }
    
    for (int i = 0; i < M; i++) {
        string adr;
        cin >> adr;
        cout << password[adr] << '\n';
    }
    

    return 0;
}
