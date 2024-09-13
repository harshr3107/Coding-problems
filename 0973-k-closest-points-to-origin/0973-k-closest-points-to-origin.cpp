class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
            priority_queue<pair<int,vector<int>>>  maxheap;
        
            for(int i=0;i<points.size();i++)
            {
                int p1=points[i][0];
                int p2=points[i][1];
               
                
                int dis = pow(p1,2)+pow(p2,2);
                
                if(maxheap.size()<k)
                {
                    
                    maxheap.push(make_pair(dis,points[i]));
                }else{
                    
                    
                    if(maxheap.top().first>dis)
                    {
                        maxheap.pop();
                        maxheap.push(make_pair(dis,points[i]));
                    }
                    
                    
                }
                
                
            }
        
        
        vector<vector<int>> ans;
        
        while(!maxheap.empty())
        {
            ans.push_back(maxheap.top().second);
            maxheap.pop();
        }
        
        
        return ans;
        
    }
};