class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        
        vector<int> ans;
        stack<int> st;
       
        
       for(int i=0;i<asteroids.size();i++)
       {
           if(st.empty() || asteroids[i]>=0)
           {
               st.push(asteroids[i]);
           }else{
               
               if(st.top()<0)
               {
                   st.push(asteroids[i]);
               }else{
                   
                   int a=0;
                   
                   while(!st.empty() && st.top()>0 && abs(asteroids[i])>=st.top())
                   {
                       if(abs(asteroids[i])==st.top())
                       {
                           a++;
                           st.pop();
                           break;
                       }
                       
                       st.pop();
                   }
                   
                   
                   if((st.empty() || st.top()<0) && a==0)
                   {
                       st.push(asteroids[i]);
                   }
                   
                   
                   
                   
               }
               
               
               
               
               
               
           }
           
           
           
       }
        
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        
        
        
        
        return ans;
        
        
        
    }
};