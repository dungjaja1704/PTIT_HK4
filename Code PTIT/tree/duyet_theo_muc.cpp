#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
    node(int x) {
        data = x;
        left = right = NULL;
    }
};

void makeRoot (node *root, int u, int v, char c) {
    if(c == 'L') root->left = new node(v);
    else root->right = new node(v);
}

void insertNode (node *root, int u, int v, char c) {
    if (root == NULL) return;
    if (root->data == u) {
        makeRoot (root, u, v, c);
    }
    else {
        insertNode(root->left, u, v, c);
        insertNode(root->right, u, v, c);
    }
}

void leverOrder(node *root) {
    queue<node*> q;
    q.push(root);
    while(!q.empty()) {
        node *tmp = q.front();
        q.pop();
        cout << tmp->data << ' ';
        if(tmp->left != NULL){
            q.push(tmp->left);
        }
        if(tmp->right != NULL){
            q.push(tmp->right);
        }
    }
}

int main() {
    int t; cin >> t;
    while(t--) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        node *root = NULL;
        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            int u, v; char c;
            cin >> u >> v >> c;
            if(root == NULL) {
                root = new node(u);
                makeRoot(root, u, v, c);
            }
            else {
                insertNode(root, u, v, c);
            }
        }
        leverOrder(root);
        cout << endl;
    }
} 
