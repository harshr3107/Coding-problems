class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int r_start=0;
        int r_end=matrix.size()-1;
        
        int c_start=0;
        int c_end=matrix[0].size()-1;
        
        
        while(c_start<=c_end && r_start<=r_end)
        {
            int rs = r_start;
            int re = r_end;
            int cs = c_start;
            int ce = c_end;
            
            while(rs<r_end && cs<c_end)
            {
                cout<<"value of rs re cs se are "<<rs<<" "<<re<<" "<<cs<<" "<<ce<<endl;
                
                int temp = matrix[r_start][cs];
                cout<<"value of temp is "<<temp<<endl;
                    
                matrix[r_start][cs]=matrix[re][c_start];
                matrix[re][c_start]= matrix[r_end][ce];
                matrix[r_end][ce]=matrix[rs][c_end];
                matrix[rs][c_end]=temp;
                
                for(int i=0;i<=r_end;i++)
                {
                    for(int j=0;j<=c_end;j++)
                    {
                        cout<<matrix[i][j]<<" ";
                    }
                    cout<<endl;
                }
                
                cout<<endl;
                
                cs++;
                rs++;
                ce--;
                re--;
                
            }
            
            cout<<"ab mai bahar aagaya hoon\n\n";
            
            r_start++;
            c_start++;
            r_end--;
            c_end--;
            
            
            
            
        }
            
         
        
    }
};