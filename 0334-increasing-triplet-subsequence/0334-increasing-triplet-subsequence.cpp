class Solution {
public:
    
    
    
    
    
    
    
    
    
    
    
    
    
    bool increasingTriplet(vector<int>& nums) {
       
        
        //BRUTE FORCE APPROCH passed 35 testcases tle
        /*
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                for(int k=j+1;k<nums.size();k++)
                {
                    if(nums[i]<nums[j] && nums[j]<nums[k])
                    {
                        return true;
                    }
                    
                }
            }
        }
         return false;*/
        
        
        //RECURSION
        /*
        int ind=0;
        int i=0;
        vector<int> v;
        
        return checkwithsubsequences(nums,ind,v);*/
        
        
        //Another approch but got Tle passes 75 test cases
        /*
        int i=0;
        int prev;
        int next;
        int a;
        
        while(i<nums.size()-1)
        {
            
            while(i<nums.size()-1 && nums[i]==nums[i+1])
            {
                i++;
            }
           
            
            
            a=0;
            prev=i-1;
            next=i+1;
            
            while(prev>=0)
            {
                if(nums[i]>nums[prev])
                {
                    a++;
                    break;
                }
                prev--;
            }
            
            while(next<nums.size())
            {
                if(nums[i]<nums[next])
                {
                    a++;
                    break;
                }
                
                next++;
                
            }
            
            
            if(a==2)
            {
                return true;
            }
            
            
            
            
            
            i++;
        }
        
        
        return false;*/
        
        
        int left = INT_MAX;
        int right = INT_MAX;
        
        for(int i=0;i<nums.size();i++)
        {
            
            if(nums[i]<=left)
            {
                left=nums[i];
            }else if(nums[i]<=right)
            {
                right=nums[i];
            }else{
                return true;
            }
            
            
        }
        
        
        
        
        
        return false;
        
        
        
        
        }
};