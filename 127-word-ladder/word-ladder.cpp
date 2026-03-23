class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Put wordList in set for efficient lookup
        unordered_set<string> dict(wordList.begin(), wordList.end());

        if (dict.find(endWord) == dict.end())
            return 0;

        // word , level
        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while (!q.empty()) {
            auto [word, step] = q.front();
            q.pop();

            if (word == endWord)
                return step;

            for(int i=0; i<word.size(); i++) {
                string temp = word;

                for(char c = 'a'; c <= 'z'; c++) {
                    temp[i] = c;
                    if(dict.count(temp)) {
                        q.push({temp, step + 1});
                        dict.erase(temp);       // In a way marking visited
                    }
                }
            }
        }
        return 0;
    }
};