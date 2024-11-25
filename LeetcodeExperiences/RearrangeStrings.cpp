
// A number of students are taking exams in a room. Students sitting adjacent to each other and taking the same exam can cheat. Arrange the students so that cheating opportunities are minimized. I was free to choose input format.

// I chose the input to be a list of length n, denoting n students. The element at index i would indicate the exam student i is taking.
// For example, [1,2,3,1,2,2] would mean:

// Student 0 is taking exam 1
// Student 1 is taking exam 2
// Student 2 is taking exam 3
// Student 3 is taking exam 1
// Student 4 is taking exam 2
// Student 5 is taking exam 2
// Output would be a list with the students re-arranged. An acceptable output for the above case would be [1,2,3,2,1,2].

class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();

        priority_queue<pair<int, char>> pq;

        unordered_map<char, int>mp;

        for(char c : s){
            mp[c]++;
        }

        for(auto it : mp){
            pq.push({it.second, it.first});
        }

        string ans = "";
        char lastchar = '/';

        while(!pq.empty()){

            if(pq.size() == 1 && pq.top().first > 1){
                return "";
            }

            pair<int,char> tmp = {-1, '/'};
            pair<int, char> tmp1 = {-1, '/'};

            if(pq.top().second == lastchar){
                tmp = pq.top();
                pq.pop();
                
            }

            int count = pq.top().first;
            char onHold = pq.top().second;

                // cout<<onHold<<endl;

            pq.pop();

            ans += onHold;
            count--;

            lastchar = onHold;

            if(count!=0){
                pq.push({count, onHold});
            }

            if(tmp != tmp1){
                pq.push(tmp);
            }
            
        }

        return ans;

    }
};