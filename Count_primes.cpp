// Link : https://leetcode.com/problems/count-primes/

// Sol 1 : Normal solution :

class Solution {
bool Is_prime(int n){
    if(n<2) return 0;
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return 0;
    }
    return 1;
}
public:
    int countPrimes(int n) {
        int count=0;
        int i=2;
        while(i<n){
            if(Is_prime(i)) count++;
            i++;
        }
        return count;
    }
};

// TC -> O(N * n^(1/2))
// SC -> O(1)



// Sol  2:

class Solution {
public:
    int countPrimes(int n) {
        if(n<=2) return 0;
        vector<bool>prime(n,1);
        prime[0]=prime[1]=0;
        for(int i=2;i*i<n;i++){
            if(prime[i]){
                for(int j=i*i;j<n;j+=i) prime[j]=0;
            }
        }
        return count(prime.begin(),prime.end(),1);
    }
};


// TC -> O(n log log n)	
// SC -> O(n)	


