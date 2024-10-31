class Solution {
public:
    int possibleStringCount(string word) {
       
        
        int i=0;
        int j=0;
        
        int ans=1;
        
        
        while(i<word.length())
        {
            char a = word.at(i);
            int count=0;
            j=i+1;
            while(j<word.length() && word.at(j)==a)
            {
                j++;
                count++;
            }
            
            
            ans+=count;
            i=j;
        }
        
        
        return ans;

            
        
    }
};