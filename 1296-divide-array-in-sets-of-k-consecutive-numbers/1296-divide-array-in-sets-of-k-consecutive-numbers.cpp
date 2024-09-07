class Solution {
public:
    bool isPossibleDivide(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0)return false;
        map<int,int> umap;
        for(int i=0; i<hand.size(); i++){
            umap[hand[i]]++;
        }
        int start = 0;
        int curr;
        while(umap.size()>0){
            curr = umap.begin()->first;
            for(int i=0; i<groupSize; i++){
                if(umap[curr+i] == 0)return false;
                --umap[curr+i];
                if(umap[curr+i] == 0)umap.erase(curr+i);
            }
        }
        return true;
    }
};