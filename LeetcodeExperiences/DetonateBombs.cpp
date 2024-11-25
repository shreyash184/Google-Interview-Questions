class Solution {
private:

    void dfs(int s, vector<int>&vis, vector<int>adj[], int& cnt){
        vis[s] = 1;
        cnt++;

        for(auto child : adj[s]){
            if(!vis[child]){
                dfs(child, vis, adj, cnt);
            }
        }
    }

public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();

        vector<int>adj[n];

        for(int i=0;i<n;i++){

            int x1 = bombs[i][0];
            int y1 = bombs[i][1];
            long long r1 = bombs[i][2];
            long long r = r1*r1;

            for(int j=0;j<n;j++){

                if(i == j)continue;

                int x2 = bombs[j][0];
                int y2 = bombs[j][1];
                // int r2 = bombs[j][2];

                long long d1 = abs(x1-x2);
                long long d2 = abs(y1-y2);

                long long d = d1 * d1 + d2 * d2;
                

                if( d <= r){
                    adj[i].push_back(j);
                    // adj[j].push_back(i);
                }
            }
        }

        

        int maxBombs = 0;

        for(int i=0;i<n;i++){
            vector<int> vis(n, 0);
            int cnt = 0;
            dfs(i, vis, adj, cnt);
            maxBombs = max(maxBombs, cnt);
        }

        return maxBombs;
    }
};