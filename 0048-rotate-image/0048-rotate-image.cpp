class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int r_start=0;
        int r_end=matrix.size()-1;
        
        int c_start=0;
        int c_end=matrix[0].size()-1;
        
        
        while(c_start<c_end && r_start<r_end)
        {
            int rs = r_start;
            int re = r_end;
            int cs = c_start;
            int ce = c_end;
            
            while(rs<r_end && cs<c_end)
            {
               
                int temp = matrix[r_start][cs];
              
                    
                matrix[r_start][cs]=matrix[re][c_start];
                matrix[re][c_start]= matrix[r_end][ce];
                matrix[r_end][ce]=matrix[rs][c_end];
                matrix[rs][c_end]=temp;
                
            
                cout<<endl;
                
                cs++;
                rs++;
                ce--;
                re--;
                
            }
            
           
            
            r_start++;
            c_start++;
            r_end--;
            c_end--;
            
            
            
            
        }
            
         
        
    }
};