# Runtime: 187 ms, faster than 60.73% of MySQL online submissions for Second Highest Salary.
# Memory Usage: 0B, less than 100.00% of MySQL online submissions for Second Highest Salary.

SELECT IFNULL
(
    (
        SELECT DISTINCT Salary
        FROM Employee
        ORDER BY Salary DESC
        LIMIT 1 OFFSET 1
    ), NULL
) AS SecondHighestSalary;
