#include <string>
#include <vector>
#include <climits>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer(2);
    int start = 0;
    long long current_sum = 0;
    int minLen = INT_MAX;

    for (int end = 0; end < sequence.size(); end++) {
        current_sum += sequence[end];

        while (current_sum >= k) {
            if (current_sum == k) {
                int currentLen = end - start + 1;
                if (currentLen < minLen) {
                    minLen = currentLen;
                    answer[0] = start;
                    answer[1] = end;
                }
            }
            current_sum -= sequence[start];
            start++;
        }
    }

    return answer;
}
