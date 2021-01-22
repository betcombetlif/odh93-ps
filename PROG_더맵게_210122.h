#include <string>
#include <vector>
#include <queue>
using namespace std;
int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue <int> pq;
    for(int i=0; i<scoville.size(); i++)
        pq.push(-scoville[i]);
    while(-pq.top() < K && pq.size()!=1){
        int one = -pq.top();
        pq.pop();
        int two = -pq.top();
        pq.pop();
        pq.push(-(one+two*2));
        answer+=1;
    }
    if(-pq.top() <K)
        answer = -1;
    return answer;
}
