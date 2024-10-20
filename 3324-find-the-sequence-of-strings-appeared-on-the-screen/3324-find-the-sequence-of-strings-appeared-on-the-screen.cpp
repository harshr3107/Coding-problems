class Solution {
public:
    vector<string> stringSequence(string target) {
        
        vector<string> ans;
        
        string str="";
        
        int i=0;
        while(i<target.length())
        {
            //cout<<"the cur str is "<<str<<endl;
            
            char k='a';
            while(k<=target.at(i))
            {
                string temp = str;
                temp+=k;
                 //cout<<"i made "<<temp<<endl;
                ans.push_back(temp);
                k++;
            }
            
            str+=target.at(i);
            i++;
        }
        
        
        return ans;
        
    }
};