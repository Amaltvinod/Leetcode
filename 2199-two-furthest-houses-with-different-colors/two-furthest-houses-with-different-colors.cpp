class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n=colors.size();
        int ans=0;
        int j=n-1,i=0;
        while(j>=0){
            if(colors[j]==colors[0])j--;
            else{
                ans=max(ans,j);
                break;
            }
        }
        while(i<n){
            if(colors[n-1]==colors[i])i++;
            else{
                ans=max(ans,n-i-1);
                break;
            }
        }
        return ans;


    }

};