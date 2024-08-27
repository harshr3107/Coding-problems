class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        map<int,int> prefix;
        map<int,int> postfix;
        
        int sum1=0;
        int sum2=0;
        
        int ans=INT_MAX;
        
        for(int i=0;i<nums.size();i++)
        {
            sum1+=nums[i];
            sum2+=nums[nums.size()-i-1];
            
            
            
            if(prefix.find(sum1)==prefix.end())
            {
                prefix[sum1]=i;
            }
            if(postfix.find(sum2)==postfix.end())
            {
                postfix[sum2]=nums.size()-i-1;
            }
            
        }
        
        
        if(postfix.find(x)!=postfix.end())
        {
            int a = nums.size()-postfix[x];
            
            ans=min(ans,a);
        }
        
         if(prefix.find(x)!=prefix.end())
        {
            ans = min(ans,prefix[x]+1);
        }
        
       
        
       int target;
        int a=0;
       
        
        for(auto it: prefix)
        {
            target=x-it.first;
            if(postfix.find(target)!=postfix.end() && it.second<postfix[target])
            {
              
                a=it.second+1;
                a=a+(nums.size()-postfix[target]);
               
                ans = min(ans,a);
            }
        }
        
      
        
        if(ans==INT_MAX)
        {
            return -1;
        }
        
        return ans;
        
        
        
    }
};