class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
    
       
        
        if(k==0)
        {
            
             vector<int> v(code.size(),0);
             return v;
        }
        
         vector<int> v;
        
        
        if(k>0)
        {
            
            int csum=0;
            int a=0;
            int cindex=1;
            int init=1;
            while(a!=k)
            {
                csum+=code[cindex];
                a++;
                cindex=(cindex+1)%(code.size());
                //cout<<"the val of cindex is "<<cindex<<endl;
                
            }
            
         
            
            for(int i=0;i<code.size();i++)
            {
                //cout<<"i also came here\n";
                
                v.push_back(csum);
                csum=csum-code[init];
                init=(init+1)%(code.size());
                csum+=code[cindex];
                cindex=(cindex+1)%(code.size());
                 //cout<<"the val of cindex is "<<cindex<<endl;
                
            }
            
            
            return v;
            
            
        }else{
            
            int csum=0;
            int a=0;
            int cindex=code.size()-abs(k);
            int init=code.size()-abs(k);
            while(a!=abs(k))
            {
                csum+=code[cindex];
                a++;
                cindex=(cindex+1)%(code.size());
               // cout<<"the val of cindex is "<<cindex<<endl;
                
            }
            
             
            
            for(int i=0;i<code.size();i++)
            {
               // cout<<"i also came here for "<<cindex<<" "<<init<<endl;
                
                v.push_back(csum);
                csum=csum-code[init];
                //cout<<"now csum is "<<csum<<endl;
                init=(init+1)%(code.size());
                
                csum+=code[cindex];
                cindex=(cindex+1)%(code.size());
                 //cout<<"now csum is "<<csum<<endl;
                
                 //cout<<"the val of cindex is "<<cindex<<endl;
                
            }
            
            
            return v;
            
            
            
            
            
            
            
            
            
            
            
            
        }
        
        
        
      return v;  
        
    }
};