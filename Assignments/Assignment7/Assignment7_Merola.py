import math
import random

def madLibsGame():
	
	userWordBank = []
	wordTypeBank = []
	
	#template variables
	Temp1 = "Be kind to your <noun>-footed <plural noun>, or a duck may be somebody's <noun>."
	Temp2 = "It was <adjective1> of the <noun1>, it was <adjective2> of the <noun2>."
	Temp3 = "<plural noun>? I don't have to show you any <adjective> <plural noun>!"
	Temp4 = "My <noun> always said <noun> was like a box of <noun>. You never know what you're gonna get."
	Temp5 = "One <time of day>, I <verb> a <noun> in my pajamas. How he got in my pajamas, I don't know."
	
	TempList = [Temp1, Temp2, Temp3, Temp4, Temp5]
	
	
	#randomly chooses a template
	randInt = random.randint(0,6)

 	Template = TempList[randInt]
 	

	#take Mad Libs words
	for index in range(len(Template)):

		TempParse = Template[index:len(Template)] #shortens the string after each index as to not look for past brackets later
		
		if (Template[index] == "<"): #compares each index until it finds a bracket
			frontBrack = TempParse.find("<")
			endBrack = TempParse.find(">")
			wordType = TempParse[frontBrack: endBrack+1] #finds the word between brackets

			userWord = raw_input("Enter a %s: " %wordType) #asks user to enter a word based on wordtype

			userWordBank.append(userWord #adds users word to a list
			wordTypeBank.append(wordType) #adds wordtype to list

		else:
			continue
	
	'''end for'''
	
	#print new mad lib
	for bankIndex in range(len(wordTypeBank)): #for every index in the bank, replace the wordtype with word
		if (bankIndex == 0):
			MadLib = Template.replace(wordTypeBank[bankIndex], userWordBank[bankIndex]) 
		else:
			MadLib = MadLib.replace(wordTypeBank[bankIndex], userWordBank[bankIndex])
	
	return MadLib

'''end madLibsGame'''

if __name__ == '__main__':

	gameOver = False
	playGame = raw_input("Do you want to play a game? (y) or (n)")

	if (playGame == "y"):
		while (gameOver != True):
			print madLibsGame()
			
			choice = raw_input("Do you want to play again? (y) or (n)")
			if (choice == "n"):
				gameOver == True
				print "Goodbye"
				break
				
		'''end while'''
	else:
		print "Goodbye"


'''end'''
