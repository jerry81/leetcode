/*

2491. Divide Players Into Teams of Equal Skill
Medium
Topics
Companies
Hint
You are given a positive integer array skill of even length n where skill[i] denotes the skill of the ith player. Divide the players into n / 2 teams of size 2 such that the total skill of each team is equal.

The chemistry of a team is equal to the product of the skills of the players on that team.

Return the sum of the chemistry of all the teams, or return -1 if there is no way to divide the players into teams such that the total skill of each team is equal.



Example 1:

Input: skill = [3,2,5,1,3,4]
Output: 22
Explanation:
Divide the players into the following teams: (1, 5), (2, 4), (3, 3), where each team has a total skill of 6.
The sum of the chemistry of all the teams is: 1 * 5 + 2 * 4 + 3 * 3 = 5 + 8 + 9 = 22.
Example 2:

Input: skill = [3,4]
Output: 12
Explanation:
The two players form a team with a total skill of 7.
The chemistry of the team is 3 * 4 = 12.
Example 3:

Input: skill = [1,1,2,3]
Output: -1
Explanation:
There is no way to divide the players into teams such that the total skill of each team is equal.


Constraints:

2 <= skill.length <= 105
skill.length is even.
1 <= skill[i] <= 1000
Seen this question in a real interview before?
1/5
Yes
No
Accepted
119.1K
Submissions
176.2K
Acceptance Rate
67.6%

*/

#include <vector>

using namespace std;
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end()); // Sort the skill array
        long long totalSkill = 0; // Variable to hold total skill
        long long chemistrySum = 0; // Variable to hold total chemistry

        // Calculate total skill
        for (int s : skill) {
            totalSkill += s;
        }

        // Check if total skill can be evenly divided into pairs
        if (totalSkill % (skill.size() / 2) != 0) return -1; // Check if total skill can be evenly divided

        long long targetSkill = totalSkill / (skill.size() / 2); // Target skill for each team

        // Form teams and calculate chemistry
        for (int i = 0; i < skill.size() / 2; ++i) {
            if (skill[i] + skill[skill.size() - 1 - i] != targetSkill) return -1; // Check if pairs meet target skill
            chemistrySum += skill[i] * skill[skill.size() - 1 - i]; // Calculate chemistry
        }

        return chemistrySum; // Return the total chemistry
    }
};