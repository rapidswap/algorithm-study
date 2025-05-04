#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

bool check(string a, string b){
    if(a.size()!=b.size()) return false;
    
    for(int i=0;i<a.size();i++){
        if(a[i]=='*') continue;
        if(a[i]!=b[i]) return false;
    }
    return true;
}


int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    
    
    
    set<string> id_list;
    sort(user_id.begin(),user_id.end());
    
    
    do{
        vector<string> temp;
        string id="";
        
        for(int i=0;i<banned_id.size();i++){
            if(check(banned_id[i],user_id[i])){
                temp.push_back(user_id[i]);
            }
        }
        
        if(temp.size()==banned_id.size()){
            sort(temp.begin(),temp.end());
            for(auto c:temp){
                id+=c;
            }
            id_list.insert(id);
        }
    }while(next_permutation(user_id.begin(),user_id.end()));
    
    
   
    return id_list.size();
}
