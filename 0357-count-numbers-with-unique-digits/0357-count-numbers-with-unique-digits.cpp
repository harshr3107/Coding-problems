class Solution {
public:
    
    
    void gettotal(int n,vector<bool>& visited,int cint,int& cans)
    {
        //cout<<"the current num is "<<cnum<<endl;
        
        if(cint==n)
        {
            
            return;
        }
            
        
        for(int i=0;i<=9;i++)
        {
            if((cint==0 && i==0) || visited[i]==true)
            {
                continue;
            }
            
            cans+=1;
            //cnum+=to_string(i);
            visited[i]=true;
            gettotal(n,visited,cint+1,cans);
            //cnum.pop_back();
            visited[i]=false;
            
        }
        
        
        
    }
    
    
    
    
    
    int countNumbersWithUniqueDigits(int n) {
        
        vector<bool> visited(10);
        //visited[0]=true;
        int cint=0;
        int cans=1;
        string cnum="";
        
       gettotal(n,visited,cint,cans);
        
        return cans;
        
    }
};