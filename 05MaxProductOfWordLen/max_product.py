from typing import List


class Solution:
    def max_uniq(self, word, words):
      can = []
      for w in words:
          contained = False
          for c in word:
              if c in w:
                  contained = True
                  continue
          if not contained:
              can.append(w)
      can.sort(key = lambda x: len(x), reverse=True)
      return can[0] if len(can) > 0 else None

    def maxProduct(self, words: List[str]) -> int:
        max_prod = 0
        for w in words:
            longest = self.max_uniq(w, words)
            if longest is not None:
                new_prod = len(longest) * len(w)
                if new_prod > max_prod:
                    max_prod = new_prod
        return max_prod

s = Solution()
words = ["abcw","baz","foo","bar","xtfn","abcdef"]
print(f"expect xtfn {s.max_uniq(words[0],words)}")
words = ["abcw","baz","foo","bar","xtfn","abcdef"]
print(f"expect 16 {s.maxProduct(words)}")
words = ["a","ab","abc","d","cd","bcd","abcd"]
print(f"expect 4 {s.maxProduct(words)}")
words = ["a","aa","aaa","aaaa"]
print(f"expect None {s.max_uniq(words[0], words)}")
print(f"expect 0 {s.maxProduct(words)}")