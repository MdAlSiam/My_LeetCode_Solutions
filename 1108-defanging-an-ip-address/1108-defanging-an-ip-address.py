class Solution:
    def defangIPaddr(self, address: str) -> str:
        
        ans = ""
        
        for i in range(len(address)):
            currChar = address[i]
            
            if currChar == '.':
                ans += "[.]"
            else:
                ans += currChar
                
        return ans
                
        
                
        
                
            
            