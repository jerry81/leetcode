# 195. Tenth Line
# Easy
# 365
# 457
# Companies
# Given a text file file.txt, print just the 10th line of the file.

# Example:

# Assume that file.txt has the following content:

# Line 1
# Line 2
# Line 3
# Line 4
# Line 5
# Line 6
# Line 7
# Line 8
# Line 9
# Line 10
# Your script should output the tenth line, which is:

# Line 10
# Note:
# 1. If the file contains less than 10 lines, what should you output?
# 2. There's at least three different solutions. Try to explore all possibilities.
# Accepted
# 96.5K
# Submissions
# 293.2K
# Acceptance Rate
# 32.9%

# Read from the file file.txt and output the tenth line to stdout.

# head -10 file.txt | tail -1

cat file.txt | sed -n '10p'
