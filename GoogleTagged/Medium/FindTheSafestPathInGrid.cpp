class Solution {
public:

    int drow[4] = {-1, 0, 1, 0};
    int dcol[4] = {0, 1, 0, -1};

    bool isValid(int target, vector<vector<int>>&dist){
        // more than or equal to target path is allowed
        // but not less than
        int noOfRows = dist.size();
        int noOfCols = dist[0].size();

        // start from left top to right bottom
        queue<pair<int, int>> que;
        vector<vector<int>> visited(noOfRows, vector<int>(noOfCols, 0));

        if(dist[0][0] < target){
            return false;
        }

        que.push({0, 0});
        visited[0][0] = 1;

        while(!que.empty()){
            int row = que.front().first;
            int col = que.front().second;

            que.pop();

            if(row == noOfRows-1 and col == noOfCols-1){
                return true;
            }

            for(int index = 0; index < 4; index++){
                int newRow = row + drow[index];
                int newCol = col + dcol[index];

                if(newRow >= 0 and newRow < noOfRows and newCol >= 0 and newCol < noOfCols and !visited[newRow][newCol] and target <= dist[newRow][newCol]){
                    visited[newRow][newCol] = 1;
                    que.push({newRow, newCol});
                }
            }
        }
        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int noOfRows = grid.size();
        int noOfCols = grid[0].size();

        // Find the shortest dist of each 0 from any nearest 1
        // We will use multisource bfs here

        queue<pair<int, int>> que;
        vector<vector<int>> visited(noOfRows, vector<int>(noOfCols, 0));
        vector<vector<int>> dist(noOfRows, vector<int>(noOfCols, 0));

        for(int row = 0; row < noOfRows; row++){
            for(int col = 0; col < noOfCols; col++){
                if(grid[row][col] == 1){
                    visited[row][col] = 1;
                    que.push({row, col});
                }
            }
        }

        int len = 0;

        while(!que.empty()){
            int size = que.size();

            while(size--){
                int currRow = que.front().first;
                int currCol = que.front().second;

                que.pop();

                for(int index = 0; index < 4; index++){
                    int newRow = currRow + drow[index];
                    int newCol = currCol + dcol[index];

                    if(newRow >= 0 and newRow < noOfRows and newCol >= 0 and newCol < noOfCols and grid[newRow][newCol] == 0 and !visited[newRow][newCol]){
                        visited[newRow][newCol] = 1;
                        que.push({newRow, newCol});
                        dist[newRow][newCol] = dist[currRow][currCol] + 1;
                    }
                }
            }
            len++;
        }

        int low = 0;
        int high = len;
        int ans = 0;

        while(low <= high){
            int mid = (low + high)/2;

            if(isValid(mid, dist)){
                ans = mid;
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }

        return ans;
    }
};