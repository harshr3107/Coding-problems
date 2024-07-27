class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
         int i=0;
        int count=0;
        
        
        if(flowerbed.size()==1 && flowerbed[0]==0)
        {
            return true;
        }
        
        
        if(flowerbed.size()>=2 && flowerbed[0]==0 && flowerbed[1]==0)
        {
            count++;
            flowerbed[0]=1;
            i++;
        }
        
        i=1;
        int j=i;
        
        while(i<flowerbed.size()-1)
        {
            
            if(flowerbed[i]==0 && flowerbed[i]==flowerbed[i-1] && flowerbed[i]==flowerbed[i+1])
            {
                count++;
                flowerbed[i]=1;
                i++;
            }
            
            i++;
            
            
        }
        
        if( flowerbed.size()>=2 && flowerbed[flowerbed.size()-2]==0 && flowerbed[flowerbed.size()-1]==0)
        {
            count++;
        }
        
        
        if(count>=n)
        {
            return true;
        }
        
        return false;
        
        
    }
};