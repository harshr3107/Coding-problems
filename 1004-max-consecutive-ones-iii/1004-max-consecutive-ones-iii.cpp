class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
       
        int low=0;
        int high=0;
        int curk=0;
        int i=0;
        int maxlen = 0;
        
        while(high<nums.size())
        {
            if(nums[high]==1)
            {
                //cout<<"i entered at first if\n";
                high++;
                maxlen=max(maxlen,(high-low));
            }else{
                
                curk++;
                //cout<<"value of k at "<<high<<" is "<<curk<<endl;
                if(curk>k)
                {
                    while(low<high && nums[low]!=0)
                    {
                        low++;
                    }
                    low++;
                   
                
                    curk--;
                    //cout<<"value after decrement of k is "<<curk<<endl;                    
                 }
                
                high++;
                maxlen=max(maxlen,(high-low));
            }
         }
        
        return maxlen;
        
        
       
    }
};