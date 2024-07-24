/*class Solution {
public:
    
     static bool comp(pair<int,int> a,pair<int,int> b)
    {
        return a.second<=b.second;
    }
    
    
    void sortmap(map<int,int>& m,vector<int>& ans)
    {
        vector<pair<int,int>> v;
        
        map<int,int>:: iterator it = m.begin();
        
        for(it=m.begin();it!=m.end();it++)
        {
            v.push_back(*it);
        }
        
        sort(v.begin(),v.end(),comp);
        
        //map<int,int>:: iterator it;
    
        for(int i=0;i<v.size();i++)
        {
            ans.push_back(v[i].first);
        }
        
        
    }
    
    
    
    
    
    
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        
        map<int,int> mp;
        vector<int> mnums;
        int temp=0;
        int num=0;
        int digit=0;
        
        vector<int> ans;
        
        for(int i=0;i<nums.size();i++)
        {
            
            temp=nums[i];
            num=0;
            int a=1;
            
            while(temp>0)
            {
               // cout<<"current value of digit is "<<temp%10<<" "<<mapping[temp%10]<<endl;
                digit = mapping[temp%10];
                num = num+digit*a;
                //cout<<"current value of num is "<<num<<endl;
                temp=temp/10;
                a=a*10;
                
            }
            
          
            
            mp[nums[i]]=num;
            mnums.push_back(num);
            
        }
        
       
       for(int i=0;i<nums.size();i++)
        {
            cout<<nums[i]<<" "<<mnums[i]<<endl;
        }
        
      
        
        
        sortmap(mp,ans);
        
        
        
        
        return ans;
        
    }
};*/

class Solution {
public:
    //Custom Comparator
    bool static cmp(pair<int, int> &a, pair<int, int> &b)
    {
        return a.first < b.first;
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        //Phase 1
        //Taking Pair to Store the Original Value and Changed Value 
        vector<pair<int,int>> mp;
        for(auto it : nums)
        {
            string str = to_string(it);
            string temp1 = "";
            //Changing the Value from to original to mapped value
            for(int i = 0 ; i < str.size() ; i++)
            {
                int x = str[i]-'0';
                int temp = mapping[x];
                temp1 += to_string(temp); 
            }
            //pushing all the values to vector of pair
            int res = stoi(temp1);
            mp.push_back({res, it});
        }
        //Phase 2
        vector<int> result;
        //Sorting the vector according to changed value and added comparator so that equal value remains unchanged 
        sort(mp.begin(), mp.end(), cmp);
        
        //Phase 3
        //Storing the Result
        for(auto rp : mp)
        {
            result.push_back(rp.second);
        }

        //Phase 4
        //return answer
        return result;
    }
};