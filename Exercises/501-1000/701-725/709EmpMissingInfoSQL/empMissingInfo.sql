-- 1965. Employees With Missing Information
-- Easy
-- Topics
-- Companies
-- SQL Schema
-- Pandas Schema
-- Table: Employees

-- +-------------+---------+
-- | Column Name | Type    |
-- +-------------+---------+
-- | employee_id | int     |
-- | name        | varchar |
-- +-------------+---------+
-- employee_id is the column with unique values for this table.
-- Each row of this table indicates the name of the employee whose ID is employee_id.


-- Table: Salaries

-- +-------------+---------+
-- | Column Name | Type    |
-- +-------------+---------+
-- | employee_id | int     |
-- | salary      | int     |
-- +-------------+---------+
-- employee_id is the column with unique values for this table.
-- Each row of this table indicates the salary of the employee whose ID is employee_id.


-- Write a solution to report the IDs of all the employees with missing information. The information of an employee is missing if:

-- The employee's name is missing, or
-- The employee's salary is missing.
-- Return the result table ordered by employee_id in ascending order.

-- The result format is in the following example.



-- Example 1:

-- Input:
-- Employees table:
-- +-------------+----------+
-- | employee_id | name     |
-- +-------------+----------+
-- | 2           | Crew     |
-- | 4           | Haven    |
-- | 5           | Kristian |
-- +-------------+----------+
-- Salaries table:
-- +-------------+--------+
-- | employee_id | salary |
-- +-------------+--------+
-- | 5           | 76071  |
-- | 1           | 22517  |
-- | 4           | 63539  |
-- +-------------+--------+
-- Output:
-- +-------------+
-- | employee_id |
-- +-------------+
-- | 1           |
-- | 2           |
-- +-------------+
-- Explanation:
-- Employees 1, 2, 4, and 5 are working at this company.
-- The name of employee 1 is missing.
-- The salary of employee 2 is missing.
-- Seen this question in a real interview before?
-- 1/5
-- Yes
-- No
-- Accepted
-- 117.5K
-- Submissions
-- 162.9K
-- Acceptance Rate
-- 72.1%

select coalesce(e.employee_id, s.employee_id) as employee_id
from Employees e
full join Salaries s
on e.employee_id = s.employee_id
where e.employee_id is null or s.employee_id is null;