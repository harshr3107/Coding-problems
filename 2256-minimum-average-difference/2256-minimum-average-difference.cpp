class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        
        vector<long long> prefix(nums.size());
        long long sum=0;
        
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            prefix[i]=sum;
        }
        
        
        long long avg1;
        long long avg2;
        long long ans = LONG_MAX;
        int minind;
        long long temp=0;
        
        for(int i=0;i<nums.size();i++)
        {
            avg1=prefix[i]/(i+1);
            if(i!=nums.size()-1)
            {
            avg2 = (prefix[nums.size()-1]-prefix[i])/(nums.size()-i-1);
            }else{
                avg2=0;
            }
            
            //cout<<"avg1: "<<avg1<<" avg2: "<<avg2<<endl;
            
            temp = abs(avg1-avg2);
                
                if(temp<ans)
                {
                    minind=i;
                    ans=temp;
                }
            
            
        }
        
        
        
        
        
        
       return minind;
        
        
    }
};