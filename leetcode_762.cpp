class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        unordered_set<int> primes = { 2,3,5,7,11,13,17,19};
        int cnt=0;
        for(int i=left; i<=right; i++){
            int setbit = __builtin_popcount(i);
            if(primes.count(setbit)){
                cnt++;
            }
        }
        return cnt;
    }
};

// another method to solve it 

class Solution {
public:
    bool isPrime(int n){
        if(n < 2) return false;
        for(int i=2; i<n; i++){
            if(n%i==0) return false;
        }
        return true;
    }
    int countPrimeSetBits(int left, int right) {
        int ans=0;
        for(int i=left; i<=right; i++){
            int setbit = __builtin_popcount(i); // it will tell you the no of set bit in a number 
            if(isPrime(setbit)) ans++;
        }
        return ans;
    }
};