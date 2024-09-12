class Solution {
public:
    double average(vector<int>& salary) {
        
        if(salary.size()<=2)
        {
            return 0;
        }
        
        
        priority_queue<double> maxheap;
        
        for(int i=0;i<salary.size();i++)
        {
            maxheap.push(salary[i]);
        }
        
        maxheap.pop();
        double sum=0;
        double a=0;
        
        while(maxheap.size()>1)
        {
            sum+=maxheap.top();
            maxheap.pop();
            a++;
        }
        
        
        
        
        return sum/a;
        
        
    }
};