
-- 1667. Fix Names in a Table
-- Easy
-- Topics
-- Companies
-- SQL Schema
-- Pandas Schema
-- Table: Users

-- +----------------+---------+
-- | Column Name    | Type    |
-- +----------------+---------+
-- | user_id        | int     |
-- | name           | varchar |
-- +----------------+---------+
-- user_id is the primary key (column with unique values) for this table.
-- This table contains the ID and the name of the user. The name consists of only lowercase and uppercase characters.


-- Write a solution to fix the names so that only the first character is uppercase and the rest are lowercase.

-- Return the result table ordered by user_id.

-- The result format is in the following example.



-- Example 1:

-- Input:
-- Users table:
-- +---------+-------+
-- | user_id | name  |
-- +---------+-------+
-- | 1       | aLice |
-- | 2       | bOB   |
-- +---------+-------+
-- Output:
-- +---------+-------+
-- | user_id | name  |
-- +---------+-------+
-- | 1       | Alice |
-- | 2       | Bob   |
-- +---------+-------+
-- Seen this question in a real interview before?
-- 1/4
-- Yes
-- No
-- Accepted
-- 189K
-- Submissions
-- 304.7K
-- Acceptance Rate
-- 62.0%

-- SELECT user_id, INITCAP(name) AS name
-- FROM Users;

-- unfortunately output Mary Ann, expected Mary ann

SELECT user_id, UPPER(SUBSTRING(name FROM 1 FOR 1)) || LOWER(SUBSTRING(name FROM 2)) as name
FROM Users
ORDER BY user_id;