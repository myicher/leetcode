/*
给定一个字符串 s 和一些长度相同的单词 words。找出 s 中恰好可以由 words 中所有单词串联形成的子串的起始位置。

注意子串要与 words 中的单词完全匹配，中间不能有其他字符，但不需要考虑 words 中单词串联的顺序。

 

示例 1：

输入：
  s = "barfoothefoobarman",
  words = ["foo","bar"]
输出：[0,9]
解释：
从索引 0 和 9 开始的子串分别是 "barfoor" 和 "foobar" 。
输出的顺序不重要, [9,0] 也是有效答案。
示例 2：

输入：
  s = "wordgoodgoodgoodbestword",
  words = ["word","good","best","word"]
输出：[]
 */


class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
       vector<int> result;
       map<string, int> mapWords;
       string tmp;
       string word;
       int pos  = 0;
       int nWordLen = 0;
       int nWordSize = 0;
       int j = 0;
       int i = 0;
       int code = 1;


       if (words.size() == 0 || s.empty()) {
           return result;
       }

       nWordLen = words[0].length();
       nWordSize = words.size();

       int nSignCount[nWordSize + 1];
       int record[nWordSize + 1];
       map<string,int>::iterator it;

       memset(nSignCount, 0, sizeof(nSignCount));
       for (i = 0; i < nWordSize; i++) {
           word = words[i];
           it = mapWords.find(word);
           if (it == mapWords.end()) {
               mapWords[word] = code;
               nSignCount[code]++;
               code++;
           }
           else {
               nSignCount[it->second]++;
           }
       }

       for (i = 0; i < s.length() - nWordLen * nWordSize + 1; i++) {
           memset(record, 0, sizeof(record));
           tmp = s.substr(i, nWordLen*nWordSize);
           for (j = 0, pos = 0; j < nWordSize; j++, pos += nWordLen) {
               word = tmp.substr(pos, nWordLen);
               it = mapWords.find(word);
               if (it == mapWords.end()) {
                   break;
               }
               else {
                   record[it->second]++;
                   if (record[it->second] > nSignCount[it->second]) {
                       break;
                   }
               }
           }
           if (j == nWordSize) {
               result.push_back(i);
           }
       }

       return result;
   }
};


   