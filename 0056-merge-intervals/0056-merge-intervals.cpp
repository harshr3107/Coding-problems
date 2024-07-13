/*class Solution {
public:
    
   
    
  
    vector<vector<int>> merge(vector<vector<int>>& v) {
        
        
        vector<int> ans;
        vector<int> cnt(100000);
        int laspos=0;
        int initpos=INT_MAX;
        
        for(int i=0;i<v.size();i++)
        {
            for(int j=v[i][0];j<=v[i][1];j++)
            {
                cnt[j]++;
            }
            
           
                if(v[i][1]>laspos)
                {
                    laspos=v[i][1];
                }
                if(v[i][0]<initpos)
                {
                    initpos=v[i][0];
                }
        }
        
       // cout<<"initpos: "<<initpos<<" lastpos: "<<laspos<<endl;
        
        vector<vector<int>> answer;
        
        int i=initpos;
        int j=initpos+1;
        
       /* for(int k=initpos;k<=laspos;k++)
        {
            cout<<cnt[k]<<" ";
        }
       // cout<<endl;
        
        while(j<=laspos)
        {
            if(cnt[j]==2)
            {
                b++;
            }
            
            if(cnt[j]==0)
            {
                
                //cout<<"i entered here\n";
                ans.push_back(i);
                ans.push_back(j-1);
                answer.push_back(ans);
                ans.clear();
                while(j<laspos && cnt[j]==0)
                {
                    j++;
                }
                i=j;
                b=0;
                
            }
            
            j++;
            
        }
        
        if(i!=laspos && j==laspos+1)
        {
             ans.push_back(i);
             ans.push_back(j-1);
            answer.push_back(ans);
        }
        
        return answer;
       
        
    }
};*/


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> output;
        for(auto interval : intervals){
            if(output.empty() || output.back()[1] < interval[0]){
                output.push_back(interval);
            }
            else{
                output.back()[1] = max(output.back()[1], interval[1]);
            }
        }
        return output;
    }
};
