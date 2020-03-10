# Runtime: 345 ms, faster than 84.44% of MySQL online submissions for Employees Earning More Than Their Managers.
# Memory Usage: 0B, less than 100.00% of MySQL online submissions for Employees Earning More Than Their Managers.

SELECT Managed.Name AS Employee
FROM
(
    SELECT *
    FROM Employee
    WHERE ManagerId IS NOT NULL
) AS Managed, Employee
WHERE Managed.ManagerId = Employee.Id AND Managed.Salary > Employee.Salary;
