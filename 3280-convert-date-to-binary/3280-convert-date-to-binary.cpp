class Solution {
public:
    
    string convertDateToBinary(string date) {
        
       int year = stoi(date.substr(0,4));
        int month = stoi(date.substr(5,2));
        int day = stoi(date.substr(8,2));
        
        
        string yearbinary="";
        string monthbinary="";
        string daybinary="";
        
        while(year>0)
        {
            int digit = year&1;
            yearbinary=to_string(digit)+yearbinary;
            year=(year>>1);
            
        }
        
         
        while(month>0)
        {
            int digit = month&1;
            monthbinary=to_string(digit)+monthbinary;
            month=(month>>1);
            
        }
        
        while(day>0)
        {
            int digit = day&1;
            daybinary=to_string(digit)+daybinary;
            day=(day>>1);
            
        }
        
        
        return yearbinary+"-"+monthbinary+"-"+daybinary;
        
        
        
    }
};