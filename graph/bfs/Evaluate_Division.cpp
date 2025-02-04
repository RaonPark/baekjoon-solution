class Solution {
private:
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<string> > eq;
        vector<double> ans;

        for(auto equation: equations) {
            eq[equation[0]].emplace_back(equation[1]);
            eq[equation[1]].emplace_back(equation[0]);
        }

        for(auto query: queries) {
            if(eq[query[0]].size() != 0) {
                double res = find_answer(equations, eq, values, query);
                ans.emplace_back(res);
            } else {
                ans.emplace_back(-1.0);
            }
        }

        return ans;
    }

    double find_answer(vector<vector<string>> &equations, unordered_map<string, vector<string>> &eq, vector<double>& values, vector<string>& query) {
        queue<pair<string, double>> q; q.push({query[0], 1.0});
        map<string, bool> visited; visited[query[0]] = true;
        double result = -1.0;

        while(!q.empty()) {
            auto now = q.front(); q.pop();

            if(now.first == query[1]) {
                // cout << query[0] << ' ' << query[1] << ' ' << now.second << '\n';
                result = now.second;
                break;
            }

            for(auto next: eq[now.first]) {
                if(!visited[next]) {
                    visited[next] = true;
                    vector<string> vs; 
                    vs.emplace_back(now.first); vs.emplace_back(next);
                    
                    double v = 1.0;
                    if(find(equations.begin(), equations.end(), vs) != equations.end()) {
                        int valueIdx = find(equations.begin(), equations.end(), vs) - equations.begin();
                        v = values[valueIdx];
                    }

                    string temp = vs[0];
                    vs[0] = vs[1];
                    vs[1] = temp;

                    if(find(equations.begin(), equations.end(), vs) != equations.end()) {
                        int valueIdx = find(equations.begin(), equations.end(), vs) - equations.begin();
                        v = 1.0 / values[valueIdx];
                        // cout << query[0] << ' ' << query[1] << ' ' << now.second * v << '\n';
                    }
                    
                    q.push({next, now.second * v});
                    // cout << query[0] << ' ' << query[1] << ' ' << now.second * v << '\n';
                }
            }
        }

        return result;
    }
};
