class Solution {
public:
    bool doesAliceWin(string s) {

        int low=0;
        int high=0;
        int turn=0;


         int vowels=0;
         for(int i=0;i<s.length();i++)
         {

            if(s.at(i)=='a' || s.at(i)=='i' || s.at(i)=='e' || s.at(i)=='o' || s.at(i)=='u')
            {
                  vowels++;
                return true;
            }


         }

         cout<<"number of vowels are "<<vowels<<endl;



        
        return false;
    }


       
};