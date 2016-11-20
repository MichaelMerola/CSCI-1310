
import csv

def createDictionary(filename):
	
	slangDict = {}
	
	#open file and read every newline
	with open(filename, "rU") as f:
		reader = csv.reader(f)
		
		for row in reader:
			#add keys to dictionary
			slangDict[row[0]] = row[1]
			
		return slangDict
	
	
'''end createDictionary'''

def main():
	
	filename = "textToEnglish.csv"
	txtDict = createDictionary(filename)
	
	gamequit = False
	while (gamequit != True):
		
		#get user input
		userInput = raw_input("Enter text to be translated to English! (Q to quit)")
		
		if (userInput == 'Q'):
			#quit game
			gamequit = True
		else:
			#split input into readable chunks
			textArr = userInput.split()
			
			#find translation in array of txt
			for i in textArr:
				if (i in txtDict):
					print txtDict[i]
				else:
					print "(Nothing was found)"
					
				print "\n"
			'''end for'''
			
		'''end else'''
	
'''end main'''

if __name__ == "__main__":
	
	main()
