class Solution {
public:
    int lengthOfLastWord(string s) {
        //leet-sync

    int i= s.size()-1;
    int length =0; //inital len at 0

    while( s[i] == ' '){

        i-- ;
    }

    while( i>= 0 && s[i] != ' '){

        length++;
        i--;
    }

    return length; 
    }
};