#functions not necessary
import math

def printHelloWorld():
	print "hello world"
'''end helloworld'''

# write a function given a list of numbers and a single number.
# returns true if any number in the list is greater than the single num
def greaterThan(numList, num):
	
	for x in numList:
		if (x > num):
			return True
		else:
			continue
	'''end for'''
			
	return False
'''end greaterThan'''

# write a function that takes a string and an index
# returns the substring from index to end
def subStr(string, index):
	s = string[index:len(string)]
	
	return s
'''end subStr'''

# write a function that takes 2 characters and a string
# returns substring between the two characters
def findSubStr(string, char1, char2):
	
	index1 = string.find(char1)
	index2 = string.find(char2)
	
	d = string[index1: index2+1]
	
	return d
'''end findSubStr'''


if __name__ == "__main__":
	
	printHelloWorld()
	
	numList = [14, 2, 3, 67]
	num = 20
	
	print greaterThan(numList, num)
	
	num = 80
	print greaterThan(numList, num)
	
	string = "my favorite string ever"
	s = string [1:4]
	
	print s
	s = string[0:1] #lower bound inclusive upper bound not
	print s
	print type(s) #returns type of variable
	
	print "\n"
	
	index = 3
	print subStr(string, index)
	
	print findSubStr(string, 'a', 'r')
	
	
'''end main'''
