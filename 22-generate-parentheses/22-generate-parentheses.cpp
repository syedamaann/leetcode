class Solution {public:
    vector<string> generateParenthesis(int n) {
        solve (0,0,n,"");
        return res;
    }
    void solve(int p,int c,int lim,string s){
        if(p==c && p==lim){
            res.push_back(s);
        }else if(p==c && p<lim){
            s.push_back('(');
            solve (++p,c,lim,s);
        }else if(p>=c){
            if(p==lim){
                s.push_back(')');
                solve (p,++c,lim,s);
            }else{
                s.push_back(')');
                solve (p,++c,lim,s);
                s.pop_back();
                s.push_back('(');
                c--;
                solve (++p,c,lim,s);
            }
        }
    }
    vector<string> res;
};