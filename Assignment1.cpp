#include<iostream>
#include<climits>
using namespace std;
class TreeNode{
public:
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int val){
        this->val = val;
        left = right = NULL;
    }
};
void Display(TreeNode *root){
    if(root == NULL) return;
    cout<<root->val<<" ";
    Display(root->left);
    Display(root->right);
}
//Q 1-> Find the product of all values in Binary Tree
int productTree(TreeNode *root){
    if(root == NULL) return 1;
    return (root->val)*productTree(root->left)*productTree(root->right);
}

//Q-2->Find the min value in the Binary Tree
int minTree(TreeNode *root){
    if(root == NULL) return INT_MAX;
    return min(root->val,min(minTree(root->left),minTree(root->right)));
}
//Q-3-> Balanced Binary Tree [Leetcode 110]
 int levels(TreeNode* root){
        if(root == NULL) return 0;
        return max(levels(root->left),levels(root->right))+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        if(abs(levels(root->left)-levels(root->right))>1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }

//Q-4 Symmetric Tree [LeetCode 101]
    bool issame(TreeNode *root1,TreeNode *root2){
        if(root1 == NULL && root2 == NULL) return true;
        if(root1 == NULL || root2 == NULL || root1->val != root2->val) return false;
        return issame(root1->left,root2->right) && issame(root2->left,root1->right);
    }
    bool isSymmetric(TreeNode* root) {
        return issame(root->left,root->right);
    }
int main(){TreeNode *a = new TreeNode(1);
    TreeNode* b = new TreeNode(2);
    TreeNode* c = new TreeNode(3);
    TreeNode* d = new TreeNode(4);
    TreeNode* e = new TreeNode(5);
    TreeNode* f = new TreeNode(6);

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    Display(a);
    cout<<endl<<"Product is "<<productTree(a);
    cout<<endl<<"Min is "<<minTree(a);
    cout<<endl<<isBalanced(a);
    cout<<endl<<isSymmetric(a);

}