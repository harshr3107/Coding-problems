
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        
        unordered_map<int,int> row;
        unordered_map<int,int> col;
        
        unordered_map<int,pair<int,int>> mp;
        
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[i].size();j++)
            {
                mp[mat[i][j]]=make_pair(i,j);
                
            }
            
        }
        
        
        for(int i=0;i<arr.size();i++)
        {
            pair<int,int> temp = mp[arr[i]];
            //cout<<temp.first<<" "<<temp.second<<endl;
            row[temp.first]++;
            col[temp.second]++;
            
            if(row[temp.first]==mat[temp.first].size() || col[temp.second]==mat.size())
            {
                return i;
            }
            
        }
        
        
        
        return -1;
        
    }
};