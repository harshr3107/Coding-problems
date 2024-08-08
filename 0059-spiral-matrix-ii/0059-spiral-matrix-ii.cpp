class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> v;
        
        for(int i=0;i<n;i++)
        {
            vector<int> v2(n);
            v.push_back(v2);
            v2.clear();
            
        }
        
        int rowstart=0;
        int colstart=0;
        int rowend=n-1;
        int colend=n-1;
        
        int a=1;
        
        while(rowend>=rowstart && colend>=colstart)
        {
            
            
            for(int i=colstart;i<=colend;i++)
            {
                v[rowstart][i]=a;
                a++;
            }
            
           rowstart++;
            
            
            for(int i=rowstart;i<=rowend;i++)
            {
                v[i][colend]=a;
                a++;
            }
            
            
            colend--;
            
            
            for(int i=colend;i>=colstart;i--)
            {
                v[rowend][i]=a;
                a++;
            }
            
            rowend--;
            
            for(int i=rowend;i>=rowstart;i--)
            {
                v[i][colstart]=a;
                a++;
            }
            
            colstart++;
            
        }
        
        
        
        return v;
    }
};