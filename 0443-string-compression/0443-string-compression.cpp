class Solution {
public:
    int compress(vector<char>& chars) {
        
        int i=1;
        int currentpos=0;
        int num=1;
        
        while(i<=chars.size())
        {
            //cout<<"value of num at index "<<i<<" is "<<num<<endl;
            
            if(i<chars.size() && chars.at(i)==chars.at(i-1))
            {
                num++;
                i++;
                continue;
            }else{
                
                //cout<<"i entered here for number "<<num<<" character "<<chars.at(i-1)<<endl;
                if(num==1)
                {
                    chars[currentpos]=chars.at(i-1);
                    currentpos++;
                    num=1;
                   
                }else{
                    
                    //if there are multiple value of the given 
                    chars[currentpos]=chars.at(i-1);
                    currentpos++;
                    string numstr = to_string(num);
                    int j=0;
                    while(j<numstr.length())
                    {
                        chars[currentpos]=numstr.at(j);
                        currentpos++;
                        j++;
                        
                    }
                    
                    num=1;
                }
                
                i++;
                }
            
            
            
        }
        
       
        
        return currentpos;
        
        
        
        
    }
};