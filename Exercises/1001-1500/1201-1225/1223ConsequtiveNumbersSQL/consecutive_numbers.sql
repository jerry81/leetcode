-- 180. Consecutive Numbers
-- Medium
-- Topics
-- Companies
-- SQL Schema
-- Pandas Schema
-- Table: Logs

-- +-------------+---------+
-- | Column Name | Type    |
-- +-------------+---------+
-- | id          | int     |
-- | num         | varchar |
-- +-------------+---------+
-- In SQL, id is the primary key for this table.
-- id is an autoincrement column starting from 1.


-- Find all numbers that appear at least three times consecutively.

-- Return the result table in any order.

-- The result format is in the following example.



-- Example 1:

-- Input:
-- Logs table:
-- +----+-----+
-- | id | num |
-- +----+-----+
-- | 1  | 1   |
-- | 2  | 1   |
-- | 3  | 1   |
-- | 4  | 2   |
-- | 5  | 1   |
-- | 6  | 2   |
-- | 7  | 2   |
-- +----+-----+
-- Output:
-- +-----------------+
-- | ConsecutiveNums |
-- +-----------------+
-- | 1               |
-- +-----------------+
-- Explanation: 1 is the only number that appears consecutively for at least three times.
-- Seen this question in a real interview before?
-- 1/5
-- Yes
-- No
-- Accepted
-- 509.3K
-- Submissions
-- 1.1M
-- Acceptance Rate
-- 45.4%
SELECT
       num as ConsecutiveNums
   FROM
       Logs
   GROUP BY
       num
   HAVING
       COUNT(*) >= 3
   AND
       (MAX(id) - MIN(id) = COUNT(*) - 1); -- too clever