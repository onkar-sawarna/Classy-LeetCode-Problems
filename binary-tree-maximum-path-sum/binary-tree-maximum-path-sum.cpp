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
    int maxpath_sum(TreeNode* root,int& result){
        if(root == NULL)return 0;
        //Hypothesis- this has to be true
        int l = maxpath_sum(root->left,result);
        int r = maxpath_sum(root->right,result);
//Temporary answer
//This has to be passed to the node's parent
//the second operand of outer max denotes that both the left and right subarray returned negative values
        int temp = max(max(l,r)+root->val,root->val);
//now find the max between the diameter of from that particular subtree or from its parents
        int ans = max(temp,root->val+l+r);
        result = max(result,ans);
        return temp;
        
    }
    int maxPathSum(TreeNode* root) {
        int result=INT_MIN;
        maxpath_sum(root,result);
        return result;
    }
};