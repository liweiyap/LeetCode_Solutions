# Runtime: 506 ms, faster than 24.71% of MySQL online submissions for Classes More Than 5 Students.
# Memory Usage: 0B, less than 100.00% of MySQL online submissions for Classes More Than 5 Students.

SELECT class
FROM courses
GROUP BY class
HAVING COUNT(DISTINCT student) >= 5;
