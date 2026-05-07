import math

class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:

        # Step 1: Check if a common divisor can even exist
        if str1 + str2 != str2 + str1:
            return ""
        
        # Step 2: Find GCD of the two lengths
        gcd_len = math.gcd(len(str1), len(str2))
        
        # Step 3: Return the prefix of that length
        return str1[:gcd_len]