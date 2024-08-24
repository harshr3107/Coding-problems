class Solution {
public:
    vector<vector<int>> generate(int numrows) {
        
        int i=0;
        int j=0;
        
        vector<vector<int>> ans;
        
        for(int i=1;i<=numrows;i++)
        {
            vector<int> v(i);
            v[0]=1;
            v[i-1]=1;
            
            for(int j=2;j<i;j++)
            {
                v[j-1] = ans.back()[j-1]+ans.back()[j-2];
                
            }
            
            ans.push_back(v);
        }
        
        return ans;
        
        
    }
};