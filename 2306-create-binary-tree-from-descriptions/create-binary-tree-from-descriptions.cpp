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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        map<int,TreeNode*>map;
        set<int>set;
        for(vector<int>desc:descriptions){
            int root=desc[0];
            int child=desc[1];
            int isLeft=desc[2];
            if(!map.contains(root)){
                map[root]=new TreeNode(root);

            }
            if(!map.contains(child)){
                map[child]=new TreeNode(child);
            }

            if(isLeft){
                
                map[root]->left=map[child];
        

            }else{
                map[root]->right=map[child];
               
            }
            set.insert(child);
        }
        
        for(auto it:map){
            if(!set.count(it.first))return it.second;
        }
        
        return nullptr;
    }
};