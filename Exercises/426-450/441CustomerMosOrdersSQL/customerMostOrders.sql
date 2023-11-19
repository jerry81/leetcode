-- 586. Customer Placing the Largest Number of Orders
-- Easy
-- 916
-- 67
-- Companies
-- SQL Schema
-- Pandas Schema
-- Table: Orders

-- +-----------------+----------+
-- | Column Name     | Type     |
-- +-----------------+----------+
-- | order_number    | int      |
-- | customer_number | int      |
-- +-----------------+----------+
-- order_number is the primary key (column with unique values) for this table.
-- This table contains information about the order ID and the customer ID.


-- Write a solution to find the customer_number for the customer who has placed the largest number of orders.

-- The test cases are generated so that exactly one customer will have placed more orders than any other customer.

-- The result format is in the following example.



-- Example 1:

-- Input:
-- Orders table:
-- +--------------+-----------------+
-- | order_number | customer_number |
-- +--------------+-----------------+
-- | 1            | 1               |
-- | 2            | 2               |
-- | 3            | 3               |
-- | 4            | 3               |
-- +--------------+-----------------+
-- Output:
-- +-----------------+
-- | customer_number |
-- +-----------------+
-- | 3               |
-- +-----------------+
-- Explanation:
-- The customer with number 3 has two orders, which is greater than either customer 1 or 2 because each of them only has one order.
-- So the result is customer_number 3.


-- Follow up: What if more than one customer has the largest number of orders, can you find all the customer_number in this case?

-- Accepted
-- 218.5K
-- Submissions
-- 334.7K
-- Acceptance Rate
-- 65.3%

SELECT t1.customer_number, item_count FROM orders t1
FULL JOIN (
    SELECT customer_number, COUNT(*) AS item_count
    FROM orders
    GROUP BY customer_number
    ORDER BY item_count DESC
) t2 ON t1.customer_number = t2.customer_number
LIMIT 1;