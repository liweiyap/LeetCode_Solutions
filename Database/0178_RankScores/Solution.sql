# Runtime: 221 ms, faster than 92.45% of MySQL online submissions for Rank Scores.
# Memory Usage: 0B, less than 100.00% of MySQL online submissions for Rank Scores.

SELECT Score, CONVERT(@rank := CASE
    WHEN @cur = Score AND @rank <> 0 THEN @rank
    WHEN (@cur := Score) IS NOT NULL THEN @rank + 1
    END, SIGNED) AS Rank
FROM Scores, (SELECT @rank := 0, @cur := 0) tmp
ORDER BY Score DESC;
