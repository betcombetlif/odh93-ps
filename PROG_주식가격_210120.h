#include <string>
#include <vector>
using namespace std;
vector<int> solution(vector<int> prices) {
    vector<int> answer;
    answer.resize(prices.size());
    vector <int> v;
    for(int i=0; i<prices.size(); i++){
        if(v.size()==0)
            v.push_back(i);
        else{
            while(v.size()!=0 && prices[i] < prices[v.back()]){
                answer[v.back()] = i-v.back();
                v.pop_back();
            }
            v.push_back(i);
        }
    }
    while(v.size()!=0){
        answer[v.back()] = prices.size()-1-v.back();
        v.pop_back();
    }
    return answer;
}
