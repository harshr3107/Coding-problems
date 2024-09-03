class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        
        //long long sum = accumulate(chalk.begin(),chalk.end(),(ll)0);
        long long sum = accumulate(chalk.begin(),chalk.end(),0LL);
        
        
        k=k%sum;
        
       for(int i=0;i<chalk.size();i++)
        {
            k=k-chalk[i];
            if(k<0)
            {
                return i;
            }
            
        }
        
       
        return 0;
        
    }
};