class Solution {
public:
    int minQueenMoves(vector<int>& source, vector<int>& target) {

        int sr = source[0];
        int sc = source[1];

        int tr = target[0];
        int tc = target[1];

        // Same position
        if(sr == tr && sc == tc)
            return 0;

        // Same row OR same column
        else if(sr == tr || sc == tc)
            return 1;

        // Same diagonal
        else if(abs(sr - tr) == abs(sc - tc))
            return 1;

        // Otherwise, 2 moves are enough
        else
            return 2;
    }
};