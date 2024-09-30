class Solution {
public:
    vector<int> dir = {-1, 0, 1, 0, -1};

    bool worker(vector<vector<char>>& board, string word,int k, int i, int j)
    {
        if(k==word.size())
            return true;

        if(i>= board.size() || i<0 || j>=board[0].size() || j<0)
            return false;
        
        if(word[k] != board[i][j])
            return false;

        char t = board[i][j];
        board[i][j] = '*';

        for(int x=0; x+1<dir.size(); x++)
        {
           if(worker(board, word, k+1, i + dir[x], j + dir[x+1])) return true;
        }

        board[i][j] = t;

        return false; 
    }

    bool exist(vector<vector<char>>& board, string word) {
        
        int n = board.size();
        int m = board[0].size();

        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                 if(worker(board,word,0,i,j))
                    return true;
            }
        }
        return false;
    }
};