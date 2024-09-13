class Solution {
public:
    
     
    
    
    
    
    
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        
        vector<int> prefix(arr.size());
        int sum=0;
        for(int i=0;i<arr.size();i++)
        {
            sum=(sum^arr[i]);
            prefix[i]=sum;
        }
        
     
        
        vector<int> ans;
        
        for(int i=0;i<queries.size();i++)
        {
            int a=queries[i][0];
            int b = queries[i][1];
            
            if(a!=0)
            {
                ans.push_back(prefix[b]^prefix[a-1]);
            }else{
                
                ans.push_back(prefix[b]);
            }
            
            
        }
        
        
        
        return ans;
        
    }
};