/**
 * @param {string[]} words
 * @return {number}
 */


 function lcs(a,b,memo={},deductions = 0,deductions2 = 0) {
    if (deductions > 1 || deductions2 > 1){
        return 0
    }
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
        const returned = 1 + lcs(a.slice(0,la), b.slice(0,lb), memo, deductions,deductions2)
        memo[`${a},${b}`] = returned
        return returned
    } else {
        if (memo[`${a},${b}`]) {
            return memo[`${a},${b}`]
        }
        const lcsA = lcs(a.slice(0,la), b, memo, ++deductions,deductions2)
        const lcsB = lcs(a, b.slice(0,lb), memo, deductions,++deductions2)
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
    for (let i = maxK; i >= minK; i--) {
        if (!lMap[i]) continue;

        for (let item of lMap[i]) {
            lsc(item,resMap,lMap)
        }
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

words = ["biltnzk","jxwakrfxsifoj","uzdwyaxvcsr","sqqgkhwbf","tnoftkolx","ipmtvxcwe","zsucxrqkhahuo","qngglugvm","kvohqyedig","njoxacsnddwrg","vwtnxw","kjjourlrzpgeem","xcs","pfsgimurs","lsifyg","uzwyxcsr","muzdwcyanxvcstr","teqyrlhbvcv","rkga","tudezgzbnzb","uzwyaxvcsr","qvzkmgfulby","x","muzdwcyianxvcstr","koqyig","gl","aqcacmy","pmvwe","eskofqduddkhykr","pm","saxxd","ds","iemm","tudegzbz","yipsawmxbp","qyrlhbvcv","yxuhwkzvoczoz","zsucxqkahuo","kga","zwziivbijeiig","wffaheemjnjahzdd","zcxkahuo","djjjsulms","plxh","ffpasoizwhtu","zwziivijeii","fyvpzegautteiv","qszaitzfzv","uwoghcy","qqgkhwbf","eteqyrllhbvcvg","qknspkhngorof","qwvzkmgfuljbyz","grkte","grikrnwezryi","xjbpvekneaxn","cy","wnhnyqmpbsum","m","offqllgj","plxhib","omblqcoktkyf","pasw","prsngzx","offlj","rvvudgpixa","djjjjsulmmrs","gt","mpfsgimurs","cxkahuo","ipmtvxcwue","pqrbaoquxqemv","prqqv","tnoftfkolx","jfzzaw","rshquwmrboghccy","ebqhvwewzzmqif","rrd","dvjjjjqsulmmrs","pfsiurs","crnruydj","rvqgeqql","djsums","prbaquqemv","bs","dzytccvny","kce","llfv","jfzaw","qwvzkmgbfuljbyz","kgieph","hnympsum","ewv","vfgel","rklga","llzqbfv","gte","jckqurkg","qngglugm","tudgzbz","ipmvcwe","rr","kkcev","djjjjsulmrs","llqbfv","offqlgj","paswu","tlrlcnnrsrf","jcckqurkg","jjourlpgeem","nvl","shquwmrboghccy","vncfgelm","dgcdgjcksk","vvhvmibflb","juifgeqkaectlcj","scvdl","whcy","yipswmbp","wcy","hbqq","bsth","etjurltvpsuy","dzvytcccevnceyq","apqrbaoquxqemv","kvohuqyediyig","lenybbukzftz","ffpasoiuztwhtu","lzlhzqibfv","wfeemjnjahzdd","djsulms","xtudezgzbnzb","eemjhzdd","scavdil","guchrvaqbe","nvll","sxzfpzjmxvu","dytccvny","grikrnjwezryi","prng","ntvmcwwpzo","laqgcacyxmym","mglosifyg","nynvlqll","vwtn","lh","zhhxducgelhy","prg","kghierph","zsucxrqkhahuom","kvohqydig","eemjhzd","offiqcdllgji","dyc","toflx","dzvytccvney","ghvb","to","guchrvab","wyimthhfzndppwt","elbqhvwewzzmqif","hkghiyerph","hkghiyejrph","hlsioorugbsuu","c","kgierph","bstbghj","prbquqev","mpfsdgimurs","zfpjvu","zfpvu","yxuhwkzvoczfgoz","gel","ntvmcpzo","ekofqduddkhykr","ekofqdddhykr","rqeql","nhnympsum","xhoqlfolk","ipmtvxcwuje","wgmhjhdmnqot","bsh","rvncfgelm","hkahpbb","lzlzqibfv","xoqlfok","tnoftfkogwgplx","ekofqdddkhykr","zwiieii","ujfzzaw","jfzw","djsms","scavdpilj","tnoftfkoglx","ps","vwtnw","scavhdpilj","scayvhdpuilji","pdrshqngzx","crnrud","wmhjhdmnqot","wghmhjhdmnqot","vbyipsawmxbp","qknsapkhngorof","wymthhfzndppwt","wxcs","dzvytccevney","acacmy","dycy","teqyrllhbvcv","uzwyxcs","wmhjhdmnqt","qvzkmgfulbyz","qngglum","zhhxgdyukcgelhy","oj","iljes","bstbh","laqcacxmy","tofx","ke","yivkqoek","djjjsulmrs","lbirdzvttzze","l","zhhxgdukcgelhy","grikvrnjwezryi","bltz","npynvlqll","gvb","okzrs","urbarfkmnlxxn","qsyzaixtzfazv","dytcy","h","kohqyig","hgri","ojdxm","ujfdfzzaw","qyrhbvcv","ebqhvwewzmqif","uzwxcs","lebzf","ysijvkwqmoekromh","wffaeemjnjahzdd","crnrduyndj","ujfdmfzzaw","laqgcacyxmzgym","jjourlrpgeem","kvohqyediyig","lebukzf","zwiijeii","guchrvb","omoktkyf","hpgt","yikoek","ysijvkwqoekromh","tvpo","ysijvkqoekromh","xbgq","d","abmtk","ors","rnrd","xzrugvlzduaxhzc","njoxacjsnddwrg","yipswmxbp","xqsyzaixtzfazv","urbrfknlxxn","sxzfpjxvu","prbaquxqemv","dvjjjjsulmmrs","kviahvqu","urbfknx","qvmgfulby","yikqoek","zsucxrqkhfahuomm","koqyg","djss","moxpfsdgimlurs","qeql","urbrfknlxn","kgieh","qnspkhngorof","plxyhib","scyayvhdpuiljki","vvhvmbflb","lpzluhzqxibfv","kkcbev","hpzgty","nyvlqll","kvahvu","rklgja","ipmtavxcwuje","lbirdzvvttzze","psw","fpasoiwhtu","dgcdgjckk","qknhsapkhngorof","qszaixtzfazv","tvp","abmtvk","uwrboghcy","hbq","crnruyd","etjurltvsuy","etjurltyvpsuy","lenbukzf","teqyrllhbvcvg","ipmvwe","o","crnryduyndj","lbirdzvvqfttzze","tnoftfkowglx","ipmtavxcwujre","omlcoktkyf","rnperyemtmqh","bltnzk","sxzfpzjxvu","uzdwyaxvcstr","bq","rvvugpixa","laqcacxmym","wffeemjnjahzdd","fpvu","xjbpvekngeyaxbn","dzvytccevncey","qgly","scavdl","fw","tox","toftklx","prbaoquxqemv","ztrobzqiukdkcbv","yivkqoekr","feemjnjhzdd","plxhi","cp","fyvpzgauttei","prshqngzx","kplxyrhib","suwrboghcy","kviahvu","mvwe","dzvytccvny","hbqwq","prbquqemv","lzlhzqxibfv","ll","omblcoktkyf","toftlx","lpzlhzqxibfv","tudegzbnz","ddgcdgjcgkspk","kgih","xjbpvekneaxbn","suwrboghccy","zwiiijeii","dytccy","ympsum","jxwakfxsifoj","uwhcy","yxuhwkzvoczfoz","xzfpjvu","lenybbukzft","b","llqfv","laqgcacyxmgym","xq","scavdilj","zwziivbijaeiig","scyayvhdpuilji","amvevfulhsd","dss","tlrlcnnrs","uzwyaxcsr","qspkhngorof","etjurtvsuy","wgqhmhjhhdmnqot","tvmpo","tnoftklx","qgflby","mlosifyg","oqyg","gchvb","t","offqcdllgj","ziieii","zwziivbijeii","vp","lpb","fyvprzegauttejiv","vtn","amefulhsd","llf","muzdwyaxvcstr","zucxqkahuo","pfsgiurs","obstbghj","ipmqtavxcwuzjrbe","djjsulms","qvmgflby","ljpzluhzqxibfv","jjourlrzpgeem","zrugvlduaxhzc","xbpvkneaxn","ljpzluhzgqyxibfv","yivkqoekrh","laqcacyxmym","nyvll","muzdwcyaxvcstr","fyvpzegauttejiv","offlgj","vnfgelm","eteiqyrllhbvcvg","zsucxrqkhahuomm","ibiltnzk","rklgjae","fpasoizwhtu","t","zhhxdukcgelhy","fpasoiwu","xzfpjxvu","tlrlcnnrysrf","ojx","mpum","lxh","eturtvsuy","rklgbjaae","kahpbb","qngglugmfvmp","fielbqtcri","xzruogvlzduaxhzc","rshquwmrbtoghccy","nyvlll","lbirdzvvqttzze","dgcdgjckspk","vvhvmibfilb","dzvytcccevncey","g","vwe","zwxcs","k","jourlpgeem","cpk","cds","tlrlcnnrsr","ivemm","fgel","grktse","urbfknlxn","qwvzkmgfulbyz","xjbpvekngeaxbn","wphuutlgczfspyga","xbq","offqcdllgji","vbyipsakwmxbp","qyrhbvc","ygzpztbno","xhogqlfolk","ujffzzaw","xbnmgq","uwohcy","rnperyemqh","prbqqev","lenybukzf","mxpfsdgimurs","ga","hpt","moxpfsdgimurs","vb","offqcllgj","rklgbjae","lifg","ztrobzzqiukdkcbv","xoqok","cs","snaxxd","cdds","qknhsapkhngorohf","rvqgeql","rnperyemmqh","scavhdpuilji","urbfknlx","rvvugixa","ygzpztbndon","zrugvlzduaxhzc","shuwmrboghccy","mlsifyg","xhoqlfok","wfeemjnjhzdd","lbzf","wythhfzndppwt","mglqosifyg","ojxm","kvohuqyevdiyig","grte","prsngz","eteeiqyrllhbvcvg","dytccny","qngglugfvmp","kohqydig","fu","qgfly","tvmcpzo","tnoftfkowgplx","zruglduaxzc","yijvkqoekrh","xqsyzaixtzfdazv","ipmqtavxcwuzjre","omloktkyf","ympum","lzlzqbfv","pasowu","rvqeql","qngglugvmp","hkghierph","eemjhz","feemnjhzdd","c","yxpuhwkzvoczfgoz","dgcgjckk","lbz","yxuwkzvoczoz","zrugvlduaxzc","ntvmcwpzo","fzw","ygzpmztbndon","rvncfgxelm","mpm","tudezgzbnz","bltzk","ffpasoiuzwhtu","cd","r","okrs","byipsawmxbp","prsqngzx","wnhnyqmpsum","ipmqtavxcwujre","w","fpasoiwtu","plxyrhib","bstbhj","xbnmrgq","ipmtvcwe","urbfkn","nympsum","qtngglugmfvmpt","jckqurg","hgr","hpzgt","rvvxudgpixa","ysijvkqoekrh","lebkzf","guchvb","kvohqyediyg","amvefulhsd","suwmrboghccy","fvu","ibdiltnzk","rnrud","iem","urbarfknlxxn","ygzpztbnon","prsng","zcxqkahuo","ffpeasoiuztwhtu","laqcacmy","qszaitzfazv","xbngq","qvkmgfulby","scavhdpuilj","zsucxrqkahuo","v","qtngglugmfvmp","ysijvkqoekrmh","lfg","prqqev","pasoiwu","p","tvmcpo","kcev","im","crnrduydj","vfgelm","ddgcdgjckspk","ivqemm","ljpzluhzgqxibfv","lenybukzft","nhnyqmpsum","iljesr","hp","tqyrlhbvcv","eemnjhzdd","xbpvekneaxn","wghmhjhhdmnqot","uwboghcy","guchrvabe","xoqfok","fyvpzgautteiv","pg","zwiivijeii","qvgflby","lsifg"]
console.log(`expect perf, ${longestStrChain(words)}`)