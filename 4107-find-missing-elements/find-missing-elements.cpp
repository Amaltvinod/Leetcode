class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
       set<int>set;
       for(int a:nums){
        set.insert(a);
       }
       vector<int>ans;
       int mn=*min_element(nums.begin(),nums.end()); 
       int mx=*max_element(nums.begin(),nums.end());
       for(int i=mn;i<=mx;i++){
            if(set.count(i))continue;
            ans.push_back(i);

       }
       return ans;
    }
};