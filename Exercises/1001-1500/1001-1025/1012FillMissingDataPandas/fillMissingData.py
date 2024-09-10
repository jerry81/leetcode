
# 2887. Fill Missing Data
# Easy
# Companies
# Hint
# DataFrame products
# +-------------+--------+
# | Column Name | Type   |
# +-------------+--------+
# | name        | object |
# | quantity    | int    |
# | price       | int    |
# +-------------+--------+
# Write a solution to fill in the missing value as 0 in the quantity column.

# The result format is in the following example.



# Example 1:
# Input:+-----------------+----------+-------+
# | name            | quantity | price |
# +-----------------+----------+-------+
# | Wristwatch      | None     | 135   |
# | WirelessEarbuds | None     | 821   |
# | GolfClubs       | 779      | 9319  |
# | Printer         | 849      | 3051  |
# +-----------------+----------+-------+
# Output:
# +-----------------+----------+-------+
# | name            | quantity | price |
# +-----------------+----------+-------+
# | Wristwatch      | 0        | 135   |
# | WirelessEarbuds | 0        | 821   |
# | GolfClubs       | 779      | 9319  |
# | Printer         | 849      | 3051  |
# +-----------------+----------+-------+
# Explanation:
# The quantity for Wristwatch and WirelessEarbuds are filled by 0.
# Seen this question in a real interview before?
# 1/5
# Yes
# No
# Accepted
# 54.5K
# Submissions
# 75.9K
# Acceptance Rate
# 71.9%

import pandas as pd

def fillMissingValues(products: pd.DataFrame) -> pd.DataFrame:
    products['quantity'] = products['quantity'].fillna(0) # TIL fillna is used to fill missing values in a column with a specified value.
    return products