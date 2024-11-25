#include <bits/stdc++.h>
using namespace std;


class TreeNodee{
public:
    string name;
    string value;
    vector<TreeNodee*> childs;

    TreeNodee(string name, string value) : name(name), value(value) {}
};


TreeNodee* mergeNodes(TreeNodee* root1, TreeNodee* root2){
    if(!root1) return root2;
    if(!root2) return root1;

    TreeNodee* mergedTree = new TreeNodee(root1->name, root2->value);

    map<string, TreeNodee*> store;

    for(auto child : root1->childs){
        store[child->name] = child;
    }

    for(auto child : root2->childs){
        if(store.find(child->name) != store.end()){
            mergedTree->childs.push_back(mergeNodes(store[child->name], child));
            store.erase(child->name);
        }else{
            mergedTree->childs.push_back(new TreeNodee(child->name, child->value));
        }
    }

    for(auto& entry : store){
        mergedTree->childs.push_back(entry.second);
    }

    return mergedTree;
}

// Print the merged tree

void printTree(TreeNodee* root, int depth  = 0){
    if(!root)return;
    cout<<string(depth*2, ' ')<<root->name << ": "<< root->value<<endl;

    for(TreeNodee* child : root->childs){
        printTree(child, depth+1);
    }
}

int main(){

   TreeNodee* T1 = new TreeNodee("T", "Hey");
    TreeNodee* A2 = new TreeNodee("A", "lambda");
    TreeNodee* B3 = new TreeNodee("B", "hello");
    TreeNodee* D3 = new TreeNodee("D", "guest");
    TreeNodee* E4 = new TreeNodee("E", "umbrella");
    TreeNodee* B2 = new TreeNodee("B", "how");
    TreeNodee* C2 = new TreeNodee("C", "are");
    TreeNodee* D2 = new TreeNodee("D", "hey");
    // TreeNodee* A22_1 = new TreeNodee("A", "you"); // Changed name to avoid confusion

    // Construct the tree hierarchy for root1
    D3->childs.push_back(E4);  // D3 has E4 as a child
    A2->childs.push_back(B3);  // A2 has B3 as a child
    A2->childs.push_back(D3);  // A2 has D3 as a child
    T1->childs.push_back(A2);  // T1 has A2 as a child
    T1->childs.push_back(B2);  // T1 has B2 as a child
    T1->childs.push_back(C2);  // T1 has C2 as a child
    T1->childs.push_back(D2);  // T1 has D2 as a child
    // T1->childs.push_back(A22_1); // T1 has A22_1 as a child

    // Construct root2
    TreeNodee* T21 = new TreeNodee("T", "approx");
    TreeNodee* B22 = new TreeNodee("B", "humble");
    TreeNodee* A2x2 = new TreeNodee("A", "theta");
    TreeNodee* C23 = new TreeNodee("C", "imp");
    TreeNodee* B23 = new TreeNodee("B", "hydrogen");
    TreeNodee* D22 = new TreeNodee("D", "oxygen");
    TreeNodee* A222 = new TreeNodee("A", "alpha");
    TreeNodee* X22 = new TreeNodee("X", "happy");

    // Construct the tree hierarchy for root2
    A2x2->childs.push_back(C23);  // A2x2 has C23 as a child
    A2x2->childs.push_back(B23);  // A2x2 has B23 as a child
    T21->childs.push_back(B22);   // T21 has B22 as a child
    T21->childs.push_back(A2x2);  // T21 has A2x2 as a child
    T21->childs.push_back(D22);   // T21 has D22 as a child
    T21->childs.push_back(A222);  // T21 has A222 as a child
    T21->childs.push_back(X22);   // T21 has X22 as a child
    cout<<flush;
    // Print tree 2
    printTree(T1);
    printTree(T21);
    
    TreeNodee* mergedTree = mergeNodes(T1, T21);
    printTree(mergedTree);

    return 0;
}


Time and space compexity is tricky part here 