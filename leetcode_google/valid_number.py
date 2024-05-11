"""
import java.util.*;
import java.util.regex.*;
class Solution {
    public boolean isNumber(String s) {
    s=s.toLowerCase();
     Pattern p=Pattern.compile("[+-]?((\\d+)|((\\d+\\.)|(\\d+\\.\\d+)|(\\.\\d+)))(e[+-]?\\d+)?");
     Matcher m=p.matcher(s);
     boolean b=m.matches();
     if(b)
        {
            return true;
        }
        return false;
    }
}
"""
import re

class Solution:
    def isNumber(self, s: str) -> bool:
        s = s.lower()
        pattern = re.compile(r"[+-]?((\d+)|((\d+\.)|(\d+\.\d+)|(\.\d+)))(e[+-]?\d+)?")
        match = pattern.fullmatch(s)
        if match:
            return True
        return False
