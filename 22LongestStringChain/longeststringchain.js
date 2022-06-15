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

function lsc(cur, memo = {}, lmap = {}) {
    if (memo[cur] != undefined) {
        return memo[cur]
    }
    let l = cur.length
    let children = lmap[l-1]
    let results = []
    if (!children) {
        memo[cur] = 1
        return 1
    }
    for (let c of children) {
        if (lcs(c, cur) != c.length) {
          continue
        }
        if (memo[c]) {
            results.push(memo[c])
        }
        let res = lsc(c, memo, lmap)
        results.push(res)
        memo[c] = res
    }
    if (results.length == 0) {
        let specialRes = 1
        memo[cur] = specialRes
        return specialRes 
    }
    const finalRes = 1 + Math.max(...results)
    memo[cur] = finalRes
    return finalRes
}

var longestStrChain = function(words) {
    let lMap = {}
    let minK = 10001
    let maxK = -1
    let resMap = {}
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
    for (let item of lMap[maxK]) {
        lsc(item,resMap,lMap)
    }
    return Math.max(...Object.values(resMap))
    // for every level: build the chain
    /* 1: {
        "a": ["ba"]
        "b": ["ba"]
    },
    2: {
        "ba": ["bca", "bda"]
    },
    3: {
        "bca": ["bdca"],
        "bda": ["bdca"]
    }
    
    level 1
    curchains = [["a"]], [["b"]]
    level 2 
    curchains = [["a","ba"], ["b",ba"], ["ba"]]
    level 3
    curchains = [[a,ba,bca], [b,ba,bca], [a,ba,bda], [b,ba,bca,bda] ]
    */
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

words = ["z","aa","aab","aabb","bbaac"]
/*
1: z
2: aa
3: aab
4: aabb
5: bbaac
*/
Output = 3
// must handle case where the longest string doesn't contain the last item 
// only way is to find all chains 
console.log(`expect ${Output}, ${longestStrChain(words)}`)

