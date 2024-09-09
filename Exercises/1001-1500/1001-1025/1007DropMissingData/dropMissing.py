# 2883. Drop Missing Data
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
# There are some rows having missing values in the name column.

# Write a solution to remove the rows with missing values.

# The result format is in the following example.



# Example 1:

# Input:
# +------------+---------+-----+
# | student_id | name    | age |
# +------------+---------+-----+
# | 32         | Piper   | 5   |
# | 217        | None    | 19  |
# | 779        | Georgia | 20  |
# | 849        | Willow  | 14  |
# +------------+---------+-----+
# Output:
# +------------+---------+-----+
# | student_id | name    | age |
# +------------+---------+-----+
# | 32         | Piper   | 5   |
# | 779        | Georgia | 20  |
# | 849        | Willow  | 14  |
# +------------+---------+-----+
# Explanation:
# Student with id 217 havs empty value in the name column, so it will be removed.
# Seen this question in a real interview before?
# 1/5
# Yes
# No
# Accepted
# 61.4K
# Submissions
# 95.9K
# Acceptance Rate
# 64.0%

import pandas as pd

def dropMissingData(students: pd.DataFrame) -> pd.DataFrame:
    students = students.dropna(subset=['name']) # TIL dropna removes rows with missing values in the specified column(s).
    return students