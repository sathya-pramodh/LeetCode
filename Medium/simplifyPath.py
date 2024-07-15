# Problem Link
# https://leetcode.com/problems/simplify-path/

class Solution:
    def simplifyPath(self, path: str) -> str:
        splits = path.split("/")
        dirs = ["/"]
        cur = "/"
        for split in splits:
            if split == "" or split == ".":
                continue
            if split == "..":
                if len(dirs) != 0 and cur != "/":
                    dirs.pop()
                    cur = dirs[len(dirs) - 1]
            else:
                dirs.append(split + "/")
                cur = split
        ans = ""
        for direc in dirs:
            ans += direc
        return ans[:len(ans) - 1] if ans != "/" else ans
