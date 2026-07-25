class Solution {
public:
    int maxProduct(int n) {
        string temp=to_string(n);
        sort(temp.begin(),temp.end());
        return (temp[temp.size()-1]-'0')*(temp[temp.size()-2]-'0');
        
    }
};