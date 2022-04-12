class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>dic(wordList.begin(),wordList.end());
        int c = 1;
        queue<pair<string,int>>q;
        q.push({beginWord,c});
        
        
        while(q.empty()==false)
        {
            auto node = q.front();
            q.pop();
            
            string word = node.first;
            int level = node.second;
            if(word==endWord)
            {
                return level;
            }
            dic.erase(word);
            for(int i=0;i<word.size();i++)
            {
                char c = word[i];
                for(int k=0;k<26;k++)
                {
                    word[i] = 'a'+k;
                    if(dic.find(word)!=dic.end())
                    {
                        q.push({word,level+1});
                    }
                }
                word[i]=c;
            }
        }
        return 0;
    }
};