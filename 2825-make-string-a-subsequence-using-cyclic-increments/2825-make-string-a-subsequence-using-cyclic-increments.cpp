/*class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        
        int i=0;
        
       
        
        while(i<str2.length())
        {
            //cout<<"the str1 is "<<str1<<endl;
            
            if(str1.length()==0)
            {
                return false;
            }
            
            char cur=str2.at(i);
            
            char cur2;
            
            if(cur=='a')
            {
                cur2='z';
            }else{
                char temp = cur;
                temp--;
                cur2=temp;
            }
            
           //cout<<"i am searching for "<<cur<<" "<<cur2<<endl;
            
            int a=-1;
            int b=-1;
            
            
            
            auto it = str1.find(cur);
            
            if(it!=string::npos)
            {
                a=it;
            }
            
            it = str1.find(cur2);
            
            if(it!=string::npos)
            {
                b=it;
            }
            
            if(a==-1 && b==-1)
            {
                return false;
            }
            
            
            if(a==-1)
            {
                
                str1 = str1.substr(b+1);
                
            }else if(b==-1){
                
                
                 str1 = str1.substr(a+1);
                
            }else{
                
                int h = min(a,b);
                
                str1=str1.substr(h+1);
                
            }
            
            
            i++;
            
            
            
        }
        
        
        
        return true;
        
    }
};*/

class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i = 0, j = 0;
        int n = str1.length(), m = str2.length();

        while (i < n && j < m) {
            char target = str2[j];
            char alternate = (target == 'a') ? 'z' : target - 1;

            // Check if the current character in str1 matches target or alternate
            if (str1[i] == target || str1[i] == alternate) {
                j++; // Move to the next character in str2
            }
            i++; // Move to the next character in str1
        }

        // If we've matched all characters in str2, return true
        return j == m;
    }
};
