# Runtime: 365 ms, faster than 65.68% of MySQL online submissions for Department Highest Salary.
# Memory Usage: 0B, less than 100.00% of MySQL online submissions for Department Highest Salary.

SELECT
    Department.Name AS Department,
    Employee.Name AS Employee,
    Employee.Salary
FROM Employee
INNER JOIN
(
    SELECT MAX(Salary) AS Salary, DepartmentId
    FROM Employee
    GROUP BY DepartmentId
) HighestEarnerByDepartment
ON Employee.Salary = HighestEarnerByDepartment.Salary AND Employee.DepartmentId = HighestEarnerByDepartment.DepartmentId
INNER JOIN Department
ON Employee.DepartmentId = Department.Id;
