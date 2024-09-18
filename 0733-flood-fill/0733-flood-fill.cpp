class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        
        
        vector<vector<bool>> visited;
        vector<vector<int>> ans(image);
        
        for(int i=0;i<image.size();i++)
        {
            vector<bool> v(image[i].size(),false);
            visited.push_back(v);
        }
        
        
       
        
        
        visited[sr][sc]=true;
        queue<pair<int,int>> q;
        q.push(make_pair(sr,sc));
        
        int startcolor = image[sr][sc];
        
       // cout<<"the start color is "<<startcolor;
        
        
        while(!q.empty())
        {
            
            
            pair<int,int> temp = q.front();
            q.pop();
            int row = temp.first;
            int col = temp.second;
            ans[row][col]=color;
            
           //cout<<row<<" "<<col<<endl;
            
            
            
           
            
            
            if((row-1)>=0)
            {
                
                if(image[row-1][col]==startcolor && visited[row-1][col]==false)
                {
                    q.push(make_pair(row-1,col));
                    visited[row-1][col]=true;
                }
                
            }
            
            
            if((row+1)<image.size())
            {
                if(image[row+1][col]==startcolor && visited[row+1][col]==false)
                {
                    q.push(make_pair(row+1,col));
                    visited[row+1][col]=true;
                }
            }
            
            if((col-1)>=0)
            {
                if(image[row][col-1]==startcolor && visited[row][col-1]==false)
                {
                    q.push(make_pair(row,col-1));
                    visited[row][col-1]=true;
                }
                
            }
            
            
            if((col+1)<image[row].size())
            {
                if(image[row][col+1]==startcolor && visited[row][col+1]==false)
                {
                    q.push(make_pair(row,col+1));
                    visited[row][col+1]=true;
                }
                
            }
            
            
            
        }
        
       
        //cout<<"the startcolor is "<<startcolor<<endl;
        
        return ans;
        
        
    }
};