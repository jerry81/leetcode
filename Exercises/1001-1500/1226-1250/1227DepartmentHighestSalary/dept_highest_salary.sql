--

-- Write your PostgreSQL query statement below

SELECT d.name as Department, e.name as Employee, salary as Salary
FROM Employee as e
JOIN Department as d
ON e.departmentId=d.id;