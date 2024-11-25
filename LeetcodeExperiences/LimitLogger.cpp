// Clarifying questions 

// 1. can there be multiple questions at same timestamp ? --> Yes
// 2. Should I consider the message are comming in order of timestamo ? --> yes {I guess if not then we need sorting}



// Brute force approach - 

class Logger {
public:

    queue<pair<string, int>> logStore;
    set<string> logValidator;

    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        while(!logStore.empty() and timestamp >= logStore.front().second + 10){
            logValidator.erase(logStore.front().first);
            logStore.pop();
        }

        if(logValidator.find(message) == logValidator.end()){
            logValidator.insert(message);
            logStore.push({message, timestamp});
            return true;
        }
        return false;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */

//  if the message are not in chronological order of timestamp, then we would have to 
//  iterate over the queue to remove the expired msg, but now we can able to stop early

// TC - O(N) and SC - O(2N)

// Can we optimize above approach ?

// Yes we can use map instead of queue and set

class Logger {
public:
    unordered_map<string, int> logStore;

    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if(logStore.find(message) == logStore.end()){
            logStore[message] = timestamp;
            return true;
        }
            
        if(logStore[message] + 10 <= timestamp){
            logStore[message] = timestamp;
            return true;
        }
            
        return false;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */

//  TC - O(1) avg
//  SC - O(M) size of map
