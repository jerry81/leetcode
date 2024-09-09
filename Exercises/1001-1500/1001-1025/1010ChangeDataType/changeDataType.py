# 2886. Change Data Type
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
# | grade       | float  |
# +-------------+--------+
# Write a solution to correct the errors:

# The grade column is stored as floats, convert it to integers.

# The result format is in the following example.



# Example 1:
# Input:
# DataFrame students:
# +------------+------+-----+-------+
# | student_id | name | age | grade |
# +------------+------+-----+-------+
# | 1          | Ava  | 6   | 73.0  |
# | 2          | Kate | 15  | 87.0  |
# +------------+------+-----+-------+
# Output:
# +------------+------+-----+-------+
# | student_id | name | age | grade |
# +------------+------+-----+-------+
# | 1          | Ava  | 6   | 73    |
# | 2          | Kate | 15  | 87    |
# +------------+------+-----+-------+
# Explanation:
# The data types of the column grade is converted to int.
# Seen this question in a real interview before?
# 1/5
# Yes
# No
# Accepted
# 56.7K
# Submissions
# 65K
# Acceptance Rate
# 87.2%

import pandas as pd

def changeDatatype(students: pd.DataFrame) -> pd.DataFrame:
    students['grade'] = students['grade'].astype(int) # TIL astype is used to change the data type of a column.
    return students
