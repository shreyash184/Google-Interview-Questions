First 0/1 knapsack question  -

Follow ups - 

1. What happen if the weights are fractional ?
2. What happens if the profit of each of the item is either 1 or 2?


weight[] = {1, 2, 4, 5}
value[] = {5, 4, 8, 6}
maxWeight = 5

// So currently i am thinking to apply dynamic programming based on take / not take strategy !!


int getMaxValue(int index, vector<int>& weight, vector<int>& value, int maxWeight){
    if(index == 0){
        if(weight[index] <= maxWeight){
            return value[index];
        }
        return 0;
    }
    int take = 0;
    int notTake = 0;
    // take 
    if(weight[index] <= maxWeight){
        take = value[index] + getMaxValue(index-1, weight, value, maxWeight-weight[index]);
    }   

    // not take
    notTake = getMaxValue(index-1, weight, value, maxWeight);

    return max(take, notTake);
}

TC - O(2^n)
SC - O(n)

memoize and then tabulation !!!


First follow up - Fractional knapsack !!

Second Follw up - comments suggested separately handle 1 and 2 but (1, 5) (1, 1, 1, 1, 1, 1, 1) k = 7 this test case fails with
that approach, So still looking for solutions !!!
