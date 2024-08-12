/*

2667. Create Hello World Function
Easy
Companies
Write a function createHelloWorld. It should return a new function that always returns "Hello World".


Example 1:

Input: args = []
Output: "Hello World"
Explanation:
const f = createHelloWorld();
f(); // "Hello World"

The function returned by createHelloWorld should always return "Hello World".
Example 2:

Input: args = [{},null,42]
Output: "Hello World"
Explanation:
const f = createHelloWorld();
f({}, null, 42); // "Hello World"

Any arguments could be passed to the function but it should still always return "Hello World".


Constraints:

0 <= args.length <= 10
Seen this question in a real interview before?
1/5
Yes
No
Accepted
448.3K
Submissions
551.4K
Acceptance Rate
81.3%

*/

/**
 * @return {Function}
 */
var createHelloWorld = function() {

  return function(...args) {

  }
};

/**
* const f = createHelloWorld();
* f(); // "Hello World"
*/