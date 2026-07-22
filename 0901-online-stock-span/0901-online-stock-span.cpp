class StockSpanner {
    stack<pair<int,int>> st;
    int day;
public:
    StockSpanner() {
        day = 0;
    }
    
    int next(int price) {
        day++;
        int ans;
        while(!st.empty() && st.top().first <= price){
            st.pop();
        }
        if(st.empty()){
        st.push({price,day});
        return day;
        }else{
            ans = day- st.top().second;
            st.push({price,day});
        }
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */