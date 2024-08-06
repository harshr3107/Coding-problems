class Solution {
public:
    int minimumPushes(string word) {
        
        
        
        map<int,int> m1;
        map<char,int> m2;
        int a=0;
        int push=0;
        
        for(int i=0;i<word.size();i++)
        {
            m1[word.at(i)]++;
            
            if(m1[word.at(i)]==1)
            {
                a++;
                if(a<=8)
                {
                    m2[word.at(i)]=1;
                    push++;
                    
                    
                }else{
                    //cout<<"mai yah aaya hoon bhai\n";
                   
                    
                    if(a<=16)
                    {
                        m2[word.at(i)]=2;
                        push+=2;
                        
                    }else if(a<=24)
                    {
                        m2[word.at(i)]=3;
                        push+=3;
                    }else{
                        
                        m2[word.at(i)]=4;
                        push+=4;
                    }
                    
                    
                    
                    
                }
                
            }else{
                
                
                push+=m2[word.at(i)];
                
            }
            
        }
        
        
        
        return push;
        
        
    }
};