def isAnagram(s,d):
 sc=[0 for i in range(26)]
 dc=[0 for i in range(26)]

 if len(s) != len(d):
   return False

 for c in s:
   idx = ord(c)-ord('a')
   sc[idx] = sc[idx]+1
 
 for c in d:
   idx = ord(c)-ord('a')
   dc[idx] = dc[idx]+1

 for i in range(len(dc)):
   if sc[i]!= dc[i]:
     return False

 return True

if __name__ == '__main__':
 print(isAnagram('alex','erla') )
     
