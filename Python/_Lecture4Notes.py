#a = raw_input("enter a number")
#print a 

'''
def openFileAndRead(filename):
	myFile = open(filename, "r")
	print myFile
	print myFile.readLine() #readline is a method in the file object
	print type(myFile.readline())
'''
	
	
if __name__ == "__main__":
	filename = "boulderData.txt" #locally stored
	#openFileAndRead(filename)
	
	
	#dictionaries
	#collection of data like a map
	
	students = {'Matt': 'Denver', 'Jessica': 'Boulder'}
	#each key (matt/jessica) have a value
	
	print students 
	print students['Matt']
	
	print "\n"
	
	for x in students:
		print "key is", x
		print "value is ", students[x]
		print "\n"
	
	scores = {'Matt': 60, 'Jessica': 78}
	
	for x in scores:
		print x
		print scores[x]
		
	scores['Rhonda'] = 65 #add new key to dictionary
	for x in scores:
		print x
		
	print "\n"
		
	#values can be any data type
	schedule = {'Matt': ['CSCI1310', 'APPM1350', 'PHYS110'], 'Jessica': ['CSCI1300', 'HUEN1010', 'CHEN2270']}
	for x in schedule:
		print x
		print schedule[x] #or schedule[x][0] to get first element of list
	
	
'''end main'''
	
	
