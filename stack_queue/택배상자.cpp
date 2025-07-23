#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    queue<int> box;
    stack<int> chest;

    for (int i = 1; i <= order.size(); i++) {
        box.push(i);
    }

    int order_idx = 0;

    while (order_idx < order.size()) {
        int target_item = order[order_idx];

        if (!box.empty() && box.front() == target_item) {
            box.pop();
            answer++;
            order_idx++;
            continue;
        }

        if (!chest.empty() && chest.top() == target_item) {
            chest.pop();
            answer++;
            order_idx++;
            continue;
        }

        if (!box.empty()) {
            chest.push(box.front());
            box.pop();
        } else {
            break;
        }
    }

    return answer;
}
