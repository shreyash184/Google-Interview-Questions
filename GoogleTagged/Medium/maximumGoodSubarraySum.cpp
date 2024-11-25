// What did you learn from this question 
// How to use prefix Sum in o(n)
// How to handle duplicate to get maximum sum.

class Solution {
public:
    // long long maximumSubarraySum(vector<int>& nums, int k) {
    //     int n = nums.size();

    //     long long maxSum = INT_MIN;

    //     vector<long long>prefixSum(n+1, 0);

    //     for(int i=1;i<n+1;i++){
    //         prefixSum[i] = nums[i-1] + prefixSum[i-1];
    //         // cout<<prefixSum[i]<<" ";
    //     }

    //     for(int i=0;i<n;i++){
    //         for(int j=i;j<n;j++){
    //             if(abs(nums[i] - nums[j]) == k){
    //                 // We can use prefix sum here to reduce this loop
    //                 long long sum = prefixSum[j+1] - prefixSum[i];
    //                 if(maxSum < sum){
    //                     maxSum = sum;
    //                 }
    //             }
    //         }
    //     }

    //     if(maxSum == INT_MIN)return 0;

    //     return maxSum;
    // }

    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        long long maxSum = LLONG_MIN;
        unordered_map<long long, int> mp;
        vector<long long>prefixSum;
        prefixSum.push_back(0);
        
        // for(int i=1;i<n+1;i++){
        //     prefixSum[i] = nums[i-1] + prefixSum[i-1];
        // }

        for(int i=0;i<n;i++){
            prefixSum.push_back(prefixSum.back() + nums[i]);
            if(mp.find(nums[i] - k) != mp.end()){
                maxSum = max(maxSum, prefixSum[i+1] - prefixSum[mp[nums[i] - k]]);
            }
            if(mp.find(nums[i] + k) != mp.end()){
                maxSum = max(maxSum, prefixSum[i+1] - prefixSum[mp[nums[i] + k]]);
            }
            if(mp.find(nums[i]) != mp.end()){
                if(prefixSum[i+1] >= prefixSum[mp[nums[i]]+1])continue;
            }
            mp[nums[i]] = i;
        }

        if(maxSum == LLONG_MIN)return 0;

        return maxSum;
    }
};