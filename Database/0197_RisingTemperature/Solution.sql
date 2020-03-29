# Runtime: 462 ms, faster than 59.97% of MySQL online submissions for Rising Temperature.
# Memory Usage: 0B, less than 100.00% of MySQL online submissions for Rising Temperature.

SELECT A.Id
FROM Weather A
INNER JOIN Weather B
ON B.RecordDate = DATE_SUB(A.RecordDate, INTERVAL 1 DAY)
AND A.Temperature > B.Temperature;
