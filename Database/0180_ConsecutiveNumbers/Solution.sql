# Runtime: 406 ms, faster than 67.38% of MySQL online submissions for Consecutive Numbers.
# Memory Usage: 0B, less than 100.00% of MySQL online submissions for Consecutive Numbers.

SELECT DISTINCT erste.Num AS ConsecutiveNums
FROM Logs erste
INNER JOIN Logs zweite ON erste.Id + 1 = zweite.Id AND erste.Num = zweite.Num
INNER JOIN Logs dritte ON zweite.Id + 1 = dritte.Id AND zweite.Num = dritte.Num;
