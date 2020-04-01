# Runtime: 174 ms, faster than 57.62% of MySQL online submissions for Not Boring Movies.
# Memory Usage: 0B, less than 100.00% of MySQL online submissions for Not Boring Movies.

SELECT *
FROM cinema
WHERE MOD(id, 2) = 1 AND description <> 'boring'
ORDER BY rating DESC;
