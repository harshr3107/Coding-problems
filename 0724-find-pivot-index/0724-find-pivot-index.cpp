class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        
        int a=0;
        int leftsum=0;
        int rightsum=0;
        
        if(nums.size()==1)
        {
            return 0;
        }
        
        for(int i=1;i<nums.size();i++)
        {
            rightsum+=nums[i];
        }
        
        //cout<<"right sum is "<<rightsum<<endl;
        
        int i=0;
        int currentind=-1;
        
        while(i<nums.size())
        {
             //cout<<"current letftsum is "<<leftsum<<endl;
            //cout<<"current rightsum is "<<rightsum<<endl;
            
            if(rightsum==leftsum)
            {
                //cout<<"i entered here at ind "<<i<<endl;
                currentind=i;
                break;
            }
            
            
           leftsum+=nums[i];
            
           i++;
            
            if(i<nums.size())
            {
            rightsum-=nums[i];
            }
                

            
            
        }
        
        
        return currentind;
        
        
        
    }
};