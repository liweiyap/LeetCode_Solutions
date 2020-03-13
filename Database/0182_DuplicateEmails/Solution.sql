# Runtime: 216 ms, faster than 81.11% of MySQL online submissions for Duplicate Emails.
# Memory Usage: 0B, less than 100.00% of MySQL online submissions for Duplicate Emails.

SELECT Email
FROM Person
GROUP BY Email
HAVING COUNT(DISTINCT id) > 1;
