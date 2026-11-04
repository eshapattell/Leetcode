class Solution {
public:
    char findParent(char x, unordered_map<char, char>& parent) {
        if (x == parent[x])
            return x;

        return parent[x] = findParent(parent[x], parent);
    }

    void unionXY(char x_parent, char y_parent, unordered_map<char, char>& parent, unordered_map<char, int>& rank) {
        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[y_parent] = x_parent;
            rank[x_parent]++;
        }
    }

    bool equationsPossible(vector<string>& equations) {
        unordered_map<char, char> parent;
        unordered_map<char, int> rank;

        for (auto& equation : equations) {
            char x = equation[0];
            char y = equation[3];

            parent[x] = x;
            parent[y] = y;

            rank[x] = 0;
            rank[y] = 0;
        }

        for (auto& equation : equations) {
            char x = equation[0];
            char y = equation[3];
            char op = equation[1];

            if (op == '!')
                continue;

            char x_parent = findParent(x, parent);
            char y_parent = findParent(y, parent);

            if (x_parent != y_parent)
                unionXY(x_parent, y_parent, parent, rank);
        }

        for (auto& equation : equations) {
            char x = equation[0];
            char y = equation[3];
            char op = equation[1];

            if (op == '=')
                continue;

            char x_parent = findParent(x, parent);
            char y_parent = findParent(y, parent);

            if (x_parent == y_parent)
                return false;
        }

        return true;
    }
};