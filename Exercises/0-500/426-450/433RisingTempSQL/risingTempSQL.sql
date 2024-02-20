/*
197. Rising Temperature
Easy
2.4K
554
Companies
SQL Schema
Pandas Schema
Table: Weather

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| id            | int     |
| recordDate    | date    |
| temperature   | int     |
+---------------+---------+
id is the column with unique values for this table.
This table contains information about the temperature on a certain day.


Write a solution to find all dates' Id with higher temperatures compared to its previous dates (yesterday).

Return the result table in any order.

The result format is in the following example.



Example 1:

Input:
Weather table:
+----+------------+-------------+
| id | recordDate | temperature |
+----+------------+-------------+
| 1  | 2015-01-01 | 10          |
| 2  | 2015-01-02 | 25          |
| 3  | 2015-01-03 | 20          |
| 4  | 2015-01-04 | 30          |
+----+------------+-------------+
Output:
+----+
| id |
+----+
| 2  |
| 4  |
+----+
Explanation:
In 2015-01-02, the temperature was higher than the previous day (10 -> 25).
In 2015-01-04, the temperature was higher than the previous day (20 -> 30).
Accepted
466K
Submissions
1M
Acceptance Rate
46.0%
*/
select id from (
  select id, temperature, recordDate,
  LAG(recordDate) OVER (ORDER BY recordDate) AS prev_recordDate,
  LAG(temperature) OVER (ORDER BY recordDate) AS prev_temp
  from Weather
)
where prev_temp < temperature and recordDate = prev_recordDate + INTERVAL '1 day';
/*
1.  googled "postgres get previous row"
2.  found postgresql LAG function https://www.postgresqltutorial.com/postgresql-window-function/postgresql-lag-function/

*/

/*
TIL:
INTERVAL '1 day'
LAG is per column.
*/