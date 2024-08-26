#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    // 2 con tro

    node *left;  // luu dia chi cua node con ben trai
    node *right; // luu dia chi cua node con ben phai
    node(int x) {
        data = x;
        left = right = NULL; // luc dau chua co nen cap phat la NULL
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

bool check(node *root) {
    if(root == NULL) return true;
    if(root->left == NULL && root->right == NULL) return true;
    if(root->left != NULL && root->right != NULL)
        return check(root->left) && check(root->right);
    else 
        return false;
}

int main() {
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
    cout << check(root);
} 
