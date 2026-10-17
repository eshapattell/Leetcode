static const int _ = [](){ios_base::sync_with_stdio(false);cin.tie(NULL);return 0;}();

class Solution {
    vector<int> par;
    int find(int x) { return par[x]==x ? x : par[x]=find(par[x]); }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size(); par.resize(n); iota(par.begin(),par.end(),0);
        unordered_map<string,int> eid;
        for (int i=0;i<n;++i)
            for (int j=1;j<(int)accounts[i].size();++j) {
                if (eid.count(accounts[i][j])) par[find(i)]=find(eid[accounts[i][j]]);
                else eid[accounts[i][j]]=i;
            }
        unordered_map<int,set<string>> merged;
        for (int i=0;i<n;++i)
            for (int j=1;j<(int)accounts[i].size();++j)
                merged[find(i)].insert(accounts[i][j]);
        vector<vector<string>> res;
        for (auto&[root,emails]:merged) {
            vector<string> acc={accounts[root][0]};
            for (auto&e:emails) acc.push_back(e);
            res.push_back(acc);
        }
        return res;
    }
};