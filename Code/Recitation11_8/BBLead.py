		
def main():
	print BasketballLead(23, 50, True)
	print BasketballLead(2, 100, False)
	
	
def BasketballLead (pointDiff, timeLeft, leadHasBall):
	pointDiff -= 3
	
	if (leadHasBall == True):
		pointDiff += 0.5
	else:
		pointDiff -= 0.5
		
	if (pointDiff < 0):
		pointDiff = 0
		
	pointDiff = pointDiff*pointDiff
	
	if (pointDiff > timeLeft):
		return True
	else:
		return False


if __name__ == '__main__':
	main()
