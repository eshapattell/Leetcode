class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int,int>>q;
        int time=0;

        for(int i=0;i< tickets.size();i++){
            q.push({tickets[i],i});
        }
        while(!q.empty()){
            auto person = q.front();
            q.pop();
            person.first--;
            time++;
            if(person.second ==k && person.first==0){
                return time;
            }
            if(person.first >0){
                q.push(person);
            }
        }
        return time;
    }
};