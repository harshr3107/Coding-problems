class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        
        float a = rolls.size();
        float sum = accumulate(rolls.begin(),rolls.end(),0);
        
        float totalsize = a+n;
        
        float h = (mean*totalsize)-sum;
        
        //cout<<"value of h is "<<h<<endl;
        //cout<<"value of n is "<<n<<endl;
        
       
        
        
        
        vector<int> v;
        int k=n;
        for(int i=0;i<n;i++)
        {
            if(ceil(h/k)>6 || floor(h/k)<=0)
            {
                return v;
                
            }else{
                
                int c = h/k;
                v.push_back(c);
                h=h-c;
                k=k-1;
                
            }
        }
        
        
        
        return v;
        
    }
};