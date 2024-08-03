class Solution {
public:
    int minSwaps(vector<int>& nums) {
        
        int ones=0;
        int zero=0;
        int one=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
            {
                ones++;
            }
        }
        
        int i=0;
        int j=0;
        
        //first window;
        
        while(j<ones)
        {
            if(nums[j]==0)
            {
                zero++;
            }else{
                one++;
            }
            
            j++;
        }
        
        j--;
        int ans = zero;
        //cout<<"init window zero are "<<ans<<endl;
        
        while(i<nums.size())
        {
           /* cout<<"\ni entered here for i "<<i<<endl;
            cout<<"current value of j is "<<j<<endl;
             cout<<"current zero are "<<zero<<endl<<endl;*/
            
            if(nums[i]==0)
            {
                zero--;
            }else{
                one--;
            }
            i++;
            j=(j+1)%nums.size();
            if(nums[j]==0)
            {
                zero++;
            }else{
                one++;
            }
            
           
            
            ans = min(ans,zero);
            
        }
        
        
        
        return ans;
        
        
        
    }
};