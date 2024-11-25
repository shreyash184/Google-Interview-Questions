/**
For a rooted tree with any arbitary number of children for each node,
not necessarily n-ary tree.

Remove all the leaf nodes, and store them in a list, this would create
new leaf nodes. Repeat untill all the nodes are removed

Conditions : Freshly created leaf nodes(node whose children are removed)
should not be removed just after its children are removed, unless
there's no other option for us, then we can remove it
 */



#include <bits/stdc++.h>
using namespace std;

class Tree{
    public:
        int val;
        Tree* left;
        Tree* right;

        Tree(int val){
            this->val = val;
            this->left = NULL;
            this->right = NULL;
        }
};

class Solution{
    private:

        map<int, vector<int> > mp;

        int dfs(Tree* root, int layer){
            if(!root){
                return layer;
            }

            int left = dfs(root->left, layer);
            int right = dfs(root->right, layer);
        
            layer = max(left, right);
            mp[layer].push_back(root->val);

            return layer+1;
        }

    public:
        vector< vector< int > > getLeaves(Tree* root){
            mp.clear();
            dfs(root, 0);

            vector< vector< int > > ans;

            for(auto it : mp){
                ans.push_back(it.second);
            }

            return ans;
        }
};

int main(){

    Tree* root = new Tree(1);

    root->left = new Tree(2);
    root->right = new Tree(3);
    root->left->left = new  Tree(4);
    root->left->right = new  Tree(5);
    root->left->right->left = new Tree(6);
    root->right->left = new Tree(7);

    Solution solution;

    vector< vector< int > > ans = solution.getLeaves(root);

    for(auto v : ans){
        for(auto element : v){
            cout<<element<< " ";
        }
        cout<<endl;
    }

    return 0;
}