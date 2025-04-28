#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> topping) {
    int answer=0;
    unordered_map<int,int> toppingC;
    unordered_map<int,int> toppingB;
    
    for(int i:topping){
        toppingC[i]++;
    }
    
    for(int i=0;i<topping.size();i++){
        if(toppingC.find(topping[i]) != toppingC.end()){
            toppingB[topping[i]]++;
            toppingC[topping[i]]--;
            
            if(toppingC[topping[i]]==0){
                toppingC.erase(topping[i]);
            }
        }
        
        if(toppingC.size() == toppingB.size()){
            answer++;
        }
    }
    return answer;
}
