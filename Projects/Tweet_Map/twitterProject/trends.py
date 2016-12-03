import sys
import json
from geo import GeoPosition
from tweet import Tweet
from state import load_states
from country import Country
from parse import load_sentiments
from colors import get_sentiment_color

class SentimentAnalysis:
	def __init__(self):
		self.sentiments = load_sentiments()
		self.states = load_states()
	def showCountry(self):
		self.usa = Country(self.states, 1200)
	def setSentiment(self, code, score):
		for state in self.states:
			if state.abbrev() == code:
				state.addSentiments(score)

	def analyzeData(self, fileName, query):
		
		rawJSONTweetData = open(fileName, "r")
		tweetLibrary = []

		#import data into classes
		for line in rawJSONTweetData:
			rawTweetData = json.loads(line)
			tweetMessage = rawTweetData["text"]
			tweetTime = rawTweetData["created_at"]
			tweetLocation = GeoPosition(rawTweetData['coordinates'][1], rawTweetData['coordinates'][0])
			for element in query:
				if (element in tweetMessage):
					tweetLibrary.append(Tweet(tweetMessage, tweetTime, tweetLocation))
		'''end import for'''

		#parse through every tweet to get a sentiment score
		for twt in tweetLibrary:
			tweetTxt = twt.message().split(" ")
			tweetGeo = twt.position()
			shortDist = -1
			closestState = " "
			sentScore = 0
			count = 1
			
			#find closest state
			for state in self.states:
				dist = tweetGeo.distance(state.centroid())
				if shortDist == -1:
					shortDist = dist
					closestState = state.abbrev()

				elif dist < shortDist:
					shortDist = dist
					closestState = state.abbrev()

			#find sentiment within tweet
			for word in tweetTxt:
				if word in self.sentiments:
					sentScore += self.sentiments[word]
					count += 1
			
			#calculate avg score and store it in the sentiment list for that state
			avgScore = sentScore/count

			self.setSentiment(closestState, avgScore)
		'''end for'''
		
	'''end analyzeData'''           
    
#finish



if __name__ == "__main__":
	if len(sys.argv) > 1:
		query = sys.argv[1:]
		print "Searching Query...\n"
	else:
		print "error: no query"
		
	sa = SentimentAnalysis()
	
	#analyze tweet data from four data files with time
	fileName = "tweets_with_time.json"
	sa.analyzeData(fileName, query)
	print "Loading DataSet1..."
	
	fileName = "tweets_with_time_2.json"
	sa.analyzeData(fileName, query)
	print "Loading DataSet2..."
	
	fileName = "tweets_with_time_3.json"
	sa.analyzeData(fileName, query)
	print "Loading DataSet3..."
	
	fileName = "tweets_with_time_4.json"
	sa.analyzeData(fileName, query)
	print "Loading DataSet4...\n"

	sa.showCountry()

	for state in sa.states:
		sa.usa.setFillColor(state.abbrev(), get_sentiment_color(state.getAverageSent()))

#finish
