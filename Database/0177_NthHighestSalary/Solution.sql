# Runtime: 249 ms, faster than 59.64% of MySQL online submissions for Nth Highest Salary.
# Memory Usage: 0B, less than 100.00% of MySQL online submissions for Nth Highest Salary.

CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  DECLARE I INT;
  SET I = N-1;
  RETURN (
      SELECT DISTINCT Salary
      FROM Employee
      ORDER BY SALARY DESC
      LIMIT 1 OFFSET I
  );
END
