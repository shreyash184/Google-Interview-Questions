In a city, there is a footpath constructed using blocks of different colors. There can be contiguous blocks of same color as well which makes the footpath beautiful
A chief guest is going to visit the city and the city department wants to make the most beautiful footpath. Beauty value of the footpath is the largest number of continuous blocks painted with chief guest's favorite color.
You are given a positive number n (number of blocks in footpath) and number k (number of available colors for blocks). 
Each block can be painted with exactly one of the given colors (block_colors [1-1] is the color value of ith block, i starting Chief guest's favorite color is c (1 <= c <= k).
Warm-up question: Find the beauty value of the footpath. 18 Example: n=10 k=6 block_colors= (6, 5, 2, 1, 2, 2, 3, 4, 5, 2) c-2 In this case, the beauty value is 2.

FOLLOWUP: queries ka array c_q = [2,3,6,1, 7] 

Followup :  
m is given maximum paint operation with favorite color c that you can do blockcolors.

the operation should be in a way to maximise the length of continous blocks or beautiful path for the color c


int getBeauty(int noOfBlocks, int totalColorsAvailable, vector<int> &colors, int favColor){
    int len = colors.size();

    int left = 0, right = 0;
    int maxBeauty = 0;

    while(right < len){
        while(colors[right] == favColor){
            maxBeauty = max(maxBeauty, right-left+1);
            right++;
        }

        right++;
        left = right;
    }

    return maxBeauty;
}

TC - O(N)
SC - O(1)


FIRST FOLLOW UP - 
n=10 k=6 block_colors= (6, 5, 2, 1, 2, 2, 3, 4, 5, 2)
[2,3,6,1, 7]

vector<int> getBeauty(int noOfBlocks, int totalColorsAvailable, vector<int> &colors, vector<int>favColors){
    int len = colors.size();

    int left = 0, right = 0;
    vector<int> ans;
    unordered_map<int, int> colorStore;

    while(right < len){
        int currColor = colors[right];
        int beauty = 0;
        while(colors[right] == currColor){
            beauty = max(beauty, right-left+1);
            right++;
        }

        colorStore[currColor] = max(beauty, colorStore[currColor]);

        // right++;
        left = right;
    }

    for(auto color : favColors){
        ans.push_back(colorStore[color]);
    }    

    return ans;
}

TC - O(N)
SC - O(N)




