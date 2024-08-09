class Solution {
public:
    
    /*bool getall3(vector<int> nums,int ind,int cursize,int cursum,int& ans,int target,int &a)
    {
        if(ind==nums.size() || cursize==3)
        {
            if(cursize==3)
            {
                if(cursum==target)
                {
                     a=cursum;
                    return true;

                    cout<<"bc mai hei hoon "<<cursum<<endl;
                }
                
                
                
            }
            return false;
        }
        
        cursum+=nums[ind];
        if(getall3(nums,ind+1,cursize+1,cursum,ans,target,a)==true)
        {
           return true;   
        }
        cursum-=nums[ind];
        if(getall3(nums,ind+1,cursize,cursum,ans,target,a)==true)
        {
            return true;
        }
        
        return false;
       
        
        
        
    }*/
    
    
    int threeSumClosest(vector<int>& nums, int target) {
        
       
       /* int cursum=0;
        int ans = INT_MAX;
        int a=0;
        getall3(nums,0,0,cursum,ans,target,a);*/
        
        
        sort(nums.begin(),nums.end());
        
        int low;
        int high;
        int ans=INT_MAX;
        int a=0;
        
        for(int i=0;i<nums.size();i++)
        {
            
          
            
            if(i!=0 && nums[i]==nums[i-1])
            {
                continue;
            }
            low=i+1;
            high=nums.size()-1;
            
            while(high>low)
            {
                
                int s = nums[i]+nums[low]+nums[high];
                
                if(ans>abs(target-s))
                {
                     ans=abs(target-s);
                     a=s;
                    
                }
                
                
                
                if(s>target)
                {
                    high--;
                }else{
                    low++;
                }
                
                
                
            }
            
            
            if(ans==0)
            {
                break;
            }
                
            
            
            
        }
        
        
        
        
        return a;
        
        
    }
};