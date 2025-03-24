class Solution {
public:
    bool detectCapitalUse(string word) {
        bool allCaps = true, allSmall = true, firstCapOnly = true;

        for (int i = 0; i < word.size(); i++) {
            if (!(word[i] >= 'A' && word[i] <= 'Z')) allCaps = false;
            if (!(word[i] >= 'a' && word[i] <= 'z')) allSmall = false;
            if (i > 0 && !(word[i] >= 'a' && word[i] <= 'z')) firstCapOnly = false;
        }

        return allCaps || allSmall || firstCapOnly;
    }

};