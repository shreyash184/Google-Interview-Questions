// Given map {X=>123, Y=456}
// Input: %X%_%Y%
// Output: 123_456
// Given map {USER=>admin, HOME=>/%USER%/home} Input: I am %USER% My home is %HOME% Output: I am admin My home is /admin/home
// USER= bob
// HOME= /home/%USER% should be substituted as : /home/bob ex2:
// home/ %USER% -> /home/bob
// Hello %USER% -> Hello bob!
// ex3:
// The user %USER% is at 50%% -> The user bob is at 50%


// This is my own code, so not sure what are the edge cases it might be failing
// While revising this question please try to test this code for multiple test cases !!


#include <bits/stdc++.h>
using namespace std;


vector<string> getVariables(string s){
    int n = s.length();
    vector<string> ans;
    int i = 0;

    while(i < n){
        // cout<<"inloop"<<endl;
        if(s[i] == '%'){
            i++;
            string tmp = "";
            while(s[i] != '%'){
                // cout<<"gathering variable"<<endl;
                tmp += s[i];
                i++;
            }
            ans.push_back(tmp);
        }
        i++;
    }
    return ans;
}

unordered_map<string, vector<string> > buildGraph(unordered_map<string, string> variables){
    unordered_map<string, vector<string> > graph;

    for(auto it : variables){
        string key = it.first;
        string value = it.second;

        vector<string>vars = getVariables(value);

        // for(auto x : vars){cout<<x<<endl;}

        for(auto i : vars){
            // cout<<key<<" "<<i<<endl;
            graph[i].push_back(key);
        }
    }

    return graph;
}

vector<string> topoSort(unordered_map<string, vector<string> > graph){
    unordered_map<string, int> indegree;

    for(auto it : graph){
        for(auto i : it.second){
            indegree[i]++;
        }
    }

    queue<string> q;

    for(auto it : graph){
        if(indegree[it.first] == 0){
            q.push(it.first);
        }
    }

    vector<string> topo;

    while(!q.empty()){
        string var = q.front();
        q.pop();

        topo.push_back(var);

        for(auto child : graph[var]){
            indegree[child]--;
            if(indegree[child] == 0){
                q.push(child);
            }
        }
    }

    return topo;
}

void replaceVariables(unordered_map<string, string> &mappings, string key){
    string value = mappings[key];
    int i=0;
    int n = value.length();
    string newValue = "";

    while(i < n){
        // cout<<"inloop"<<endl;
            if(value[i] == '%'){
                i++;
                string tmp = "";
                while(value[i] != '%'){
                    // cout<<"gathering variable"<<endl;
                    tmp += value[i];
                    i++;
                }
                i++;
                newValue += mappings[tmp];
            }else{
                newValue += value[i];
                i++;
            }
        mappings[key] = newValue;
    }
}

int main(){

    unordered_map<string, string> variables;
    // variables["X"] = "123";
    // variables["Y"] = "456";
    // variables["USER"] = "bob";
    // variables["HOME"] = "/home/%USER%";

    // USER=>admin, HOME=>/%MY%/home, MY=>"%USER%

    variables["USER"] = "admin";
    variables["HOME"] = "/%MY%/home";
    variables["MY"] = "%USER%";

    // For below example it is getting wrong output

    // variables["a"] = "x";
    // variables["b"] = "/%a%/xyc";
    // variables["c"] = "/xyz/%b%/a";
    // variables["d"] = "/%b%/%c%/dxy";

    // cout<<"testing"<<endl;

    unordered_map<string, vector<string> > graph = buildGraph(variables);

    // cout<<"testing"<<endl;

    vector<string> topo = topoSort(graph);
    // reverse(topo.begin(), topo.end());

    // cout<<"testing"<<endl;

    // cout<<topo.size()<<endl;

    // for(auto i : topo){
    //     cout<<i<<" ";
    // }
    // cout<<endl;

    for(auto s : topo){
        replaceVariables(variables, s);
    }

    // for(auto it : variables){
    //     cout<<it.first<<" "<<it.second<<endl;
    // }

    string input = "I am %USER% My home is %HOME%";
    int n = input.length();
    int i = 0;
    string newValue = "";

    while(i < n){
        if(input[i] == '%'){
            string tmp = "";
            i++;
            while(input[i] != '%'){
                tmp += input[i];
                i++;
            }
            i++;
            newValue += variables[tmp];
        }else{
            newValue += input[i];
            i++;
        }
    }

    cout<<newValue<<endl;

    return 0;
}