# 🌟 **Substring vs. Subsequence** 🌟

## 🔹 **Substring**  
A **substring** is a contiguous part of a string.  
✅ **Example**: For `"abc"`, the substrings are:  
   - `"a"`, `"ab"`, `"abc"`, `"b"`, `"bc"`, `"c"`  

🧮 **Count Formula**:  
A string of length **n** has **`n(n+1)/2`** substrings.  

---

## 🔹 **Subsequence**  
A **subsequence** is formed by deleting some (or no) characters while keeping the order intact.  
✅ **Example**: For `"abc"`, the subsequences are:  
   - `"a"`, `"b"`, `"c"`, `"ab"`, `"ac"`, `"bc"`, `"abc"`  

🧮 **Count Formula**:  
A string of length **n** has **`2^n`** subsequences (including the empty one).  

---

## 🔥 **Key Difference**  
| Feature    | Substring 🚀 | Subsequence 🎯 |
|------------|------------|---------------|
| **Contiguous?** | ✅ Yes | ❌ No |
| **Order matters?** | ✅ Yes | ✅ Yes |
| **Count Formula** | `n(n+1)/2` | `2ⁿ` |

💡 **Tip:** Every substring is a subsequence, but not every subsequence is a substring!  
