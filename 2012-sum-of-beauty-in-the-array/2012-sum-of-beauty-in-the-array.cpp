class Solution {
public:
    
    void display(multiset<int> s)
    {
        for(auto it: s)
        {
            cout<<it<<" ";
        }
        
        cout<<endl;
    }
    
    int sumOfBeauties(vector<int>& nums) {
        
        multiset<int> s1;
        multiset<int> s2;
        
        int ans=0;

        s1.insert(nums[0]);
       
        for(int j=2;j<nums.size();j++)
        {
            s2.insert(nums[j]);
        }
        
        multiset<int>:: iterator it;
        
        
       
       
        
        
        
      // display(s1);
      //display(s2);
       
        
        
        for(int i=1;i<nums.size()-1;i++)
        {
           // cout<<"i entered here for "<<nums[i]<<" ";
            
            
            if(*s1.rbegin()<nums[i] && *s2.begin()>nums[i])
            {
               // cout<<"i entered here 1";
                ans+=2;
            }else if(nums[i-1]<nums[i] && nums[i]<nums[i+1])
            {
              // cout<<"i entered here 2";
                ans+=1;
            }else{
                //cout<<"i entered here 3";
                ans=ans;
            }
            //cout<<endl;
            s1.insert(nums[i]);
            it = s2.find(nums[i+1]);
            //cout<<*it<<endl;
            s2.erase(it);
            //display(s1);
            //display(s2);
            
        }
        
        
       
        
       return ans;
        
        
        
    }
};