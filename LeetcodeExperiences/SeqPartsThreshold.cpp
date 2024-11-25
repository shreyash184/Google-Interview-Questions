// You are given a sequence of positive integers sequence. 
// Your goal is to divide this sequence into parts non-empty contiguous subsequences. 
// Among these parts subsequences, the number of subsequences whose sum of elements is at least threshold will be called the score. 
// Find the maximum score.


// sequence = [1, 4, 2, 8]
// parts = 3
// threshold = 6

// Output:
// 2


// sequence = [1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
// parts = 5
// threshold = 2

// Output:
// 5


// Brute Force approach

#include <bits/stdc++.h>
using namespace std;

void partitionHelper(vector<int>&sequence, int parts, int start, vector<vector<int> >&currPartitions, int& maxScore, int threshold){
    if(currPartitions.size() == parts-1){
        // Include the last partition
        currPartitions.push_back(vector<int>(sequence.begin() + start, sequence.end()));
        int score = 0;
        // Check the current score from this possible way of partitioning
        for(auto currPartition : currPartitions){
            int sum = 0;

            for(auto value : currPartition){
                sum += value;
            }

            if(sum >= threshold){
                score++;
            }
        }
        maxScore = max(score, maxScore);
        currPartitions.pop_back();
        return;
    }
   
    for(int i = start+1; i<sequence.size(); i++){
        currPartitions.push_back(vector<int>(sequence.begin() + start, sequence.begin() + i));
        partitionHelper(sequence, parts, i, currPartitions, maxScore, threshold);
        currPartitions.pop_back();
    }
}

int getMaxScore(vector<int>&sequence, int parts, int threshold){
    vector<vector<int> > currPartitions;
    int maxScore = 0;
    partitionHelper(sequence, parts, 0, currPartitions, maxScore, threshold);
    return maxScore;
}

int main(){

    vector<int>sequence; // {1, 4, 2, 8}
    sequence.push_back(1);
    sequence.push_back(4);
    sequence.push_back(2);
    sequence.push_back(8);
    int parts = 3; // 3
    int threshold = 6; // 6

    cout<<getMaxScore(sequence, parts, threshold)<<endl;
}

Time Complexity - O(n^k * k) k ->n is divided into k parts !!

Below code is not solved please go through when you revise this !!


// #include <iostream>
// #include <vector>
// #include <numeric>
// using namespace std;

// int maxScore(const vector<int>& sequence, int parts, int threshold) {
//     int n = sequence.size();
//     // Prefix sums array
//     vector<int> prefix(n + 1, 0);
//     for (int i = 1; i <= n; i++) {
//         prefix[i] = prefix[i - 1] + sequence[i - 1];
//     }

//     // DP table
//     vector<vector<int>> dp(parts + 1, vector<int>(n + 1, 0));

//     for (int p = 1; p <= parts; p++) {
//         for (int i = p; i <= n; i++) {
//             // Iterate over all possible previous partitions
//             for (int j = p - 1; j < i; j++) {
//                 int sum = prefix[i] - prefix[j]; // Sum of subsequence from j to i
//                 dp[p][i] = max(dp[p][i], dp[p - 1][j] + (sum >= threshold ? 1 : 0));
//             }
//         }
//     }

//     return dp[parts][n];
// }

// int main() {
//     vector<int> sequence1 = {1, 4, 2, 8};
//     int parts1 = 3;
//     int threshold1 = 6;
//     cout << "Max Score: " << maxScore(sequence1, parts1, threshold1) << endl; // Expected output: 2

//     vector<int> sequence2 = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
//     int parts2 = 5;
//     int threshold2 = 2;
//     cout << "Max Score: " << maxScore(sequence2, parts2, threshold2) << endl; // Expected output: 5

//     return 0;
// }
