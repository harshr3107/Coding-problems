class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        
        vector<vector<int>> hdis;
        //vector<vector<bool>> visited;
        
        for(int i=0;i<h.size();i++)
        {
              vector<int> v(h[i].size(),INT_MAX);
             
            
            hdis.push_back(v);
            
            
        }
        
        
        
        hdis[0][0]=0;
        set<pair<int,pair<int,int>>> s;
        
        s.insert(make_pair(hdis[0][0],make_pair(0,0)));
        
        //cout<<"tyhe size of set is "<<s.size()<<endl;
        
        while(!s.empty())
        {
            
            
            pair<int,pair<int,int>> p = *(s.begin());
            s.erase(s.begin());
            int dis = p.first;
            int row = p.second.first;
            int col = p.second.second;
            
            //visited[row][col]=true;
            
            if((row-1)>=0)
            {
               // cout<<"1"<<endl;
                int a = max(dis,abs(h[row][col]-h[row-1][col]));
                
                if(a<hdis[row-1][col])
                {
                    if(s.count(make_pair(hdis[row-1][col],make_pair(row-1,col))))
                    {
                        s.erase(s.find(make_pair(hdis[row-1][col],make_pair(row-1,col))));
                    }
                    
                    hdis[row-1][col]=a;
                    
                    s.insert(make_pair(a,make_pair(row-1,col)));
                    
                }
                
                
            }
            
            
            if((row+1)<h.size())
            {
                //cout<<"2"<<endl;
                
                int a = max(dis,abs(h[row][col]-h[row+1][col]));
                
                if(a<hdis[row+1][col])
                {
                    if(s.count(make_pair(hdis[row+1][col],make_pair(row+1,col))))
                    {
                        s.erase(s.find(make_pair(hdis[row+1][col],make_pair(row+1,col))));
                    }
                    
                    hdis[row+1][col]=a;
                    
                    s.insert(make_pair(a,make_pair(row+1,col)));
                    
                }
                
                
            }
            
             if((col-1)>=0)
            {
                 //cout<<"3"<<endl;
                 
                int a = max(dis,abs(h[row][col]-h[row][col-1]));
                
                if(a<hdis[row][col-1])
                {
                    if(s.count(make_pair(hdis[row][col-1],make_pair(row,col-1))))
                    {
                        s.erase(s.find(make_pair(hdis[row][col-1],make_pair(row,col-1))));
                    }
                    
                    hdis[row][col-1]=a;
                    
                    s.insert(make_pair(a,make_pair(row,col-1)));
                    
                }
                
                
            }
            
            //cout<<"idhar pohcha mai\n";
            //cout<<col+1<<" "<<h[row].size()<<" "<<visited[row][col+1]<<endl;
             
             if((col+1)<h[row].size())
            {
                // cout<<"4"<<endl;
                 
                int a = max(dis,abs(h[row][col]-h[row][col+1]));
                
                if(a<hdis[row][col+1])
                {
                    if(s.count(make_pair(hdis[row][col+1],make_pair(row,col+1))))
                    {
                        s.erase(s.find(make_pair(hdis[row][col+1],make_pair(row,col+1))));
                    }
                    
                    hdis[row][col+1]=a;
                    
                    s.insert(make_pair(a,make_pair(row,col+1)));
                    
                }
                
                
            }
            
            
        }
        
        
       
        
        
        
        //return 0;
        return hdis[h.size()-1][h[0].size()-1];
        
        
        
        
        
    }
};