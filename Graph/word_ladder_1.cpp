// Link : https://www.naukri.com/code360/problems/word-ladder_1102319?leftPanelTabValue=SUBMISSION
#include<bits/stdc++.h>
int wordLadder(string begin, string end, vector<string> &dict) 
{
    unordered_set<string>st(dict.begin(),dict.end());
    queue<pair<string,int>>q;
    q.push({begin,1});
    st.erase(begin);

    while(!q.empty()){
        string word=q.front().first;
        int step=q.front().second;
        q.pop();
        if(word==end) return step;
        for(int i=0;i<word.size();i++){
            char org=word[i];
            for(char ch='a';ch<='z';ch++){
                word[i]=ch;
                if(st.find(word)!=st.end()){
                    st.erase(word);
                    q.push({word,step+1});
                }
            }
            word[i]=org;
        }
    }
    return -1;
}
