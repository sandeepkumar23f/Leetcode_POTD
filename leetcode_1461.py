class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        st = set()
        n = len(s)
        codes = 2**k
        for i in range(k,n+1):
            sub = s[i-k:i]
            if sub not in st:
                st.add(sub)
                codes = codes -1
            if codes == 0:
                return True
        
        return False
        