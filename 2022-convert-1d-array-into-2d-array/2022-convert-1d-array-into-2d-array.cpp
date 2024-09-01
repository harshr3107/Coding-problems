class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        
        
        vector<int> v;
        vector<vector<int>> ans;
        int h=0;
        int b=0;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(h==original.size())
                {
                    b++;
                    break;
                }
                v.push_back(original[h]);
                h++;
            }
            ans.push_back(v);
            v.clear();
        }
        
        if(h!=original.size() || b>0)
        {
            ans.clear();
        }
        
        
        return ans;
        
    }
};