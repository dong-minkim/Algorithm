#include <string>
#include <queue>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 1;
    //�⺻���� �켱���� ť�� ���������̴�.
    priority_queue<int> pq;
    queue<pair<int, int>>q;
    for (int i = 0; i < priorities.size(); i++) {
        pq.push(priorities[i]);
        q.push(make_pair(i, priorities[i]));
    }
    while (!q.empty()) {
        //�켱����ť top�� �� �� �����̴�.
        if (q.front().second == pq.top()) {
            if (q.front().first == location)
                return answer;
            else {
                answer++;
                q.pop();
                pq.pop();
            }
        }
        else {
            q.push(q.front());
            q.pop();
        }
    }
    return answer;
}