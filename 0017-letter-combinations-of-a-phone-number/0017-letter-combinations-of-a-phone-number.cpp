class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        vector<string> ans;
        if(digits.length()==0)
        {
            return ans;
        }
        
       
        map<int,string> m;
        m[2]="abc";
        m[3]="def";
        m[4]= "ghi";
        m[5]="jkl";
        m[6]="mno";
        m[7]="pqrs";
        m[8]="tuv";
        m[9]="wxyz";
            
        
            
            
        
        string s ="";
        getcombi(digits,0,s,ans,m);
        
        return ans;
        
    }
    
    
    void getcombi(string digits,int index,string s,vector<string>& ans,map<int,string> m)
    {
        if(s.length()==digits.length())
        {
            ans.push_back(s);
            return;
        }
        
        int number = digits[index]-'0';
        string value = m[number];
        
        for(int i=0;i<value.length();i++)
        {
            s.push_back(value[i]);
            getcombi(digits,index+1,s,ans,m);
            s.pop_back();
            
        }
        
        
    }
    
    
    
};