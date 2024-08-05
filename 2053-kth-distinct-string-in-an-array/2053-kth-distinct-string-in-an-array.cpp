class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        
        queue<string> q;
        map<string,int> m;
        
        for(int i=0;i<arr.size();i++)
        {
            m[arr[i]]++;
            if(m[arr[i]]<=1)
            {
                q.push(arr[i]);
            }
            
        }
        
        int a=0;
        
        while(!q.empty())
        {
            if(m[q.front()]==1)
            {
                a++;
                if(a==k)
                {
                    return q.front();
                }
                
            }
            
            q.pop();
        }
        
        
        return "";
        
        
        
        
    }
};