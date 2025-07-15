#include <bits/stdc++.h>
using namespace std;
class StockSpanner {
    /*we are trying to maintain a monotonic stack of decreasing order. when we pop
    and find top is greater than price then all the rest elements will also be
    greater. cnt is to keep track of it's span. if an element is removing another
    element then the sapn of the removing el will be added to the span of current
    element*/
    stack<pair<int,int>> st;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int cnt=1;
        while(!st.empty() && price>=st.top().first){
            cnt+=st.top().second;
            st.pop();
        }
        st.push({price,cnt});
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */