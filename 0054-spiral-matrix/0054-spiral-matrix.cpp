class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
      
        
        vector<int> ans;
        
        int r_start=0;
        int r_end=matrix.size()-1;
        int c_start=0;
        int c_end=matrix[0].size()-1;
        
        
        while(r_end>=r_start && c_end>=c_start)
        {
            for(int i=c_start;i<=c_end;i++)
            {
                ans.push_back(matrix[r_start][i]);
            }
            
            r_start++;
            if(r_start>r_end)
            {
                break;
            }
            
            for(int j=r_start;j<=r_end;j++)
            {
                ans.push_back(matrix[j][c_end]);
            }
            
            c_end--;
             if(c_start>c_end)
            {
                break;
            }
            
            
            
            for(int j=c_end;j>=c_start;j--)
            {
                ans.push_back(matrix[r_end][j]);
            }
            
            r_end--;
            
             if(r_start>r_end)
            {
                break;
            }
            
            
            
            
            for(int j=r_end;j>=r_start;j--)
            {
                ans.push_back(matrix[j][c_start]);
            }
            c_start++;
            
            
            
            
        }
        
        
        
        
        
        
        
        
        return ans;
        
        
    }
};