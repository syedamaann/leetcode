using namespace std;
class Solution {
    
    vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
public:
    

    void recurse(const string digits, vector<string>& ans, string& interim) {
        
        if(digits.empty())
        {
            ans.push_back(interim); 
            return;
        }
        
        const char& digit = digits.at(0);
        uint64_t mapping_pos = digit - '0';
        for(const char& c: mapping[mapping_pos])
        {
            interim.push_back(c);
            recurse( digits.substr(1), ans, interim);
            interim.pop_back();
        }
        
    }
    
    vector<string> letterCombinations(string digits) {
    
        vector<string> ans{};
        string empty;
        if(!digits.empty()) {
            recurse(digits, ans, empty);
        }
        return ans;

    }
};