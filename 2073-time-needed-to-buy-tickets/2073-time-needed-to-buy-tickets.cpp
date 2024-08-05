class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        
        int sec=0;
        
         while(true)
         {
             int a=0;
             
              if(a!=0 || tickets[k]==0)
             {
                 //cout<<"wfkhiuqwhefh\n";
                 break;
             }
             
             
             for(int i=0;i<tickets.size();i++)
             {
                
                 if(tickets[i]!=0)
                 {
                     //cout<<"i entered here\n";
                     sec++;
                     tickets[i]--;
                     if(i==k && tickets[i]==0)
                     {
                         a++;
                         break;
                     }
                     
                 }
                 
             }
             
             
            
             
         }
        
        
        return sec;
        
    }
};