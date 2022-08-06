typedef unordered_map<int, unordered_set<int>> um_i_us;
typedef unordered_map<string, unordered_set<int>> um_str_us;
typedef unordered_set<int> us_i;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& b) {
        um_i_us rows(9);
        um_i_us cols(9);
        um_str_us mp(9);
        for(int i=0; i < 9; i++) rows[i] = us_i(9);
        for(int i=0; i < 9; i++) cols[i] = us_i(9);
        int m = b.size(), n = b[0].size();
        for(int i=0; i<m; i++){
            for(int j = 0; j < n; j++){
                if(b[i][j] == '.') continue;
                
                string k = to_string(i/3)+""+to_string(j/3);
                if(!mp.count(k))mp[k] = us_i(9);

                if(rows[i].count(b[i][j]) || 
                    cols[j].count(b[i][j])||
                    mp[k].count(b[i][j])) return false;
                
                rows[i].insert(b[i][j]);
                cols[j].insert(b[i][j]);
                mp[k].insert(b[i][j]);
            }
        }
        return true;
    }
};