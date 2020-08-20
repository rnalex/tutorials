import sys


def match(s):
  mkeys={'{':'}','[':']','(':')'}
  mstack=[]

  #Examine all characters
  for c in s:
    #Examine keys
    if c in mkeys.keys():
      mstack.append(c)
    #Match values or the closing paranthesis
    elif c in mkeys.values():
      if len(mstack) == 0:
        return False
      elif mkeys[mstack.pop()] != c:
             return False
  return len(mstack) == 0

s='[llll]'
assert(match(s) == True)
s='()'
assert(match(s) == True)
