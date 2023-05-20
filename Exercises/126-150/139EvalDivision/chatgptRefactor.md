```

Here are the changes that have been made:

The type of eqMap has been changed to unordered_map<string, unordered_map<string, double>>. Since the values in eqMap are just double and not vectors, the unnecessary vector has been removed.
In the buildMap function, instead of creating vectors with values [val, 1] and [1, val], we directly assign the values and their reciprocals to eqMap.
The solveBFS function has been updated to remove unnecessary type conversions and simplify the code.
The query parameter in solveBFS has been changed to a reference to avoid unnecessary copying.
The conditions for returning -1.0 in solveBFS have been combined into a single check for both operands not found in eqMap.
The visited map in solveBFS has been changed to unordered_map<string, bool> for simplicity.
The visited map is now updated before pushing the node into the queue to avoid unnecessary processing of duplicate nodes.
The op1 and op2 variables have been moved closer to their usage.
In the calcEquation function, the q parameter has been changed to a reference to avoid unnecessary copying.
These changes improve code readability, remove unnecessary operations, and simplify the logic of the functions.

```