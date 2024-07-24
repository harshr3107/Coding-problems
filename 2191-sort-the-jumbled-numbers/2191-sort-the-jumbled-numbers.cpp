
class Solution {
public:
    
    bool static cmp(pair<int, int> &a, pair<int, int> &b)
    {
        return a.first < b.first;
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        
        vector<pair<int,int>> mp;
        for(auto it : nums)
        {
            string str = to_string(it);
            string temp1 = "";
            
            for(int i = 0 ; i < str.size() ; i++)
            {
                int x = str[i]-'0';
                int temp = mapping[x];
                temp1 += to_string(temp); 
            }
           
            int res = stoi(temp1);
            mp.push_back({res, it});
        }
       
        vector<int> result;
       
        sort(mp.begin(), mp.end(), cmp);
        
       
        
        for(auto rp : mp)
        {
            result.push_back(rp.second);
        }

        
        return result;
    }
};
