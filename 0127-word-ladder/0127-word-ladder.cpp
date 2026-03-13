class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
                        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord)) return 0;
        queue<string> q;
        q.push(beginWord);
        unordered_set<string> visited;
        visited.insert(beginWord);
        int dist = 1;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                string rv = q.front();
                q.pop();

                for (string word : wordList) {

                    if (diff(rv, word)==1 && !visited.count(word)) {
                        if (endWord == word) {
                            return dist+1;
                        }
                        visited.insert(word);
                        q.push(word);
                    }
                }
            }

            dist++;
        }
        return 0;
    }
    int diff(string a, string b) {
        int diff = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                diff++;
            }
        }
        return diff;
    }
};