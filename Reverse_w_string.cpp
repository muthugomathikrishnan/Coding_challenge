// Link :https://leetcode.com/problems/reverse-words-in-a-string/
class Solution {
private:
    vector<string>split_words(string s){
        vector<string>words;
        string word="";
        for(char c:s){
            if(c!=' ') word+=c;
            else if(!word.empty()){
                words.push_back(word);
                word.clear();
            }
        }
        return words;
    }
public:
    string reverseWords(string s) {
        vector<string> words=split_words(s);
        reverse(words.begin(),words.end());
        string ans="";
        for(int i=0;i<words.size();i++){
            ans+=words[i];
            ans+=' ';
        }
        ans.pop_back();
        return ans;
    }
};
