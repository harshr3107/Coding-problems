class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        
        
        for(int i=0;i<box.size();i++)
        {
            for(int j=box[i].size()-2;j>=0;j--)
            {
                
             
                if(box[i][j]=='#' )
                {
                    //cout<<"i entered here for "<<i<<" "<<j<<endl;
                    int k=j+1;
                    box[i][j]='.';
                    while(k<box[i].size() && box[i][k]=='.')
                    {
                        k++;
                    }
                   
                   
                
                    box[i][k-1]='#';
                    
                }
                
            }
        }
        
        
        vector<vector<char>> ans;
        
        for(int j=0;j<box[0].size();j++)
        {
            vector<char> v;
            for(int i=0;i<box.size();i++)
            {
                
                v.push_back(box[i][j]);
                
            }
            reverse(v.begin(),v.end());
                ans.push_back(v);
            //cout<<endl;
        }
        
        
        
        
        return ans;
        
    }
};