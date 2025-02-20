
-- 176. Second Highest Salary
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


-- Write a solution to find the second highest distinct salary from the Employee table. If there is no second highest salary, return null (return None in Pandas).

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
-- Output:
-- +---------------------+
-- | SecondHighestSalary |
-- +---------------------+
-- | 200                 |
-- +---------------------+
-- Example 2:

-- Input:
-- Employee table:
-- +----+--------+
-- | id | salary |
-- +----+--------+
-- | 1  | 100    |
-- +----+--------+
-- Output:
-- +---------------------+
-- | SecondHighestSalary |
-- +---------------------+
-- | null                |
-- +---------------------+
-- Seen this question in a real interview before?
-- 1/5
-- Yes
-- No
-- Accepted
-- 1.1M
-- Submissions
-- 2.5M
-- Acceptance Rate
-- 42.9%

-- Write your PostgreSQL query statement below

SELECT
  CASE
    WHEN COUNT(*) < 2 THEN NULL
    ELSE (SELECT DISTINCT salary FROM Employee ORDER BY salary DESC LIMIT 1 OFFSET 1)
  END AS SecondHighestSalary
FROM Employee;

-- order by plus OFFSET (TIL)