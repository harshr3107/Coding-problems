class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        
        sort(nums.begin(),nums.end());
        
        
        while(!nums.empty())
        {
            int i=0;
            int a=1;
            int n =nums[0];
            
            while(a<=k && find(nums.begin(),nums.end(),n)!=nums.end())
            {
                //cout<<"i found the num "<<n<<endl;
                a++;
                nums.erase(find(nums.begin(),nums.end(),n));
                n=n+1;
               
            }
            
            //cout<<endl;
            //cout<<"value of a is "<<a<<" value of k is "<<k<<endl<<endl;
            a=a-1;
            
            if(a<k)
            {
                return false;
            }
            
        }
        
        
        return true;
        
    }
};