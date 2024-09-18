#include <cstdlib>

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        
       unordered_map<int,int> row;
       unordered_map<int,int> col;
        
        for(int i=0;i<grid.size();i++)
        {
            int ones=0;
            
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==1)
                {
                    ones++;
                }
                
            }
            row[i]=ones;
            
        }
        
        for(int j=0;j<grid[0].size();j++)
        {
            int ones=0;
            
            for(int i=0;i<grid.size();i++)
            {
                if(grid[i][j]==1)
                {
                    ones++;
                }
            }
            
            col[j]=ones;
            
        }
        
        
        vector<vector<int>> ans(grid);
        
        
       /* for(int i=0;i<ans.size();i++)
        {
            for(int j=0;j<ans[i].size();j++)
            {
                ans[i][j] = row[i]+col[j]-(abs(static_cast<int>(row[i])-ans[i].size()))-(abs(static_cast<int>(col[j])-ans.size()));
                
            }
        }*/
        
        for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans[i].size(); j++) {
        ans[i][j] = row[i] + col[j] - abs(static_cast<int>(row[i] - ans[i].size())) - abs(static_cast<int>(col[j] - ans.size()));
    }
}

        
        
        return ans;
        
        
        
    }
};