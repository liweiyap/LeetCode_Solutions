# Runtime: 755 ms, faster than 65.66% of MySQL online submissions for Department Top Three Salaries.
# Memory Usage: 0B, less than 100.00% of MySQL online submissions for Department Top Three Salaries.

SELECT
    Department.Name AS Department,
    EmployeesRankedBySalary.Name AS Employee,
    Salary
FROM
(
    SELECT
        Name,
        Salary,
        DepartmentId,
        @rank := CONVERT(CASE WHEN @curDepartmentId = DepartmentId AND @prevSalary <> Salary THEN @rank + 1
                              WHEN @curDepartmentId = DepartmentId THEN @rank
                              WHEN @curDepartmentId <> DepartmentId THEN 1 END, SIGNED) AS Rank,
        @curDepartmentId := CONVERT(IF(@curDepartmentId = DepartmentId, @curDepartmentId, DepartmentId), SIGNED) AS CurDepartmentId,
        @prevSalary := Salary AS PrevSalary
    FROM Employee, (SELECT @rank := 0, @curDepartmentId := 0, @prevSalary := NULL) tmp
    ORDER BY DepartmentId, Salary DESC
) EmployeesRankedBySalary
INNER JOIN Department ON DepartmentId = Department.Id
WHERE Rank <= 3;
