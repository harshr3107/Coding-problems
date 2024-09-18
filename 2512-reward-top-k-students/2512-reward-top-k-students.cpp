/*class Solution {
public:
    
    class compare{
        
        public:
        
        bool operator()(pair<long long,long long>& a,pair<long long,long long>& b)
        {
            if(a.second==b.second)
            {
                return a.first<b.first;
            }
            
            return a.second>b.second;
            
        }
        
        
    };
    
    
    
    int gettotalocc2(string p ,string w)
    {
        
        
        int count=0;
        
       //cout<<"the val of index of firs occ is "<<p.find(w)<<endl;
        
        if(p.at(0)!=' ')
        {
            if(p.substr(0,w.length())==w)
            {
                count++;
            }
            
        }
        
        
        while(p.find(" "+w+" ")!=string::npos)
        {
             count++;
             p.erase(p.find(" "+w),w.length());
        }
            
        int i = p.length()-1;
        int a=0;
        while(i>=0 && p.at(i)!=' ')
        {
            i--;
        }
        
        
        
       if(p.substr(i+1)==w)
       {
           count++;
       }
         
            
            
            
        return count;
        
        
    }
    
    int gettotalocc(string p, string w) {
    int count = 0;
    size_t pos = 0;
    
    // Check for the word at the start
    if (p.substr(0, w.length()) == w && (p.length() == w.length() || p[w.length()] == ' ')) {
        count++;
    }
    
    // Check for occurrences in the middle with spaces around
    while ((pos = p.find(" " + w + " ", pos)) != string::npos) {
        count++;
        pos += w.length() + 1;
    }
    
    // Check for the word at the end
    if (p.length() >= w.length() && p.substr(p.length() - w.length()) == w && p[p.length() - w.length() - 1] == ' ') {
        count++;
    }
    
    return count;
}

    
    
    
    
    
    
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,compare> minheap;
        
        map<long long,long long> m;
        
        
        
        
        
        
        //first find positive feedback points
        
        for(int i=0;i<report.size();i++)
        {
            
            //map<string,int> cnt;
            
            
            
            for(auto it : positive_feedback)
            {
                if(report[i].find(it)!=string::npos)
                {
                    
                    int count = gettotalocc(report[i],it);
                    //cout<<"count of "<<it<<" is "<<count<<endl;
                    m[student_id[i]]+=(count*3);
                }
                
           }
            
            
            for(auto it : negative_feedback)
            {
                if(report[i].find(it)!=string::npos)
                {
                    int count = gettotalocc(report[i],it);
                   // cout<<"count of "<<it<<" is "<<count<<endl;
                    m[student_id[i]]-=(count);
                }
            }
            
            //cout<<endl;
        }
        
        
        for(auto it : m)
        {
           // cout<<it.first<<" "<<it.second<<endl;
            
            
             if(minheap.size()<k)
             {
                 minheap.push(make_pair(it.first,it.second));
             }else{
                 
                 if(minheap.top().second<it.second)
                 {
                     //cout<<"mai yaha aaya iskeliye\n";
                     minheap.pop();
                     minheap.push(make_pair(it.first,it.second));
                     
                 }else if(minheap.top().second == it.second && minheap.top().first>it.first)
                 {
                       minheap.pop();
                      minheap.push(make_pair(it.first,it.second));
                 }
                 
                 
             }
        }
        
        
        for(auto it : m)
        {
            minheap.push(make_pair(it.first,it.second));
            
        }
        
        while(!minheap.empty())
        {
            cout<<minheap.top().first<<" "<<minheap.top().second<<endl;  
            minheap.pop();
        }
        
        
        
        
        
        vector<int> ans;
        
       while(!minheap.empty())
        {
            ans.push_back(minheap.top().first);
            minheap.pop();
        }
        
        
       
        
        
        
        reverse(ans.begin(),ans.end());
        
        return ans;
        
        
        
        
        
        
        
        
        
    }
};*/


#define pp pair<int,int> 
class Solution {
public:

struct cmp{
    bool operator()(pp&p1, pp&p2){
        if(p1.first==p2.first){
            return p1.second>p2.second;
        }
        else return p1.first<p2.first;
    }
};

    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {

        int n = student_id.size(); //= report.size();
        int p = positive_feedback.size();
        int q = negative_feedback.size();

        unordered_map<string,int> pos;
        unordered_map<string,int> neg;

        for(int i=0; i<p; i++) pos[ positive_feedback[i] ] = 3;
        for(int i=0; i<q; i++) neg[ negative_feedback[i] ]= -1;
        
       priority_queue< pp, vector<pp>, cmp> pq;

        for(int i=0; i<n; i++){
            int score=0;
            int id = student_id[i];

                stringstream ss(report[i]);
                string word;
                while(ss>>word){
                    score=score+(pos[word]+neg[word]);
                }
            pq.push({score,id});
        }

        vector<int> rank;

        while(!pq.empty()){
            rank.push_back(pq.top().second);
            pq.pop();
            if(rank.size()==k) break;
        }
        return rank;  
    }
};


