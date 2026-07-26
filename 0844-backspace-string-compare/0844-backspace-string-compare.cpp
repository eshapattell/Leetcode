class Solution {
public:
    bool backspaceCompare(string s, string t) {
        //starting from the end
        int i= s.size()-1;
        int j =t.size()-1;

        //keeping the track of '#' count
        int skipS=0;
        int skipT=0;

        //till both the string are processed
        while(i>=0 || j>=0){
            //find the next valid charcter in s
            while(i>=0){
                //inc the skip count and dec the pointer
                if(s[i]=='#'){
                    skipS++;
                    i--;
                }
                //if characters are there to skip, skip the curr
                else if(skipS > 0){
                    skipS--;
                    i--;
                }
                //currr is valid
                else{
                    break;
                }
            }
            //find the next valid charcter in s
            while(j>=0){
                //inc the skip count and dec the pointer
                if(t[j]=='#'){
                    skipT++;
                    j--;
                }
                //if characters are there to skip, skip the curr
                else if(skipT > 0){
                    skipT--;
                    j--;
                }
                //curr is valid
                else{
                    break;
                }
            }
            //if both the pointers are valid, compare them
            if(i >=0 && j >=0){
                if(s[i] != t[j]){
                    return false;
                }
            }
            //if one has character left and the other dont they cant be valid
            else if( i >=0 || j >= 0){
                return false;
            }
            //move to the prev character of the strings
            i--;
            j--;
        }
        //all valid characters matched
        return true;
    }
};