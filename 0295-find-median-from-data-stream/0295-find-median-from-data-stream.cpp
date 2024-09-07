
  
  
// Declaring ordered_set for pair<int,int> 
 

class MedianFinder {
public:
    
    multiset<double> s;
    
    
    
    MedianFinder() {
        
        s.clear();
       
        
    }
    
    void addNum(int num) {
        
        s.insert(num);
        
        
        
    }
    
    double findMedian() {
        
        int h = s.size();
        
        multiset<double>:: iterator it;
        it = s.begin();
        int a = h/2;
        
        if(h%2==0)
        {
             
            
            int i=1;
            while(i<a)
            {
                it++;
                i++;
            }
            
            double num1 = *it;
            it++;
            double num2 = *it;
            
            
            return (num1+num2)/2.0;
            
            
            

        }else{
            
            int i=0;
            
            while(i<a)
            {
                it++;
                i++;
            }
            
            return *it;
            
            
        }
        
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */