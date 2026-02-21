class Solution {
public:
    unordered_map<string, string> map;
    int count = 0;

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string key = "http://tinyurl.com/" + count++;
        map[key] = longUrl;
        return key;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return map[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));