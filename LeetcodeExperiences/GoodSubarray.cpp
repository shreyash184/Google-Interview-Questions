Given an array, any subarray is special if it forms an AP with common difference of 1 or -1. Give sum of all such subarrays.

Ex: arr = [2,3,4,5,6,5]

So ans should be sum of all the good subarrays which are:]

[2], [3], [4], [5], [6], [5]

[2,3], [3,4], [4,5], [5,6], [6,5]

[2,3,4], [3,4,5], [4,5,6]

[2,3,4,5], [3,4,5,6]

[2,3,4,5,6]

A more precise explanation of above problem - 
We call an array arr of length n consecutive if one of the following holds:

arr[i] - arr[i - 1] == 1 for all 1 <= i < n.
arr[i] - arr[i - 1] == -1 for all 1 <= i < n.
The value of an array is the sum of its elements.

For example, [3, 4, 5] is a consecutive array of value 12 and [9, 8] is another of value 17. While [3, 4, 3] and [8, 6] are not consecutive.

Given an array of integers nums, return the sum of the values of all consecutive 
subarrays
.

Since the answer may be very large, return it modulo 109 + 7.

Note that an array of length 1 is also considered consecutive.

Clarifying questions -

are we considering the single element as consecutive elements - yes

1 2 3

1
2
3
1 2
2 3
1 2 3

20

3 4 5 4

3 4 5
    3 
    4
    5
    3 4
    4 5
    3 4 5
 - 40

5 4
    5
    4
    5 4

- 18

40 + 18 - 5 = 53

3 
 = 3

3 4
3 + 2 * 4 = 11

3
4
3 4 = 3 + 4 + 3 + 4 = 14

sum1 += cnt1 * nums[i];
sum2 += cnt2 * nums[i];


res = res + sum1+sum2 - nums[i]

return res



int getGoodSum(vector<int>& nums){
    int sum1 = nums[0];
    int sum2 = nums[0];
    int countOfIncreasingConsecutive = 1;
    int countOfDecreasingConsecutive = 1;

    int sumOfConsecutiveSubarray = nums[0];


    for(int iter = 1; iter < nums.size(); iter++){
        if(nums[iter] - nums[iter-1] != 1){
            sum1 = 0;
            countOfIncreasingConsecutive = 0;
        }

        if(nums[iter] - nums[iter-1] != -1){
            sum2 = 0;
            countOfDecreasingConsecutive = 0;
        }

        countOfIncreasingConsecutive++;
        countOfDecreasingConsecutive++;

        sum1 = sum1 + countOfIncreasingConsecutive * nums[iter];
        sum2 = sum2 + countOfDecreasingConsecutive * nums[iter];

        sumOfConsecutiveSubarray = sumOfConsecutiveSubarray + sum1 + sum2 - nums[iter];
    }

    return sumOfConsecutiveSubarray;
}

1 2 3

sum1 = 1, sum2 = 1;
c1 = 1, c2 =1;

sum1 = 1, sum2 = 0
c1 = 2, c2 = 1;

sum1 = 1 + 2 * 2 = 5
sum2 = 0 + 1 * 2 = 2;

ans = 1 + 5 + 2 - 2 = 6

sum1 = 5, sum2 = 0;
c1 = 3, c2 = 1;

sum1 = 5 + 3 * 3 = 14
sum2 = 0 + 1 * 3 = 3;

ans = 6 + 14 + 3 - 3 = 20

TC - O(n)
SC - O(1)
