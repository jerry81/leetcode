/**
 * @param {string} word1
 * @param {string} word2
 * @return {number}
 */
 var minDistance = function(word1, word2) {
    let count = 0
    let trimmed1 = word1
    let trimmed2 = word2
    // for every substring of word1?
    for (let i = 0; i < word1.length; i++) {
        const c = word1[i]
        const idx = word2.indexOf(c)
        if (idx == -1) {
          // remove the char 
          count+=1
          trimmed1 = trimmed1.split(c).join('')
        }
    }
    for (let j = 0; j < word2.length; j++) {
        const c = word2[j]
        const idx = word1.indexOf(c)
        if (idx == -1) {
          // remove the char 
          count+=1
          trimmed2 = trimmed2.split(c).join('')
        }
    }
    console.log(`trimmed1 is ${trimmed1}, trimmed2 is ${trimmed2}`)
    return count
};

let word1 = "sea"
let word2 = "eat"
let Output = 2
console.log(`expect ${Output} ${minDistance(word1, word2)}`)
// anaylsis
/* 
sea
eat

[sea,ea], [se,eat]
1 + [se,e],   [se, ea], [s,eat]
1 + 1 + [s, []],   [s,ea], [se, e], [s,ea] [eat]


map of character positions
s: [0], []
e: [1], [0]
a: [2], [1]

word1 first char s 
find first occurence of s in word 2 
- not found
- remove s 
- ea 
- eat 
- e e first item - don't delete anything
- a a first item - don't delete anything
- cut rest of word 2 
*/


word1 = "leetcode"
word2 = "etco"
Output = 4
console.log(`expect ${Output} ${minDistance(word1, word2)}`)
/*
leetcode
etco 
l - no occurence

*/

word1 = "cyazt"
word2 = "cat"
Output = 2
/*
delete y 
delete z
*/
console.log(`expect ${Output} ${minDistance(word1, word2)}`)

word1 = "aaaabbbbbccccc"
word2 = "abcabcabcabc"
Output = 2
/*
word1 -> abc
word2 -> abc
*/
console.log(`expect ${Output} ${minDistance(word1, word2)}`)