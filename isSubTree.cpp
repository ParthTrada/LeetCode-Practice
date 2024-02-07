/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    bool isSame(TreeNode* root, TreeNode* subRoot){
         if(root == NULL && subRoot == NULL){
            return true;
        }

        if(root == NULL || subRoot == NULL){
            return false;
        }

        if(root->val == subRoot->val){
            return (isSame(root->left, subRoot->left) && isSame(root->right, subRoot->right));
        }
        return false;
    }

    bool isTree(TreeNode* root, TreeNode* subRoot){
        bool temp = false;

        if(root == NULL && subRoot == NULL){
            return true;
        }

        if(root == NULL || subRoot == NULL){
            return false;
        }

        if(root->val == subRoot->val){
            return (isTree(root->left, subRoot->left) && isTree(root->right, subRoot->right));
        }
        
        return false;
    }

    void Traversal(TreeNode* root, TreeNode* subRoot, bool &ans){

        bool temp = false;
        if(root == NULL){
            return;
        }

        if(root != NULL){

            if(root->val == subRoot->val){
                bool temp = isTree(root, subRoot);
                if(temp){
                    ans = isSame(root, subRoot);
                }                
            }
            Traversal(root->left, subRoot, ans);
            Traversal(root->right, subRoot, ans);
        }
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool ans = false;
        Traversal(root, subRoot, ans);
        return ans;      
    }
};