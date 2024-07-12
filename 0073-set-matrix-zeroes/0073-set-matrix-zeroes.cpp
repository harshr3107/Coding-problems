class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        vector<pair<int,int>> v;
        
       for(int i=0;i<matrix.size();i++)
       {
           for(int j=0;j<matrix[0].size();j++)
           {
               if(matrix[i][j]==0)
               {
                   pair<int,int> p;
                   p.first=i;
                   p.second=j;
                   v.push_back(p);
               }   
                   
               
               
           }
       }
        
        
        for(int j=0;j<v.size();j++)
        {
           // cout<<v[j].first<<" "<<v[j].second<<endl;
             
            for(int i=0;i<matrix[0].size();i++)
            {
                   matrix[v[j].first][i]=0;   
            }
            for(int i=0;i<matrix.size();i++)
            {
                matrix[i][v[j].second]=0;
            }
            
            
            
        }
        
        
        
    }
};