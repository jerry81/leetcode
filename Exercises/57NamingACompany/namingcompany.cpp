/*

2306. Naming a Company
Hard
450
27
Companies
You are given an array of strings ideas that represents a list of names to be used in the process of naming a company. The process of naming a company is as follows:

Choose 2 distinct names from ideas, call them ideaA and ideaB.
Swap the first letters of ideaA and ideaB with each other.
If both of the new names are not found in the original ideas, then the name ideaA ideaB (the concatenation of ideaA and ideaB, separated by a space) is a valid company name.
Otherwise, it is not a valid name.
Return the number of distinct valid names for the company.



Example 1:

Input: ideas = ["coffee","donuts","time","toffee"]
Output: 6
Explanation: The following selections are valid:
- ("coffee", "donuts"): The company name created is "doffee conuts".
- ("donuts", "coffee"): The company name created is "conuts doffee".
- ("donuts", "time"): The company name created is "tonuts dime".
- ("donuts", "toffee"): The company name created is "tonuts doffee".
- ("time", "donuts"): The company name created is "dime tonuts".
- ("toffee", "donuts"): The company name created is "doffee tonuts".
Therefore, there are a total of 6 distinct company names.

The following are some examples of invalid selections:
- ("coffee", "time"): The name "toffee" formed after swapping already exists in the original array.
- ("time", "toffee"): Both names are still the same after swapping and exist in the original array.
- ("coffee", "toffee"): Both names formed after swapping already exist in the original array.
Example 2:

Input: ideas = ["lack","back"]
Output: 0
Explanation: There are no valid selections. Therefore, 0 is returned.


Constraints:

2 <= ideas.length <= 5 * 104
1 <= ideas[i].length <= 10
ideas[i] consists of lowercase English letters.
All the strings in ideas are unique.
Accepted
10.8K
Submissions
29.1K
Acceptance Rate
37.1%

*/

#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

struct Swapped {
  string word1 = "";
  string word2 = "";
};


class Solution {
unordered_map<string, unordered_map<string, bool>> lookup;
unordered_map<string, unordered_map<string, bool>> suffixes;
bool lc(string key) { //lookup contains helper
  return (lookup.find(key) != lookup.end());
}

Swapped swapFirst(string s1, string s2) {
  string temp = s1;
  s1[0] = s2[0];
  s2[0] = temp[0];
  Swapped sw;
  sw.word1 = s1;
  sw.word2 = s2;
  return sw;
}

bool sameFirstOrLast(string s1, string s2) {
   if (s1[0] == s2[0]) return true;

   if (s1.substr(1) == s2.substr(1)) return true;

   return false;
}


bool canAdd(Swapped inp) {
  return (!lc(inp.word1) && !lc(inp.word2));
}

public:
    // long long distinctNames(vector<string>& ideas) {
    //   long long count = 0;
    //   for (string s: ideas) {
    //     lookup[s] = true;
    //   }
    //   for (int i = 0; i < (ideas.size()-1); ++i) {
    //     string item1 = ideas[i];
    //     for (int j = i+1; j < ideas.size(); ++j) {
    //       string item2 = ideas[j];
    //       if (sameFirst(item1, item2)) continue;

    //       Swapped res = swapFirst(item1, item2);
    //       if (canAdd(res)) count+=2;
    //     }
    //   }
    //   return count;
    // }

     long long distinctNames(vector<string>& ideas) {
       lookup.clear();
       suffixes.clear();
       for (string s:ideas) {
         cerr << "word is " << s << endl;
         string pre = s.substr(0,1);
         string post = s.substr(1);
         cerr << "pre is " << pre << endl;
         cerr << "post is " << post << endl;
         if (post.empty()) {
           post = "BLANK";
           cerr << "BRANK" << endl;
         }
         if (lookup.find(pre) == lookup.end()) {
           unordered_map<string, bool> um;
           um[post] = true;
           lookup[pre] = um;

         } else {
           lookup[pre][post] = true;
         }

         if (suffixes.find(post) == suffixes.end()) {
           unordered_map<string, bool> um;
           um[pre] = true;
           suffixes[post] = um;
         } else {
           suffixes[post][pre] = true;
         }
       }
       long long count = 0;
       int numkeys = lookup.size();
       for (auto a: lookup) {
        // cout << "examining lookup key " << a.first << endl;

          unordered_map<string, bool> prohibited;

           for (auto suff: a.second) {
             for (auto prohibit: suffixes[suff.first]) {
                prohibited[prohibit.first] = true;
             }

            for (auto c: lookup) {
             if (prohibited.find(c.first) != prohibited.end()) continue;


             for (auto suffix: c.second) {
               if (a.second.find(suffix.first) == a.second.end()) {
                 // cout << "counting " << a.first<<suffix.first<< " " << c.first << suff.first   << endl;
                 count++;
               }

             }
           }

           }


         }

      //  for (int i = 0; i < (ideas.size()-1); ++i) {
      //    string item1 = ideas[i];
      //    for (int j = i+1; j < ideas.size(); ++j) {
      //      string item2 = ideas[j];
      //      if (sameFirstOrLast(item1, item2)) continue;

      //      count+=2;
      //    }
      //  }
       return count;
     }
};



int main() {
vector<string> test1 = {
"ufrd","evjfco","ojdyeze","pildaslfj","bhush","q","fvbvd","gmyfxe","gsnzuzxd","acaw","kv","ak","itktagmfvc","xafbvv","iucpfg","lhgxuanmk","efljasin","raldgyqnl","pxcuapwd","ymfiudiy","qubqhventm","htcpug","bliwkz","ibd","wmackcg","hjy","frvviojvjl","ialerc","xyeppctwam","fonjranlmq","pdnwak","gzjkoyxn","imyvh","wxpnt","kzrdvqrcz","qvwwvumv","hvd","heaqhxvn","fpqb","qmwebgbq","x","zm","ad","jmfqqphb","fqdsfskyxa","sxtzh","s","bosjkmv","dxazbbk","eguj","cvu","kr","uvm","godsfrbd","sgj","cvxrzer","xbb","hhcjyc","p","sg","gppoq","pzenuvvi","rjhhk","rdtci","rp","ttqacsxhd","u","braflwzfvn","sabfkglhpp","c","tamy","tchuflso","w","fgkwtwgkje","reuvvjnga","msrfj","wgwfflbia","eizpigf","ezpkwrkfye","jsd","bvgvrzvb","xeb","jo","hcsnhodewy","t","mebfwel","grzcebhdm","mhoyzwc","zhfnbiodb","dtwinj","xph","oagejrbw","otlvqywmbj","nloryp","bwmwvyhdpk","tn","bzpu","iicrfdnxzg","zexi","fcdt","pwdq","shthfmmz","ytupezhd","li","ktqyl","bpaqphrymg","wq","iwhagzdr","dhykysqamu","euniekj","sm","zf","fnige","xvnifcpnbm","lwxm","qcnbmwavsl","gmkmlolfp","merpmw","ujsito","vfmqygu","weemh","cmqfjc","bsi","baycguvsk","beemh","xsj","kpm","m","wgvh","qjpn","ez","pabfkglhpp","jkwaleku","gujo","tgpc","szkgafvpu","bibwzumdzk","ucloyz","dkxazydf","pjfwbx","g","lwwkaypq","sbx","sxr","pwxco","qmmlqtr","qjwgtc","abcunxeuz","ehqolylwy","hcjpmhew","mqjervmdn","vjnti","mapr","hkxru","idfrdpkdzy","klxpubomc","bwwepvrbs","wsmjuzvyrj","oz","ujmxsgkbqw","bzamyz","mpuo","dpbzutc","ye","oswzwnqmxt","ftvdj","qa","k","pewwqberzj","lkxngnzyhd","twfbg","krxqbcw","rza","uhnpmcp","rdnmekawa","bdtci","hoccmond","zovrgabd","bfptusy","lcguji","jrznpo","h","jegid","ccnbmwavsl","xdxjiu","czg","pnksktifrw","vszouj","ec","unoulota","qbksmdhrfl","nuemd","skk","pyjlymwj","vetlrnzyp","lxoj","yeqgz","j","kwswyofcd","fnadu","spqq","tlqgtdbz","jgtpg","d","xjqrbsv","lu","qlz","sguzxjg","zknw","kbvt","iaju","bm","om","hwniqofxmk","msrqlfqbmz","zlkljalfuk","gyqiecft","kgieoqqged","uncajn","zxdttqrcq","cgien","tlqjhd","qh","kvx","tnfcip","uiyaixpzoa","hlms","cys","iez","fuzrxfx","tus","uxhsl","dyttyyur","pb","zwvfbibbzk","jcv","geeskwdv","etrrctme","cn","sbkou","qehxc","kjmwyep","nsewcy","rjnye","kvus","joemuly","vcgkqyacc","aivr","uzmvau","orabkt","lvmxwdjy","hugw","wutq","imhvii","ev","yoda","cqyligiq","jhyl","piqjyenws","gbjnb","int","krouwpcvf","uaygpmgrxm","nqakxp","zsy","a","qkobvf","mld","gj","yfrxzp","qetwhnkav","junficb","wpzolbyomp","ndvafzxgw","kfetkof","zeam","dqyelgc","hlqizp","zztfegg","dkf","qjmbmwm","mo","necijfqgl","ksus","gfaqtwokn","iefzg","sier","xbsxppxnof","ervviojvjl","uhsmgsfpc","gyoriyhjv","apsvhqfku","zedpul","dfijydxnbk","vajpmtv","xqwfjgkove","iwxolneugu","l","kqixmaljie","nceqhmky","umjkdbp","fauizhiz","ilovtl","ntmymf","b","blqyeozud","luubvtaza","kkqutkavb","adu","qlncjz","nzg","jypszs","msevbx","qifrc","mbd","khzmrppp","phxtvpibnh","hi","wegtljkhz","vygksg","znnxas","fxqqastbi","upviltbs","mrvtkfxqz","hbyhawmdf","sker","diu","sqckv","wrdsfkz","bhxv","uqbqs","riqz","hw","iyxjdoyjs","sksgltkdgh","pub","sowbbdpm","cpidjcktia","fie","kyytk","njq","ip","kcwj","uo","rgniqun","timrmt","gdtgok","vu","iyuqgipd","gczqfwpea","lixkgpjyt","weed","rchhnojpyt","ipqkvz","rrjwkzb","wjoprckvz","fmlu","yxsqs","nuqmyiivf","gbgizujoz","bxxxb","sptrhkof","f","uuh","uyoftrd","jfblfdro","fwbh","lnuvw","nkhtvzc","otlnjlmxng","xrkievj","qe","vgur","jpmchp","dsmrhmzsav","xuypdlqf","ipm","qdvwhaqirv","gjdvsg","ocuvuraln","nwkpcjfzs","gftlvkvtsy","rmvvcpiy","wfo","jjdfgz","dmckkg","ouqcb","n","exp","hzccsfisdg","xwfxrked","oaba","eajeavpgk","wmvvcpiy","phuzhfet","spvhcjcjkf","zuaqjn","mcdp","ovbcho","awndm","nmhwviqsh","vxicuxvo","fzxwjrt","qpzmdtbzm","mnfcip","hcqbf","qfs","ogyyhjn","maoemq","cbsyti","wndk","ykk","dnbqgptwdi","mdaxwnf","mkdsh","bdqcwlunm","apntxmz","zkpibygdg","mknndceh","kbcftqbvyl","mlwn","pkjlb","ulqy","lkf","vdieyjkj","bupa","tjv","opqbpmpt","gr","jmkrolrp","clafjy","ofxf","ek","tcpkl","ozoijnd","uybm","hn","zythamzz","ayqdabeg","nfkp","seeed","wpbbf","fkyvotinr","nsfhob","bnsfqa","bvlebiiljh","hpycw","atwyi","buigtg","nojhqg","zeatqt","nnfcip","pteqfne","byzivljxfx","kngtchkh","ublip","bsbevyxreh","aykodk","ltwinj","kvlebiiljh","bbbeibja","vbgjnz","tjvy","rvo","ahnghgjx","clkmga","znwvzwi","sdxmvq","yjcz","pdvlteoh","fzqokaw","iom","pnjx","mlsjpedb","eufhzqyt","cxasfr","lp","scnlouri","cbpyzhmmpn","stfmxjpyn","ixazbbk","lznzlkkvsr","gwdiyzot","mzt","fz","ge","vvj","uzge","evvp","iazduxrwqh","fpnouyya","sdrldphp","r","hfbsco","eukeuowg","jquhlraxje","ksdvhnc","cmj","cgnqev","soamuijlq","xx","mrikzjfdj","spdgfkb","ygsrjpglui","uf","qygxiduzt","rbsrpcsuin","iworwissw","cnsbagxt","khf","bacwrqtmj","krlo","xdvnms","wvh","bnr","orcakqbj","ijhfqvoa","waf","vhimahp","bspizjin","nvbcho","rcjts","mf","rzoijnd","omwekniv","ow","fp","ypqzcdkz","ntaikqd","wpycw","hqkjmwm","cezjxigi","ifwzxq","xkommk","ygdeztnl","dwin","hfrgsyjmqj","nvurxqhage","ycjts","fygjo","ix","ct","fuhowzonh","ziwfbeohxp","zjjn","csxemb","nbrjxkgk","evmp","ah","snxi","wkjkoyeyn","ynlvh","kkumbufht","rc","gprtqz","juro","tdd","tyko","neyisbvnd","bybmwsxwh","silpcrif","agozvuxr","vgpk","cgt","huth","oppmx","kb","nhbf","qqbzg","tingkixov","zsygmj","vmf","rgj","rkkfswqiay","paqqtsdboi","hauizhiz","rpuophvhtg","tbmwbkgmtc","pmw","crr","ohd","xrox","cvf","ocjje","gjs","y","glqqjnye","xmmwck","nxldrwb","cgubnevt","yzllnsnuy","kpoy","wuuwlqvpvt","hcl","z","kbhhg","xdelalwwiy","vbrf","go","qd","uzrdvqrcz","nj","qhtmsbuvnl","vrfpnpkx","eaafhjvd","ksocgyzw","qmx","ob","pqyoep","peizqg","qb","rmfk","csq","bmnlcmpb","tycnzkkck","sijexib","fu","npxyo","jifdm","bfbsco","yhaneeeh","grnrnsowv","ahywep","jhcdyajqzw","hunl","ozalifegd","wvdtcrhbus","rng","pszouj","wrxqg","segzex","xlpinmkoms","myehfdqsf","oamgb","tp","qkxay","muq","fhlrvjh","xrq","yhqolylwy","fmjidpdq","nwfp","plmfzopu","raq","aspge","cg","wvkcppffli","ngbft","mvcx","tcvvefngzh","ysvchiviug","gomvkt","ekeiqqw","ygjypjc","bpciyeibml","evtqvma","hkuhjvjyv","dn","fyflcpja","gftzucziet","wwbxpdudxl","zmuqndc","ggoqeid","nmfqmzrfv","jqkdw","kfccwvpsgj","zzvjrgzt","lbpr","chxv","i","uuljtgt","cupdgzqhm","lg","jmp","dr","tsbsekkmyw","lzboy","vuoujrxb","rsdcjae","qbdwbk","tguwbae","qttta","nnnhejwho","jxquldfmaw","zhiaytjbk","vouwn","gxazbbk","urhytjb","dkqhvbocjx","ajjfwoqje","nmomedocu","jlikoyj","jmoo","mse","owhoatludb","eetfffs","zprofcb","fgo","zn","sreveqqc","qmlymw","vswjyppqgc","ljbcrytui","bjppk","wsvowp","ocjui","wmnsqnlb","hts","getgk","pbhbgyci","yxpufkhrp","pzkpkbka","zdz","ykct","xt","uilolvbbnj","o","lggfvojs","bpwzvywuzp","dvpplsvy","nmfamegpoj","dgcqfpqkd","wxoyfq","seqas","egljwyfy","uzedntcz","tazdpd","ezytbwuab","vhabhw","sgpdl","mptqovn","nrimahca","ubtfxqtg","urt","qlm","ynakzoo","wgvuipkblf","iarjzugcd","gs","xnapihbkmm","jfkomz","xszsw","xlc","tultq","xmt","pwr","ecqmkrw","rtmnwbnd","oczlg","fwgvyyef","puxqkvnwj","vua","usq","ysgrk"};
Solution s;

cerr << "expect sth " << s.distinctNames(test1) << endl;;

vector<string> test2 = {
"aaa","baa","caa","bbb","cbb","dbb"
};
cerr << "exect 2 " << s.distinctNames(test2) << endl;

vector<string> test3 = {
"sfuzder","spklurny","kvdolme","kbbdklkpgk","za","mdbsmnjiu","pzydbfwiw","lvvyshmd","ow","ssipb","jucpsquexm","ffuzder","uftruik","ringlxh","jz","sjlxouiv","csdbtsvg","openygbaix","dcn","r","hwql","ok","y","sze","ttptd","atxp","ejfpsea","vjfpsea","lj","drmvufbt","zxambug","ozpxq","qzydbfwiw","lqxik","bjo","rrmvufbt","jvl","rzxaaa","nmfydhawa","shlwkf","rcl","hhn","yrmcsc","yieuzizaeh","nrmvufbt","rinsldgdpp","wqg","tyhkgqcu","rsdbtsvg","zvehtqiqxa","jtz","mjaguebiy","fztbpozhf","zzpxq","ue","foktqxiqe","ztf","dn","lxambug","kinsldgdpp","jhn","k","i","qxtava","roktqxiqe","hr","bwzw","mot","cadj","x","bcep","u","kzydbfwiw","ahku","ijo"
};
cerr << "expect 4934 " << s.distinctNames(test3) << endl;


return 0;
}