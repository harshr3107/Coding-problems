class Solution {
public:
    
    
    void moveelements(vector<int>& v,int pos)
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
    
    
    
    void moveZeroes(vector<int>& nums) {
        
    int i=0;
    
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
        
        
    }
        
        
        
    }
};