class Solution {
public:
    string minWindow(string s, string t) {
        int n1 = s.size(), n2 = t.size();
        unordered_map<char, int> wndMap, tMap;
        int wndSt = 0, wndEnd = 0, ans = INT_MAX, ansSt = -1, ansEnd = -1, found = 0, required = t.size();

        for(int i=0;i<n2;i++){
            tMap[t[i]]++;
        }

        while(wndEnd<n1){
            char currentChar = s[wndEnd];
            wndMap[currentChar]++;
            if(tMap.count(currentChar) && tMap[currentChar] >= wndMap[currentChar]){
              // if curr char is present in t and its frequency is less than or equal to its frequency in current window
              // then we have found one of the char in t
              // but if currChar is not in t or is present in t but its wnd frequency is greater than required
              // then we have not found a char in t
                found++;
            }
            while(found == required && wndSt <= wndEnd){
                char wndStartChar = s[wndSt];
                if(found == required && tMap.count(wndStartChar) && tMap[wndStartChar] == wndMap[wndStartChar]){
                  /* if found is same as t's len curr char is present in t and its frequency is equal as
                      it is required then this is the min window possible for now so calculate an */
                    if((wndEnd - wndSt+1) < ans){
                        ans = wndEnd -wndSt+1;
                        ansSt = wndSt;
                        ansEnd = wndEnd;
                    }
                }

                if(tMap[wndStartChar] == wndMap[wndStartChar]){
                  /* if char we removed was required one then we have lost a found  */
                    found--;
                }

                wndSt++;
                wndMap[wndStartChar]--;
            }
            wndEnd++;
        }
        if(ansSt == -1) return "";
        return s.substr(ansSt, ans);
    }
};