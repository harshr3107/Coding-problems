class Solution {
public:
    int bitwiseComplement(int n) {
        
        if(n==0)
        {
            return 1;
        }
        
        int answer=0;
        int digit=0;
        int s=0;
        int ans=0;
        while(n>0)
        {
            digit=n&1;
            if(digit==0)
            {
                //ans=ans+1*pow(10,s);
                answer   = answer+pow(2,s);
            }
            
            n=n>>1;
            s++;
            
        }
        
        //cout<<"value of compliment is "<<ans<<endl;
        
        /*int a=1;
        int answer=0;
        
        while(ans>0)
        {
            digit=ans%10;
            answer=answer+a*digit;
            a=a*2;
            ans/=10;
            
        }*/
       
       // cout<<"value of final answer is "<<answer<<endl;
        
        return answer;
    }
};