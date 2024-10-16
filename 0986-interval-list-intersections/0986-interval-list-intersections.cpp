class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& f, vector<vector<int>>& s) {
        
        
        int i=0;
        int j=0;
        
        vector<vector<int>> ans;
         vector<int> v;
        
        while(i<f.size() && j<s.size())
        {
            
            if(f[i][0]<=s[j][0])
            {
               // cout<<"i entered here 1\n";
                
                if(f[i][1]>=s[j][0])
                {
                   
                    
                    int a = s[j][0];
                    int b = min(f[i][1],s[j][1]);
                    
                    v.push_back(a);
                    v.push_back(b);
                    ans.push_back(v);
                    v.clear();
                }
                
                
                
            }else{
                
                //cout<<"i entered here 2\n";
                
                if(s[j][1]>=f[i][0])
                {
                    vector<int> v;
                    
                    int a = f[i][0];
                    int b = min(f[i][1],s[j][1]);
                    
                    v.push_back(a);
                    v.push_back(b);
                    
                    ans.push_back(v);
                    v.clear();
                }
                
                
                
            }
            
            
            
            
            
            
            if(f[i][1]>s[j][1])
            {
                j++;
            }else{
                i++;
            }
            
        }
        
        
        return ans;
        
        
        
    }
};