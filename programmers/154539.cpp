#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(),0);
    stack<pair<int,int>> st;
    
    st.push({numbers[0], 0});
        
    for(int i=1;i<numbers.size();i++){
        while(!st.empty() && (numbers[i]>st.top().first)){
            auto [x,y] = st.top(); st.pop();
            answer[y] = numbers[i];
            }
        st.push({numbers[i], i});
    }
    while(!st.empty()){
        auto [x,y] = st.top(); st.pop();
        answer[y] = -1;
    }
    return answer;
}