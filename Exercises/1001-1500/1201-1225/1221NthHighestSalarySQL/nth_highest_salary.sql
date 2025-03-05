-- 177. Nth Highest Salary
-- Medium
-- Topics
-- Companies
-- SQL Schema
-- Pandas Schema
-- Table: Employee

-- +-------------+------+
-- | Column Name | Type |
-- +-------------+------+
-- | id          | int  |
-- | salary      | int  |
-- +-------------+------+
-- id is the primary key (column with unique values) for this table.
-- Each row of this table contains information about the salary of an employee.


-- Write a solution to find the nth highest salary from the Employee table. If there is no nth highest salary, return null.

-- The result format is in the following example.



-- Example 1:

-- Input:
-- Employee table:
-- +----+--------+
-- | id | salary |
-- +----+--------+
-- | 1  | 100    |
-- | 2  | 200    |
-- | 3  | 300    |
-- +----+--------+
-- n = 2
-- Output:
-- +------------------------+
-- | getNthHighestSalary(2) |
-- +------------------------+
-- | 200                    |
-- +------------------------+
-- Example 2:

-- Input:
-- Employee table:
-- +----+--------+
-- | id | salary |
-- +----+--------+
-- | 1  | 100    |
-- +----+--------+
-- n = 2
-- Output:
-- +------------------------+
-- | getNthHighestSalary(2) |
-- +------------------------+
-- | null                   |
-- +------------------------+
-- Seen this question in a real interview before?
-- 1/5
-- Yes
-- No
-- Accepted
-- 463.6K
-- Submissions
-- 1.2M
-- Acceptance Rate
-- 37.9%

CREATE OR REPLACE FUNCTION NthHighestSalary(N INT) RETURNS TABLE (Salary INT) AS $$
BEGIN
  RETURN QUERY (
    -- Write your PostgreSQL query statement below.
    SELECT
      CASE
        WHEN COUNT(DISTINCT oe.salary) < N THEN NULL
        WHEN N < 1 THEN NULL
        ELSE
          (SELECT DISTINCT e.salary
          FROM Employee as e
          ORDER BY e.salary DESC LIMIT 1 OFFSET (N-1))
      END
    FROM Employee as oe
  );
END;
$$ LANGUAGE plpgsql;