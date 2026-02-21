public class Codec {
    private readonly Dictionary<string, string> hashmap;

    public Codec() {
        hashmap = new Dictionary<string, string>();
    }

    // Encodes a URL to a shortened URL
    public string encode(string longUrl) {
        string key;
        do {
            key = Convert.ToBase64String(Guid.NewGuid().ToByteArray())
                .Replace("+", "-")
                .Replace("/", "_")
                .TrimEnd('=');
        } while(hashmap.ContainsKey(key));

        hashmap[key] = longUrl;
        return key;
    }

    // Decodes a shortened URL to its original URL.
    public string decode(string shortUrl) {
        return hashmap[shortUrl];
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.decode(codec.encode(url));