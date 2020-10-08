class Difference:
    def __init__(self, a):
        self.__elements = a

	# Add your code here
    def computeDifference(self):
        self.maximumDifference = abs(max(self.__elements) - min(self.__elements)) 
# End of Difference class