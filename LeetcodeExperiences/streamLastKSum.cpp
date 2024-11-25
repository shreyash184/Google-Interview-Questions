// Q1: Given a stream of numbers coming, find the sum of the last k numbers. (k is given beforehand)

// Follow-up: sum of last k - (sum to top n%tile), i.e. subtract the top n%tile from the sum.

// a1 a2 a3 | x y a b x  | d f s d | d g d --> we will store this in a vector

// given k


// brute force solution that is comming to my mind currently is 



#include <bits/stdc++.h>
using namespace std;


class StreamOperations{
public:

    vector<int> store;
    vector<int> prefixSum;
    
    StreamOperations(){
        prefixSum.push_back(0);
    }

    void addElement(int value){
        store.push_back(value);
        prefixSum.push_back(prefixSum.back() + value);
    }

    int sumOfLastKValues(int k){
        int sum = 0;
        int firstIndex = store.size() - k;
        int lastIndex = store.size();
        sum += prefixSum[lastIndex] - prefixSum[firstIndex];
        // cout<<firstIndex<<" "<<lastIndex<<endl;

        // for(auto it : prefixSum)cout<<it<<" ";
        // cout<<endl; 
        return sum;
    }
};

int main(){


    StreamOperations streams;

    streams.addElement(1);
    streams.addElement(2);
    streams.addElement(343);
    streams.addElement(4);
    cout<<streams.sumOfLastKValues(2)<<endl;
    streams.addElement(1);
    streams.addElement(243);
    streams.addElement(34);
    streams.addElement(42);
    cout<<streams.sumOfLastKValues(5)<<endl;

    return 0;
}


// A better solution will be to use queue with k size for first question.

