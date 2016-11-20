#single line comments

'''
multiple line comments

Similarities in languages 
variables, conditionals, loops, I/O

//Variables
C++ - int a = 5;
Python... a = 5

Python Dynamic Typing - type assigned at runtime
Interperative Language

C++ Static Typing - compiled language

Python has objects
Python Loops - iterator over a collection of lines in a file

]'''
#int
a = 5 

#double
a = 5.678

#string
a = "hello world"

#bool
a = True

#list
a = ['a', 4, 56, "hey im on tv", True]

print a 

#tuple (read-only)
a = (4, 5, 'a', "wow")

print "\n"


print "hello world"

myStr = "four score and seven years ago"

f = myStr.find("seven") #index of seven
print f

c = myStr.count("s") #count instances of s
print c

r = myStr.replace("seven", "many") #replace the word
print r

listInt = [100, 60, 50]
listStr = ["poop", "yes"]
listMix = ["garbage", 69]

listolists = [listInt, listStr, listMix]

#index in a list
listolists[0][0]

#for loops
#for <item> in <collection>
#<collection> can be a list, string, 
for x in listInt:
	print x
	
#prints all items in the list
for y in listolists:
	print y
		
#for loop with index
#range - generate a list of numbers
numbers = range(1, 6)
print numbers
#len represents length of an array

for x in range(0, len(listInt)):#loop through number of items in the list
	print listInt[x]
	
#conditionals
if y < 5:
	print "y < 5"
else: 
	print "y not less than 5"
	
y += 1
print y

#functions
def myFunction(myStr):
	print myStr

myFunction("print a string with this dope af function")
myFunction(5)

def findItem(listToSearch, valueSearchFor):
	#loop through list
	for x in range(0, len(listToSearch)):
		if listToSearch[x] == valueSearchFor:
			index = x
		return index


	
	
	

