// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Game of Life.
// Memory Usage: 7.7 MB, less than 100.00% of C++ online submissions for Game of Life.

#include <vector>
#include <algorithm>

class Solution
{
public:
    void gameOfLife(std::vector<std::vector<int>>& board)
    {
        for (int rowNr = 0; rowNr < board.size(); ++rowNr)
        {
            for (int colNr = 0; colNr < board[0].size(); ++colNr)
            {
                int ns = neighbourSum(board, rowNr, colNr);
                if ((ns | board[rowNr][colNr]) == 3)  // short, elegant condition that covers all 4 rules
                {
                    board[rowNr][colNr] |= 2;  // 2nd bit to store new state
                }
            }
        }
        
        for (int rowNr = 0; rowNr < board.size(); ++rowNr)
        {
            for (int colNr = 0; colNr < board[0].size(); ++colNr)
            {
                board[rowNr][colNr] >>= 1;  // remove old state
            }
        }
    }
    
    int neighbourSum(std::vector<std::vector<int>>& board, int rowNr, int colNr)
    {
        int sum = 0;
        for (int y = std::max(rowNr-1, 0); y < std::min(rowNr+2, static_cast<int>(board.size())); ++y)
        {
            for (int x = std::max(colNr-1, 0); x < std::min(colNr+2, static_cast<int>(board[0].size())); ++x)
            {
                sum += board[y][x] & 1;  // "& 1" because of the bitwise OR update in "gameOfLife" function
            }
        }
        return sum -= board[rowNr][colNr] & 1;
    }
};
