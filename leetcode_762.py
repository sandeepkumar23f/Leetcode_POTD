class Solution:
    def isPrime(self,n: int) -> bool:
        if n < 2:
             return False
        for i in range(2,int(n**0.5)+1):
            if(n % i ==0):
                return False
            
        return True
    def countPrimeSetBits(self, left: int, right: int) -> int:
        ans=0
        for i in range(left,right+1):
            setbit = i.bit_count()
            if self.isPrime(setbit):
                ans+=1
            
        return ans
        