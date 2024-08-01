class Solution {
public:
    int countSeniors(vector<string>& details) {
        
        int a=0;
        int age;
        
        for(int i=0;i<details.size();i++)
        {
            age = stoi(details[i].substr(11,2));
            //cout<<"age of the citizen is "<<age<<endl;
            if(age>60)
            {
                a++;
            }
        }   
            
        return a;
    }
};