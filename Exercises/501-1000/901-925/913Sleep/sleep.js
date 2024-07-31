/*

2621. Sleep
Easy
Companies
Hint
Given a positive integer millis, write an asynchronous function that sleeps for millis milliseconds. It can resolve any value.



Example 1:

Input: millis = 100
Output: 100
Explanation: It should return a promise that resolves after 100ms.
let t = Date.now();
sleep(100).then(() => {
  console.log(Date.now() - t); // 100
});
Example 2:

Input: millis = 200
Output: 200
Explanation: It should return a promise that resolves after 200ms.


Constraints:

1 <= millis <= 1000
Seen this question in a real interview before?
1/5
Yes
No
Accepted
136.3K
Submissions
157K
Acceptance Rate
86.8%

*/

/**
 * @param {number} millis
 * @return {Promise}
 */
async function sleep(millis) {
  return new Promise(resolve=>setTimeout(resolve, millis));
}

/**
 * let t = Date.now()
 * sleep(100).then(() => console.log(Date.now() - t)) // 100
 */