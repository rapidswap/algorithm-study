#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    sort(routes.begin(),routes.end());
    
    int backCar=routes[0][1];
    for(auto a:routes){
        if(a[0]>backCar){
            backCar=a[1];
            answer++;
        }
        
        if(backCar>=a[1]) backCar=a[1];
    }
    return answer;
}
