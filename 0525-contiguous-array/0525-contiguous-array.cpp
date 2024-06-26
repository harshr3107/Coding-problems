/*class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        int i=0;
        int ans=0;
        int ones=0;
        int zeros=0;
        int max=INT_MIN;
        
        if(nums.size()==1)
        {
            return 0;
        }
        
        while(i<nums.size())
        {
            if(nums[i]==0)
            {
                zeros++;
            }else{
                ones++;
            }
            
            if(zeros==ones)
            {
                if(max<(zeros+ones))
                {
                    max=zeros+ones;
                    ans=max;
                }
                
            }
            
            i++;
            
            
        }
        
        i=1;
        
        int tones=ones;
        int tzeros=zeros;
        
        for(int i=1;i<nums.size()-ans;i++)
        {
            
            
            if(nums[i-1]==0)
            {
                zeros--;
            }else{
                ones--;
            }
            tones=ones;
            tzeros=zeros;
            
            if(tzeros==tones)
            {
                
                if(max<(tzeros+tones))
                {
                    max=tzeros+tones;
                    ans=max;
                }
                
            }
                
            
            int j=nums.size()-1;
            
            while(j>=i)
            {
                
                if(nums[j]==0)
                {
                   tzeros--;    
                }else{
                    tones--;
                }
                
                
                if(tzeros==tones)
            {
                
                if(max<(tzeros+tones))
                {
                    max=tzeros+tones;
                    ans=max;
                }
                
            } 
                
                j--;
                
            }
            }
        
       
        
        
        
        
        
        
        return ans;
        
    }
};*/


class Solution {
public:
    int findMaxLength(vector<int>& nums) {
		vector<int> arr(2*nums.size() + 1, INT_MIN);
		arr[nums.size()] = -1;
        int maxLen = 0, sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += (nums[i] == 0 ? -1 : 1);
			if (arr[sum + nums.size()] >= -1)  maxLen = max(maxLen, i - arr[sum + nums.size()]);
			else  arr[sum + nums.size()] = i; 
        }
        return maxLen;
    }
};