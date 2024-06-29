class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        /*vector<int> count(nums.size()+1);
        
        for(int i=0;i<nums.size();i++)
        {
            count[nums[i]]++;
        }
      
        
        
        vector<int>::iterator it = find(count.begin(),count.end(),0);
        
        int a=it-count.begin();
        
        return a;*/
        
       /* sort(nums.begin(),nums.end());
        int a=0;
        int b=nums.size();
        int i=0;
        
        while(b>=a)
        {
            if(nums[a]!=a)
            {
            
                return a;
            }
        
            if(nums[b-1]!=b)
            {
                return b;
            }
        
        a++;
        b--;
    }
        
        
        return 0;*/
        
        
        int a=0;
        
        for(int i=0;i<nums.size();i++)
        {
            a=a^nums[i];
        }
        
        for(int i=0;i<=nums.size();i++)
        {
            a=a^i;
        }
        
        
        
        return a;
        
        
            
        
        
    }
};