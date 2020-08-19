#
#Unique emails
#
class Solution(object):
    def numUniqueEmails(self, emails):
        """
        :type emails: List[str]
        :rtype: int
        """
        unique_emails = set()
        for e in emails:
            parts = e.split('@')
            lname = parts[0]
            dname = parts[1]
            ulname = lname[:lname.index('+')] if '+' in lname else lname
            ulname = ulname.replace('.','')
            unique_emails.add(ulname+'@'+dname)
        #print(emails)
        #print(unique_emails)
        return len(unique_emails)

s = Solution()
n = s.numUniqueEmails(["test.email+alex@testcode.com","test.e.mail+bob.cathy@testcode.com","testemail+david@tes.tcode.com"])
assert(n==2)


