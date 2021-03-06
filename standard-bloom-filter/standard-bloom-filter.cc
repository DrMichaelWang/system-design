# include <bitset>

const int MAXN = 200000;
const int MOD = 100000;

class HashFunction {
    public:
    HashFunction(int m, int b): mod(m), base(b) {}
    int get_hash(const string &s) {
        int ans = 0;
        for (int i = 0; s[i]; ++i) {
            ans = (ans * base + s[i]) % mod;
        }
        return ans;
    }
    
    private:
    int mod, base;
};

class StandardBloomFilter {
    public:
    StandardBloomFilter(int k) {
        // initialize your data structure here
        int mod = MOD, base = 3;
        for (int i = 0; i < k; ++i) {
            HashFunction *hf = new HashFunction(mod, base);
            hfs.push_back(hf);
            ++mod;
            base += 2;
        }
        n_hash = k;
    }
    
    void add(string& word) {
        // Write your code here
        for (int i = 0; i < n_hash; ++i) {
            int h = hfs[i]->get_hash(word);
            bs.set(h);
        }
    }
    
    bool contains(string& word) {
        // Write your code here
        for (int i = 0; i < n_hash; ++i) {
            int h = hfs[i]->get_hash(word);
            if (!bs[h]) return false;
        }
        return true;
    }
    
    private:
    int n_hash;
    vector<HashFunction*> hfs;
    bitset<MAXN> bs;
};
