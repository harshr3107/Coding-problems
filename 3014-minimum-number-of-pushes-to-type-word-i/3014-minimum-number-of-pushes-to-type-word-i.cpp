class Solution {
public:
    int minimumPushes(string word) {
        
        
        
       
       
        int a=0;
        int push=0;
        
        for(int i=0;i<word.size();i++)
        {
           
            
            
                a++;
                if(a<=8)
                {
                   
                    push++;
                    
                    
                }else if(a<=16)
                {
                      
                        push+=2;
                        
                }else if(a<=24)
                {
                        
                        push+=3;
                }else{
                        
                       
                        push+=4;
                }
                    
                    
                    
                    
       }
                
            
            
        
        
        
        
        return push;
        
        
    }
};