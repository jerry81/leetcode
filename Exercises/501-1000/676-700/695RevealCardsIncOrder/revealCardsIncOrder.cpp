/*

950. Reveal Cards In Increasing Order
Medium
Topics
Companies
You are given an integer array deck. There is a deck of cards where every card has a unique integer. The integer on the ith card is deck[i].

You can order the deck in any order you want. Initially, all the cards start face down (unrevealed) in one deck.

You will do the following steps repeatedly until all cards are revealed:

Take the top card of the deck, reveal it, and take it out of the deck.
If there are still cards in the deck then put the next top card of the deck at the bottom of the deck.
If there are still unrevealed cards, go back to step 1. Otherwise, stop.
Return an ordering of the deck that would reveal the cards in increasing order.

Note that the first entry in the answer is considered to be the top of the deck.



Example 1:

Input: deck = [17,13,11,2,3,5,7]
Output: [2,13,3,11,5,17,7]
Explanation:
We get the deck in the order [17,13,11,2,3,5,7] (this order does not matter), and reorder it.
After reordering, the deck starts as [2,13,3,11,5,17,7], where 2 is the top of the deck.
We reveal 2, and move 13 to the bottom.  The deck is now [3,11,5,17,7,13].
We reveal 3, and move 11 to the bottom.  The deck is now [5,17,7,13,11].
We reveal 5, and move 17 to the bottom.  The deck is now [7,13,11,17].
We reveal 7, and move 13 to the bottom.  The deck is now [11,17,13].
We reveal 11, and move 17 to the bottom.  The deck is now [13,17].
We reveal 13, and move 17 to the bottom.  The deck is now [17].
We reveal 17.
Since all the cards revealed are in increasing order, the answer is correct.
Example 2:

Input: deck = [1,1000]
Output: [1,1000]


Constraints:

1 <= deck.length <= 1000
1 <= deck[i] <= 106
All the values of deck are unique.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
83.8K
Submissions
106.4K
Acceptance Rate
78.8%

*/

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
      // study example 1
      // sort first
      // then split into two subarrays
      // alternate pick from both sorted
      vector<int> sorted = deck;
      sort(sorted.begin(), sorted.end());
      int len = sorted.size();
      bool oddlen = len%2 == 1;
      int halflen = len/2;
      if (oddlen) halflen+=1;
      vector<int> half1(sorted.begin(), sorted.begin()+halflen);
      vector<int> half2(sorted.begin()+halflen, sorted.end());
      // cout << "first half " << endl;
      // for (int i: half1) {
      //   cout << i << endl;
      // }
      // cout << "second half " << endl;
      // for (int i: half2) {
      //   cout << i << endl;
      // }
      vector<int> res;
      int idx = 0;
      for (int i = 0; i < halflen; ++i) {
        res.push_back(half1[i]);
        if (half2.size() > i) res.push_back(half2[i]);
      }
      return res;
    }
};