/*
给定一个单词数组和一个长度 maxWidth，重新排版单词，使其成为每行恰好有 maxWidth 个字符，且左右两端对齐的文本。

你应该使用“贪心算法”来放置给定的单词；也就是说，尽可能多地往每行中放置单词。必要时可用空格 ' ' 填充，使得每行恰好有 maxWidth 个字符。

要求尽可能均匀分配单词间的空格数量。如果某一行单词间的空格不能均匀分配，则左侧放置的空格数要多于右侧的空格数。

文本的最后一行应为左对齐，且单词之间不插入额外的空格。

说明:

单词是指由非空格字符组成的字符序列。
每个单词的长度大于 0，小于等于 maxWidth。
输入单词数组 words 至少包含一个单词。
示例:

输入:
words = ["This", "is", "an", "example", "of", "text", "justification."]
maxWidth = 16
输出:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
示例 2:

输入:
words = ["What","must","be","acknowledgment","shall","be"]
maxWidth = 16
输出:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
解释: 注意最后一行的格式应为 "shall be    " 而不是 "shall     be",
     因为最后一行应为左对齐，而不是左右两端对齐。       
     第二行同样为左对齐，这是因为这行只包含一个单词。
示例 3:

输入:
words = ["Science","is","what","we","understand","well","enough","to","explain",
         "to","a","computer.","Art","is","everything","else","we","do"]
maxWidth = 20
输出:
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]
*/


class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int size = 0;
        int start  = 0;
        int end = 0;
        int len = 0;
        int remindNum = 0;
        int blankNum = 0;
        string str;
        vector<string> result;
        size = words.size();

        for (int i = 0; i < size; ++i) {
            if (len + words[i].length() + end - start > maxWidth) {
                if (end - start == 1) {
                    str += words[start] + string(maxWidth - len, ' ');
                }
                else {
                    blankNum = (maxWidth - len) / (end - start - 1);
                    remindNum = (maxWidth - len) % (end - start - 1);

                    for (int j = start; j < end - 1; j++) {
                        str += words[j] + string(remindNum-- > 0 ? blankNum+1 : blankNum, ' ');
                    }
                    int strlen = str.length();
                    str += words[end - 1];
                }
                result.push_back(str);
                len = 0;
                start = end;
                str = "";
            }
            len += words[i].length();
            ++end;
        }
        if (len > 0) {
            for (int i = start; i < size; i++) {
                str += words[i];
                str += maxWidth - str.length() > 0 ? " " : "";
            }
            if (maxWidth - str.length() > 0) {
                str += string(maxWidth - str.length(),' ');
            }
            
             result.push_back(str);
        }
        return result;
    }
};