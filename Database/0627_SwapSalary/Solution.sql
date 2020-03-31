# Runtime: 140 ms, faster than 97.44% of MySQL online submissions for Swap Salary.
# Memory Usage: 0B, less than 100.00% of MySQL online submissions for Swap Salary.

UPDATE salary
SET sex = CASE WHEN sex = 'm' THEN 'f'
               WHEN sex = 'f' THEN 'm'
          END;
