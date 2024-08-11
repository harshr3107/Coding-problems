class Solution {
public:
    
    
    void display(vector<int> nums)
    {
        for(int i=0;i<nums.size();i++)
        {
            cout<<nums[i]<<" ";
        }
        
        cout<<endl;
    }
    
    
    
    int removeDuplicates(vector<int>& nums) {
        
        int i=0;
        int j;
        int a=0;
        int k;
        
        /*if(nums.size()<=2)
        {
            return nums.size();
        }*/
        
        while(i<nums.size()-1)
        {
            //cout<<"i entered here for "<<nums[i]<<endl;
            
            if(nums[i]>nums[i+1])
            {
                return i+1;
                
            }
            
            
            if(i!=0 && nums[i-1]>nums[i])
            {
                cout<<"mai yaha hoon\n";
                return i;
            }
            
            
            a=1;
            j=i;
            //cout<<"value of j is "<<j<<endl;
            while(i<nums.size()-1 && nums[i]==nums[i+1])
            {
               
                a++;
                if(a==3)
                {
                    //cout<<"value of a is 3 at i = "<<i<<endl;
                    j=i+1;
                    
                }
                i++;
                
            }
            
            i++;
            
            if(i==nums.size())
            {
                //cout<<"hshshshs\n";
                if(a<=2)
                {
                    return j+a;
                }
                
                return j;
            }
            
            
            if(a>=3 && i<nums.size())
            {
               k=j;
                
                //cout<<"value of j and i are "<<j<<" "<<i<<endl;
                
                while(i<nums.size() && j<nums.size())
                {
                    swap(nums[j],nums[i]);
                    i++;
                    j++;
                }
                
                //display(nums);
                i=k;
                continue;
            }
            
            
            
        }
        
        
        if(i!=0 && nums[i-1]>nums[i])
        {
                cout<<"mai yaha hoon\n";
                return i;
        }
        
        
        if(i==nums.size()-1)
        {
            return nums.size();
        }
        
        
        return 0;
        
        
    }
};