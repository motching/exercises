#!/usr/bin/python3

import itertools

class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """

        if not s: return 0
        print (s, '\n')

        maxlen = 1
        curlen = 0
        substr = ''
        foundDup = False
        for c in list(s):
            if c in substr:
                foundDup = True
                maxlen = max(maxlen, len(substr))
                substr = list(itertools.dropwhile(lambda x: x != c, substr))
                substr = substr[1:]
            substr += c

        maxlen = max(maxlen, len(substr))
        if not foundDup:
            maxlen = len(s)
        return maxlen

print (Solution().lengthOfLongestSubstring('abcabcbb'))
print (Solution().lengthOfLongestSubstring('bbbbb'))
print (Solution().lengthOfLongestSubstring('pwwkew'))
print (Solution().lengthOfLongestSubstring('aab'))
print (Solution().lengthOfLongestSubstring('dvdf'))
print (Solution().lengthOfLongestSubstring('bpfbhmipx'))
