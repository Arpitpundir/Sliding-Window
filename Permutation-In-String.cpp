class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size(), s1AsciSum = 0;
        unordered_map<char, int> charFreMap1, charFreMap2;

        for(int i=0;i<n1;i++){
            s1AsciSum+=(s1[i]);
            charFreMap1[s1[i]]++;
        }

        int stPtr = 0, endPtr = 0, windowAsciSum = 0;
        bool ans = false;

        while(endPtr < n2){

          // increase value of endPtr in every iteration
            windowAsciSum+=(s2[endPtr]);
            charFreMap2[s2[endPtr]]++;

            // make initial window of size n1
            if(endPtr-stPtr+1 < n1){
                endPtr++;
                continue;
            }

            // if current window ascii sum is equal to s1 ascii sum
            if(windowAsciSum == s1AsciSum){
              // check if frequency of each character is same or not
                for(int i=0; i<27;i++){
                    if(charFreMap1['a'+i] == charFreMap2['a'+i]){
                        ans = true;
                    }else{
                        ans = false;
                        break;
                    }
                }
            }
            // if current window ascii sum is not equal to s1 ascii sum
            // remove first character from window and add next character
            if(ans == false){
                charFreMap2[s2[stPtr]]--;
                windowAsciSum-=(s2[stPtr]);
                stPtr++;
                endPtr++;
            }else {
                return true;
            }
        }
        return ans;
    }
};