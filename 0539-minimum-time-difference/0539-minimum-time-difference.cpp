class Solution {
public:
    int findMinDifference(vector<string>& ts) {
        
        sort(ts.begin(),ts.end());
        
        
        int ansdif=INT_MAX;
        
    string s1 = ts[0];
    string s2= ts[ts.size()-1];
        
      int h1 = stoi(s1.substr(0,2));
      int h2 = stoi(s2.substr(0,2));
        
      int m1 = stoi(s1.substr(3,2));  
      int m2 = stoi(s2.substr(3,2));
        
        int hrdif = 23-h2+h1;
        int mindif = 60-m2+m1;
        ansdif = min(ansdif,hrdif*60+mindif);
        
        //cout<<hrdif*60+mindif<<" "<<hrdif<<" "<<mindif<<endl<<endl;
        
        //cout<<ansdif<<endl;
        //cout<<h1<<" "<<m1<<"\n"<<h2<<" "<<m2<<endl;
       
        
        int i=0;
        int j=1;
        while(j<ts.size())
        {
            h1 = stoi(ts[i].substr(0,2));
            h2 = stoi(ts[j].substr(0,2));
            m1 = stoi(ts[i].substr(3,2));  
            m2 = stoi(ts[j].substr(3,2));
            
            hrdif = h2-h1-1;
            mindif = 60-m1+m2;
            
            //cout<<hrdif<<" "<<mindif<<endl;
            
            ansdif = min(ansdif,hrdif*60+mindif);
            
            
            i++;
            j++;
            
        }
        
        
        return ansdif;
        
    }
};