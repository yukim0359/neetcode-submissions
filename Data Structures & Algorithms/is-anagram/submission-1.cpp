class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> mp;
        for (int i=0; i<s.size(); ++i){
            mp[s.at(i)]++;
        }
        for (int j=0; j<t.size(); ++j){
            mp[t.at(j)]--;
            if (mp[t.at(j)] == 0) mp.erase(t.at(j));
        }
        if (mp.empty()) return true;
        else return false;
    }
};
