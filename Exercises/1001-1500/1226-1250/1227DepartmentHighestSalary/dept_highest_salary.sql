--

-- Write your PostgreSQL query statement below

SELECT d.name as "Department", e.name as "Employee", salary as "Salary"
FROM Employee as e
JOIN Department as d
ON e.departmentId=d.id
WHERE (e.departmentId, salary) IN ( -- where with IN
  SELECT departmentId, MAX(salary)
  FROM Employee
  GROUP BY departmentId
)
ORDER BY salary DESC;