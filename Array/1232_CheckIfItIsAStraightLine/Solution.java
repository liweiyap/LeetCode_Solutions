// Runtime: 0 ms, faster than 100.00% of Java online submissions for Check If It Is a Straight Line.
// Memory Usage: 41.2 MB, less than 100.00% of Java online submissions for Check If It Is a Straight Line.

class Solution
{
    public boolean checkStraightLine(int[][] coordinates)
    {
        double oldGradient = 1.0 * (coordinates[1][1] - coordinates[0][1]) / (coordinates[1][0] - coordinates[0][0]);
        for (int i = 2; i < coordinates.length; ++i)
        {
            double gradient = 1.0 * (coordinates[i][1] - coordinates[0][1]) / (coordinates[i][0] - coordinates[0][0]);
            if (gradient != oldGradient)
            {
                return false;
            }
        }
        return true;
    }
}