#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    void getNext(int* next, const string& s) { // 构建next数组
        int j = -1;
        next[0] = j;
        for (int i = 1; i < s.size(); i++) {
            while (j >= 0 && s[i] != s[j + 1]) {
                j = next[j];
            }
            if (s[i] == s[j + 1]) {
                j++;
            }
            next[i] = j;
        }
    }

    bool repeatedSubstringPattern(string& s) {
        if (s.size() == 0) {
            return false;
        }
        const int lenStr = s.size();
        vector<int> next(lenStr);
        getNext(&next[0], s);
        int len = next[lenStr - 1] + 1;
        if (len >= 1 && len % (lenStr - len) == 0) {
            return true;
        } else {
            return false;
        }
    }
};