
# 2880. Select Data
# Easy
# Companies
# Hint
# DataFrame students
# +-------------+--------+
# | Column Name | Type   |
# +-------------+--------+
# | student_id  | int    |
# | name        | object |
# | age         | int    |
# +-------------+--------+

# Write a solution to select the name and age of the student with student_id = 101.

# The result format is in the following example.



# Example 1:
# Input:
# +------------+---------+-----+
# | student_id | name    | age |
# +------------+---------+-----+
# | 101        | Ulysses | 13  |
# | 53         | William | 10  |
# | 128        | Henry   | 6   |
# | 3          | Henry   | 11  |
# +------------+---------+-----+
# Output:
# +---------+-----+
# | name    | age |
# +---------+-----+
# | Ulysses | 13  |
# +---------+-----+
# Explanation:
# Student Ulysses has student_id = 101, we select the name and age.
# Seen this question in a real interview before?
# 1/5
# Yes
# No
# Accepted
# 77.5K
# Submissions
# 97.8K
# Acceptance Rate
# 79.3%

import pandas as pd

def selectData(students: pd.DataFrame) -> pd.DataFrame:
  return students.loc[students['student_id'] == 101, ['name', 'age']]