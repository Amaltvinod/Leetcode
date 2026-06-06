class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        vector<int>arr(n,1);

        const int mod=1e9+7;
        for(int j=0;j<k;j++){
            int sum=arr[0];
            for(int i=1;i<n;i++){
                sum+=arr[i];
                sum%=mod;
                arr[i]=sum;
                
            }

        }
        return arr[n-1];

    }
};