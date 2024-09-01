/*
 * @lc app=leetcode id=809 lang=cpp
 *
 * [809] Expressive Words
 */

// @lc code=start

#define DEBUG 1

#if(DEBUG)
#include <iostream>
#include <vector>
using namespace std;
#endif

class Solution {
public:

    bool isCharCountNotPossible(vector<int>& smap, vector<int>& tmap) {

        for(int i = 0; i < 26; i++) {
            if(tmap[i] == 0 && smap[i] != 0) {
                return true;
            }
        }
        return false;
    }

    string getsubs(string str, int sidx) {

        int i = sidx;
        char c = str[i];
        int len = 0;

        while(str[i] == c && (str[i] !='\0')) {
            len++;
            i++;
        }

        return str.substr(sidx, len);

    }
    int expressiveWords(string str, vector<string>& words) {
        
        vector<int> smap(26,0);
        int count = 0;

        for(char c : str) {
            smap[c-'a']++;
        }

        for(string word : words) {
            cout << word << endl;

            // 1. check if word atleast contains one char count 
            vector<int> tmap(26,0);
            for(char c : word) {
                tmap[c - 'a']++;
            }

            if(isCharCountNotPossible(smap, tmap)) {
                continue;
            }

            // 2. If word size is more, then already stretched but not properly done
            if(str.size() < word.size()) {
                continue;
            }

            // 3. Traverse and check the window of each continuous char 
            bool flag = false;

            int sp = 0;
            int tp = 0;

            while(sp < str.size() && tp < word.size()) {

                // needed?
                if(flag) {
                    break;
                }

                string ssub = getsubs(str, sp);

                // if window of word is different from str itself
                if(ssub[0] != word[tp]) {
                    flag = true;
                    break;
                }

                string tsub = getsubs(word, tp);

                // check conditions [IMPORTANT]
                if(ssub.size() < tsub.size()) {
                    flag = true;
                    break;
                }

                if(ssub.size() == 2 && tsub.size() == 1) {
                    flag = true;
                    break;
                }
                
                cout << ssub << " " << tsub << endl; 

                // move to next window if successful
                sp = sp + ssub.size();
                tp = tp + tsub.size();
            }

            // case of not satisfy
            if(flag) {
                continue;
            }

            // if either one of not traversed completely, then not satisfy
            if(sp < str.size() || tp < word.size()) {
                continue;
            }

            // finally we reach here and increment the counter
            count++;
        }

        return count;
    }
};



#if(DEBUG)
int main()
{

    class Solution* sol = new Solution();

    string s = "heeellooo";

    vector<string> words;
    words.push_back("hello");
    words.push_back("hi");
    words.push_back("helo");

    cout << sol->expressiveWords(s, words);
}
#endif
// @lc code=end

