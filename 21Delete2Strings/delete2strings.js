/**
 * @param {string} word1
 * @param {string} word2
 * @return {number}
 */
function lcs(a,b,memo={}) {
    if (a.length == 0) {
        memo[`${a},${b}`] = 0
        return 0
    }
    if (b.length == 0) {
        memo[`${a},${b}`] = 0
        return 0 
    }
    const la = a.length-1
    const lb = b.length-1
    if (a[la] == b[lb]) {
        const returned = 1 + lcs(a.slice(0,la), b.slice(0,lb), memo)
        memo[`${a},${b}`] = returned 
        return returned
    } else {
        if (memo[`${a},${b}`]) {
            return memo[`${a},${b}`]
        }
        
        const lcsA = lcs(a.slice(0,la), b, memo)
        const lcsB = lcs(a, b.slice(0,lb), memo)
        const returned = Math.max(lcsA, lcsB)
        memo[`${a},${b}`] = returned 
        return returned
    }
}

var minDistance = function(word1, word2) {
    const longest = lcs(word1,word2)
    console.log('longest is ', longest)
    return (word1.length - longest) + (word2.length - longest)
}

 var minDistanceNaive = function(word1, word2) {
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
console.log(`expect 2 (lcs) ${lcs(word1,word2)}`)
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
// console.log(`expect 4 ${lcs(word1,word2)}`)
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

word1 = "aaaabbbbbccccc" // aabbbccc 8
word2 = "abcabcabcabc" // bccaab 6 = 14 aabbcc
Output = 'unknown'
/*
word1 -> aabbcc
word2 -> aabbcc
*/
console.log(`expect ${Output} ${minDistance(word1, word2)}`)

console.log('hello'.slice(0,4))

word1 = "dinitrophenylhydrazine"
word2 = "benzalphenylhydrazone"
console.log(lcs(word1,word2, {}))