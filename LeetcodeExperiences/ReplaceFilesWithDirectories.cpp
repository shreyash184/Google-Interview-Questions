// Solve this problem before jumping to this problem
// https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/

// Actuall Question 
// you are given a complete list of directories and files in the file system, and then a subset of files. Return an augmented list of the subset, where if all files in a directory are listed in the subset, replace those file names with the directory name.

// Example input & output:
// allFiles = [
// "a/b/c/d.txt",
// "a/b/c/e.txt",
// "a/b/b.txt",
// "a/b/e.txt",
// "b/c/d.txt"
// ]

// subsetFiles = [
// "a/b/c/d.txt",
// "a/b/c/e.txt",
// "a/b/b.txt",
// "b/c/d.txt"
// ]

// output=[
// "a/b/c",
// "a/b/b.txt",
// "b"
// ]

// In this question try to visualize the scenario, It will be easy to understand, please look at below
// and try to play with the test cases

// all_files = {"a/b.txt", "b/c.txt", "b/d.txt", "c/e.txt", "c/f/a.txt", "c/f/b.txt", "c/g.txt", "d/a/b.txt"};
// selected_files = {"b/c.txt", "b/d.txt", "c/e.txt", "c/f/a.txt", "c/f/b.txt", "d/a/b.txt"};


// root
//  ├── a
//  │   └── b.txt
//  ├── b
//  │   ├── c.txt
//  │   └── d.txt
//  ├── c
//  │   ├── e.txt
//  │   ├── f
//  │   │   ├── a.txt
//  │   │   └── b.txt
//  │   └── g.txt
//  └── d
//      └── a
//          └── b.txt

// This is tricky problem to understand at first but good problem to learn the trie in depth
#include <bits/stdc++.h>
using namespace std;

class Node{

public:

    unordered_map<string, Node*> childs;
    bool file;
    int childCount;

    Node(){
        file = false;
        childCount = 0;
    }

    bool containsKey(string key){
        return childs.count(key);
    }

    Node* get(string key){
        return childs[key];
    }

    void put(string key){
        childs[key] = new Node();
    }

    bool isFile(){
        return file;
    }

    void setFile(){
        file = true;
    }
};

class Trie{
private:

    Node* root;

public:

    Trie(){
        root = new Node();
    }

    void insert(vector<string> words){
        Node* node = root;

        for(int iter = 0; iter < words.size(); iter++){
            node->childCount++;

            if(!node->containsKey(words[iter])){
                node->put(words[iter]);
            }
            node = node->get(words[iter]);
        }
        node->setFile();
    }

    string getPath(vector<string> words){
        Node* node = root;

        string compressedPath = "";

        for(int iter = 0; iter < words.size(); iter++){
            node = node->get(words[iter]);

            if(node->childCount == 0 or node->isFile()){
                compressedPath += words[iter];
                return compressedPath;
            }

            compressedPath += words[iter] + '/';
        }

        return "";
    }

    void decrementChildCount(vector<string> words){
        Node* node = root;

        for(int iter = 0; iter < words.size(); iter++){
            if(!node->containsKey(words[iter])){
                return;
            }
            node->childCount--;
            node = node->get(words[iter]);
        }
    }

     void search (vector<string> words){ 
        Node *node = root;
        for(auto w : words){
            if(!node->childs.count(w)){
                return;
            }
            node = node->get(w);
            cout<<w<<":"<<node->childCount<<"\n";
        }
    }
};

vector<string> splitPath(const string &path) {
    vector<string> result;
    string currentPart;
    
    for (char c : path) {
        if (c == '/') {
            if (!currentPart.empty()) {
                result.push_back(currentPart);
                currentPart.clear();
            }
        } else {
            currentPart += c;
        }
    }
    
    // Add the last part if it's not empty
    if (!currentPart.empty()) {
        result.push_back(currentPart);
    }

    return result;
}

int main(){
    vector<string>result;
    vector<string> all_files; 

    all_files.push_back("a/b.txt");
    all_files.push_back("b/c.txt");
    all_files.push_back("b/d.txt");
    all_files.push_back("c/e.txt");
    all_files.push_back("c/f/a.txt");
    all_files.push_back("c/f/b.txt");
    all_files.push_back("c/g.txt");
    all_files.push_back("d/a/b.txt");
    
    vector<string> selected_files;
    
    selected_files.push_back("b/c.txt");
    selected_files.push_back("b/d.txt");
    selected_files.push_back("c/e.txt");
    selected_files.push_back("c/f/a.txt");
    selected_files.push_back("c/f/b.txt");
    selected_files.push_back("d/a/b.txt");
    
    Trie *trie = new Trie();

    // for(auto i : splitPath("d/a/b.txt")){
    //     cout<<i<<" ";
    // }
    // cout<<endl;

    for(auto path : all_files){
        trie->insert(splitPath(path));
        // trie->search(splitPath(path));
    }
    // cout<<"-------------------------"<<endl;

    for(auto path : selected_files){
        trie->decrementChildCount(splitPath(path));
        // trie->search(splitPath(path));
    }

   set<string> uniquePaths;
//    cout<<"ans==============="<<endl;

    for(auto path : selected_files){
        string findPath = trie->getPath(splitPath(path));
        uniquePaths.insert(findPath);
    }

    for (const auto& path : uniquePaths) {
        cout << path << endl;
    }
    // cout<<"Testing"<<endl;
}
