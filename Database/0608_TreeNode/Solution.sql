# Runtime: 355 ms, faster than 96.02% of MySQL online submissions for Tree Node.
# Memory Usage: 0B, less than 100.00% of MySQL online submissions for Tree Node.

SELECT id,
       (CASE WHEN p_id IS NULL THEN "Root"
             WHEN id IN (SELECT p_id FROM Tree) THEN "Inner"
             ELSE "Leaf"
        END) AS type
FROM Tree