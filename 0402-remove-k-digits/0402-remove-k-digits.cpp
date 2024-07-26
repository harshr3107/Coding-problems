class Solution {
public:
    
    /*
    //recursive approach
    
    void getsmallest(string num,int cur,int required,string& ans,int& minnum)
    {
        
        if(cur==num.length())
        {
            if(ans.length()==required)
            {
                int number = stoi(ans);
                minnum = min(minnum,number);
                //cout<<"value of number are "<<number<<endl;
                
            }
            
            
            return;
            
        }
        
        
        
        
        ans.push_back(num.at(cur));
        getsmallest(num,cur+1,required,ans,minnum);
        ans.pop_back();
        getsmallest(num,cur+1,required,ans,minnum);
        
        
        
    }
    
    
    
    
    
    string removeKdigits(string num, int k) {
        
        string ans="0";
        
        int size = num.length();
        int required=num.length()-k+1;
        int minnum = INT_MAX;
        
        getsmallest(num,0,required,ans,minnum);
        
        return to_string(minnum);
        
    }
    
   */
  
    
    
    
string removeKdigits(string nums, int k) {
    
    stack<int> st;
    
    for(int i=0;i<nums.size();i++)
    {
       while(!st.empty() && k>0 && st.top()-'0'>nums[i]-'0')
        {
            st.pop();
            k--;
        }
        
        st.push(nums[i]);
    }
    
   
    
    
    while(k>0)
    {
        st.pop();
        k--;
    }
   
    
    if(st.empty())
    {
        return "0";
    }
    
    string ans="";
    
    while(!st.empty())
    {
        ans+=st.top();
        st.pop();
       
    }
    
    //int i = ans.length()-1;
    
    while(ans.length()!=0 &&  ans.back()=='0')
    {
        ans.pop_back();
    }
    
    
    reverse(ans.begin(),ans.end());
    
    if(ans.empty())
    {
        return "0";
    }
    
    
    
    
    return ans;
    
    
    
    
        
    
        
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
};



/*
class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> st;

        for(int i = 0; i<num.size(); i++){
            while(!st.empty() && k > 0 && (st.top() - '0') > num[i] - '0'){
                k--;
                st.pop();
            }
            st.push(num[i]);
        }

        while(k > 0){
            st.pop();
            k--;
        }

        if(st.empty()) return "0";

        string res = "";

        while(!st.empty()){
            res += st.top();
            st.pop();
        }

        while(res.size() != 0 && res.back() == '0'){
            res.pop_back();
        }

        reverse(res.begin(), res.end());

        if(res.empty()) return "0";

        return res;
    }
};

*/