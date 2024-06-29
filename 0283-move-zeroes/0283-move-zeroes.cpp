class Solution {
public:
    
    
    /*void moveelements(vector<int>& v,int pos)
    {
        
        int j=pos;
        
        while(j<v.size()-1)
        {
            v[j]=v[j+1];
            j++;
        }
        
        v[j]=0;
        
        
    }
    
    bool checklast(vector<int>& v,int pos)
    {
       int i=pos;
        
        while(i<v.size() && v[i]==0)
        {
            i++;
        }
        
        if(i==v.size())
        {
            return true;
        }
        
        return false;
        
    }
    
    */
    
    void moveZeroes(vector<int>& nums) {
        
    /*int i=0;
    
    while(i<nums.size())
    {
        
        if(nums[i]==0)
        {
            if(checklast(nums,i))
            {
                break;
            }else{
                
                moveelements(nums,i);
            }
        }else{
            
            i++;
        }
        
        
    }*/
        
        
        
        
      /*  
        int i=0;
        int j=0;
        
        
        while(i<nums.size())
        {
            if(nums[i]==0)
            {
                int j=i+1;
                while(j<nums.size() && nums[j]==0)
                {
                    j++;
                }
                
                if(j==nums.size())
                {
                    return;
                }
                
                swap(nums[i],nums[j]);
               
            }
            
            i++;
            
        }*/
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        int pos=0;
        int j=0;
        
        while(j<nums.size())
        {
            if(nums[j]!=0)
            {
                swap(nums[pos],nums[j]);
                pos++;
            }
            j++;
            
            
        }
        
        
        
          
        
        
        
        
    }
};