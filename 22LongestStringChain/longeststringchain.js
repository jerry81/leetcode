/**
 * @param {string[]} words
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

var longestStrChain = function(words) {
    let sorted = words.sort((x,b) => x.length - b.length)
    console.log('sorted is ', sorted)
    return 0
};

let words = ["a","b","ba","bca","bda","bdca"]
let Output = 4

console.log(`expect ${Output}, ${longestStrChain(words)}`)

words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
Output = 5

console.log(`expect ${Output}, ${longestStrChain(words)}`)

words = ["abcd","dbqca"]
Output = 1

console.log(`expect ${Output}, ${longestStrChain(words)}`)