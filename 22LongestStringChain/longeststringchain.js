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

function lsc(words, memo = {}, lmap = {}) {
    if (words.length == 0) {
      return 0 
    }

    if (words.length == 1) {
        return 1 
    }

    if (words.length == 2) {
        return 
    }

   
}

var longestStrChain = function(words) {
    let lMap = {}
    let minK = 10001
    let maxK = -1
    for (let w of words) {
        let l = w.length
        if (l < minK) {
          minK = l
        }

        if (l > maxK) {
            maxK = l
        }

        if (!lMap[l]) {
            lMap[l] = [w]
        } else {
            lMap[l].push(w)
        }
    }
    // for every level: build the chain
    
};

let words = ["a","b","ba","bca","bda","bdca"]
let Output = 4

console.log(`expect ${Output}, ${longestStrChain(words)}`)

words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
/*
2: xb
3: xbc
4: cxbc
5: pcxbc
6: pcxbcf
*/
Output = 5

console.log(`expect ${Output}, ${longestStrChain(words)}`)

words = ["abcd","dbqca"]
Output = 1

console.log(`expect ${Output}, ${longestStrChain(words)}`)

words = ["a","aa","aab","aabb","bbaac"]
/*
1: a
2: aa
3: aab
4: aabb
5: bbaac
*/
Output = 4
// must handle case where the longest string doesn't contain the last item 
// only way is to find all chains 
console.log(`expect ${Output}, ${longestStrChain(words)}`)


 /* 
    given [z,abc,def, abcd, abce, abcdefg, abcefgh, abcdefgh, zzzzzzzzz]
    [abc,def, abcd, abce, abcdefg, abcefgh, abcdefgh, zzzzzzzzz]
    next iteration should try zzzzzzzzz with a reduced set
    should also try without zzzzzzzzz 
    abc -> [abc, abcd] [abcdefg,abcefgh,abcdefgh]
    abc -> [abc abce] [abcdefg,abcefgh,abcdefgh]
    [abc,abcd] -> [abc,abcd] [abcdefg,abcdefgh]
    [abc,abce] -> [abc,abce] [abcefgh,abcdefgh]
    [abc,abcd,abcdefg] -> [abcdefgh]
    [abc,abce,abcefgh] -> [abcdefgh]
    stringchainmap: 
    1: [z]
    3: [abc,def]
    4: [abcd, abce]
    7: [abcdefg,abcefgh]
    8: [abcdefgh]
    9: [zzzzzzzzz]

    z, abc no 
    z, def, no - done 

    abc,abcd yes
    abc abce yes

    abcd abcdefg yes 
    abcd abcefgh no 
    def,abcdefg
    

*/