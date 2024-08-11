class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        
        int i=0;
        int j=0;
        
        for(int k=0;k<commands.size();k++)
        {
            if(commands[k].starts_with('R'))
            {
               // cout<<"i am right\n";
                j++;
            
            }else if(commands[k].starts_with('L'))
            {
                //cout<<"i am left\n";
                j--;
                
            }else if(commands[k].starts_with('D'))
            {
                //cout<<"i am down\n";
                
                i++;
                //cout<<"value of i is "<<i<<endl;
                
            }else{
                
                //cout<<"i am up\n";
                
                i--;
            }
            
        }
        
        //cout<<"value of i is "<<i<<" "<<j<<endl;
        
        return (i*n)+j;
        
    }
};