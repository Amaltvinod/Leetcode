class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>ans;
        for(int a:nums){
            if(a<pivot)ans.push_back(a);
        }
        for(int a:nums){
            if(a==pivot)ans.push_back(a);
        }
        for(int a:nums){
            if(a>pivot)ans.push_back(a);
        }
        return ans;
        
    }
};