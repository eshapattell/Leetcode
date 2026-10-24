class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] == x) {
            return x;
        }

        return parent[x] = find(parent[x]);
    }

    void merge(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);

        if (rootA == rootB) {
            return;
        }

        if (size[rootA] < size[rootB]) {
            swap(rootA, rootB);
        }

        parent[rootB] = rootA;
        size[rootA] += size[rootB];
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        DSU dsu(n);

        //email -> account index
        map<string, int> emailToIndex;


        //step 1 is merging account indices using common emails
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];

                if (emailToIndex.find(email) == emailToIndex.end()) {
                    emailToIndex[email] = i;
                } else {
                    dsu.merge(i, emailToIndex[email]);
                }
            }
        }

        //step 2 is finding ultimate parent index -> sorted emails
        map<int, set<string>> mergedEmails;

        for (auto& it : emailToIndex) {
            string email = it.first;
            int index = it.second;

            int root = dsu.find(index);
            mergedEmails[root].insert(email);
        }
        // step 3 is constructing the final answer
        vector<vector<string>> ans;

        for (auto& it : mergedEmails) {
            int root = it.first;

            vector<string> temp;
            temp.push_back(accounts[root][0]);

            for (auto& email : it.second) {
                temp.push_back(email);
            }

            ans.push_back(temp);
        }
        return ans;
    }
};




