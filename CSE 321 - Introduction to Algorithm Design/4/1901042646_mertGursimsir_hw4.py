import random

def firstQuestion():
	n = int(input("\nPlease enter n: "))
	m = int(input("Please enter m: "))
	array = []
	print("\n    ", end = "")
	for i in range(n):
		print(" B{} ".format(i+1), end = "")
	for i in range(m):
		row = []
		print("\n A{} ".format(i+1), end = "")
		for j in range(n):
			row.append(random.randint(0, 100))
			print("%3d " % (row[j]), end = "")
		array.append(row)

	path = []
	points = [[0, 0]]
	score = pathFinder(array, 0, 0, path)
	print("\n\nRoute : A1B1 -> ", end="")
	path = path[1]
	for i in range(1, n+m-2):
		print("A{}B{} -> ".format(path[0][0]+1, path[0][1]+1), end="")
		points.append([path[0][0], path[0][1]])
		path = path[1]
	print("A{}B{}".format(path[0][0]+1, path[0][1]+1))
	points.append([path[0][0], path[0][1]])

	print("Points: ", end="")
	for i in range(len(points)-1):
		print("{} + ".format(array[points[i][0]][points[i][1]]), end="")
	print(array[points[len(points)-1][0]][points[len(points)-1][1]], end="")
	print(" = {}".format(score))

def pathFinder(array, row, column, path):
	n = len(array)
	m = len(array[0])
	path.append((row, column))

	if row == n-1 and column == m-1:
		return array[row][column]

	if row < n - 1 and column < m - 1:
		firstPath = []
		firstWay = pathFinder(array, row, column+1, firstPath)

		secondPath = []
		secondWay = pathFinder(array, row+1, column, secondPath)

		if firstWay > secondWay:
			path.append(firstPath)
			total = array[row][column] + firstWay

		else:
			path.append(secondPath)
			total = array[row][column] + secondWay

	elif row == n - 1:
		tempPath = []
		total = array[row][column] + pathFinder(array, row, column+1, tempPath)
		path.append(tempPath)

	else:
		tempPath = []
		total = array[row][column] + pathFinder(array, row+1, column, tempPath)
		path.append(tempPath)

	return total

##########################################################################################

def secondQuestion():
	array = []
	size = int(input("\nPlease enter array size: "))
	print("Array: ", end="")
	for i in range(size):
		array.append(random.randint(0, 100))
		print(array[i], end=" ")
	print("\nMedian:", end=" ")
	
	if (len(array) % 2 == 0):
		k = len(array)/2
		index = array.index(QuickSelect(array, int(k), 0, len(array)-1))
		indexNext = array.index(QuickSelect(array, int(k)+1, 0, len(array)-1))
		print((array[index] + array[indexNext]) / 2)
		print("(Average of middle 2 elements.)")
	else:
		k = len(array)/2 + 1
		print(QuickSelect(array, int(k), 0, len(array)-1))
		print("(Middle element.)")

def LomutoPartition(array, l, r):
	p = array[r]
	s = l

	for i in range(l, r):
		if array[i] <= p:
			temp = array[s]
			array[s] = array[i]
			array[i] = temp
			s = s + 1

	temp = array[s]
	array[s] = array[r]
	array[r] = temp

	return s

def QuickSelect(array, k, l, r):
	if (k > 0 and k <= r - l + 1):
		s = LomutoPartition(array, l, r)

		if (s - l == k - 1):
			return array[s]
		if (s - l > k - 1):
			return QuickSelect(array, k, l, s-1)
		return QuickSelect(array, k-s+l-1, s+1, r)
	return -1


##########################################################################################
class Node:
    def __init__(self, data=None):
        self.data = data
        self.next = None

class CircularLinkedList:
    def __init__(self):
        self.head = None

    def add(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
            new_node.next = self.head
        else:
            cur = self.head
            while cur.next != self.head:
                cur = cur.next
            cur.next = new_node
            new_node.next = self.head

    def addPlayers(self, size):
    	for i in range(size):
    		self.add(i+1)

    def winner(self):
    	while self.head.next != self.head:
    		self.head.next = self.head.next.next
    		self.head = self.head.next
    	return self.head.data

def thirdQuestionA():
	size = int(input("\nPlease enter number of players: "))
	players = CircularLinkedList()
	players.addPlayers(size)
	print("Player {} is the winner!".format(players.winner()))

##########################################################################################

def thirdQuestionB():
	playerNum = int(input("\nPlease enter number of players: "))
	print("Player {} is the winner!".format(decreaseAndConquer(playerNum)))


def decreaseAndConquer(playerNum):
	if playerNum == 1:
		return 1

	if playerNum % 2 == 0:
		return 2 * decreaseAndConquer(playerNum/2) - 1
	else:
		return 2 * decreaseAndConquer((playerNum-1)/2) + 1
	

##########################################################################################

userInput = int(input("\nHello there! How can I help you, please choose:\n1 - 2D Map Game\n2 - Median\n3 - Circular Elimination Game\n4 - Decrease-and-conquer Elimination Game\nEnter: "))
if (userInput == 1):
   	firstQuestion()
if (userInput == 2):
	secondQuestion()
if (userInput == 3):
	thirdQuestionA()
if (userInput == 4):
	thirdQuestionB()
print("\nSO LONG!")