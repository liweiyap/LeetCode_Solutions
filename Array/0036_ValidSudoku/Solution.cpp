// Runtime: 28 ms, faster than 10.17% of C++ online submissions for Valid Sudoku.
// Memory Usage: 8.5 MB, less than 100.00% of C++ online submissions for Valid Sudoku.

#include <cassert>
#include <vector>

class Solution
{
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board)
    {
        assert(board.size() == 9);  // no. of columns
        assert(board[0].size() == 9);  // no. of rows
        
        for (auto row : board)
        {
            if (!isValidRow(row))
            {
                return false;
            }
        }
        
        for (size_t colIdx = 0; colIdx < 9; ++colIdx)
        {
            if (!isValidCol(board, colIdx))
            {
                return false;
            }
        }
        
        for (size_t rowIdx = 0; rowIdx < 9; rowIdx += 3)
        {
            for (size_t colIdx = 0; colIdx < 9; colIdx += 3)
            {
                if (!isValidSubBox(board, rowIdx, colIdx))
                {
                    return false;
                }
            }
        }
        
        return true;
    }
    
private:
    bool isValidRow(std::vector<char>& row)
    {
        std::vector<bool> truth(9, false);
        for (char val : row)
        {
            if (wrongDigits(truth, val))
            {
                return false;
            }
        }
        return true;
    }
    
    bool isValidCol(std::vector<std::vector<char>>& board, size_t colIdx)
    {
        assert(colIdx < 9);
        std::vector<bool> truth(9, false);
        for (auto row : board)
        {
            char val = row[colIdx];
            if (wrongDigits(truth, val))
            {
                return false;
            }
        }
        return true;
    }
    
    bool isValidSubBox(std::vector<std::vector<char>>& board, size_t topRowIdx, size_t leftColIdx)
    {
        std::vector<bool> truth(9, false);
        for (size_t rowIdx = topRowIdx; rowIdx < topRowIdx + 3; ++rowIdx)
        {
            for (size_t colIdx = leftColIdx; colIdx < leftColIdx + 3; ++colIdx)
            {
                char val = board[rowIdx][colIdx];
                if (wrongDigits(truth, val))
                {
                    return false;
                }
            }
        }
        return true;
    }
    
    bool wrongDigits(std::vector<bool>& truth, const char val)
    {
        assert(truth.size() == 9);  // sudoku is a game with digits 1 to 9
        if (val != '.')
        {
            int idx = val - '1';
            if (idx < 0 || idx > 8 || truth[idx])  // out of range OR repetition of val in row
            {
                return true;
            }
            truth[idx] = true;
        }
        return false;
    }
};
