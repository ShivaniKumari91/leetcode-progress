class Solution {
public:
    int minQueenMoves(vector<int>& source, vector<int>& target) {
        int sr = source[0];
        int sc = source[1];

        int tr = target[0];
        int tc = target[1];

        if(sr == tr && sc == tc) return 0;

        else if(sr == tr || sc == tc) return 1;

        else if(abs(sr-tr) == abs(sc-tc)) return 1;

        else return 2;
        
    }
};