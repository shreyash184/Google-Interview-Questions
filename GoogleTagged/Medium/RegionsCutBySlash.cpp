class Solution {
private:

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    void dfs(vector<vector<int>>&mat, int i, int j, int n){
        mat[i][j] = 1;

        for(int t=0;t<4;t++){
            int x = i + dx[t];
            int y = j + dy[t];

            if(x >= 0 && x < n && y >= 0 && y < n && mat[x][y] == 0){
                dfs(mat, x, y, n);
            }
        }
    }

    int getCc(vector<vector<int>>& mat){
        int n = mat.size();
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] == 0){
                    dfs(mat, i, j, n);
                    cnt++;
                }
            }
        }

        return cnt;
    }

public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size() * 3;

        vector<vector<int>> mat(n, vector<int>(n, 0));

        for(int i=0;i<grid.size();i++){
            string s = grid[i];
            for(int j=0;j<s.length();j++){
                int x = i*3;
                int y = j*3;

                if(s[j] == '/'){
                    mat[x+2][y] = 1;
                    mat[x+1][y+1] = 1;
                    mat[x][y+2] = 1;
                }else if(s[j] == '\\' ){
                    mat[x][y] = 1;
                    mat[x+1][y+1] = 1; 
                    mat[x+2][y+2] = 1;
                }
            }
        }

        return getCc(mat);
    }
};