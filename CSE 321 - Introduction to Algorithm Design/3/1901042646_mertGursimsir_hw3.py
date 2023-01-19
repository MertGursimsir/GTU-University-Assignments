class Graph:
   def __init__(self, graph):
      self.graph = graph
      self.vertices = list(self.graph.keys())
      self.visited = [False for i in range(len(self.vertices))]
      self.stack   = []

   def topSortDFS(self):
      for i in range(len(self.vertices)):
         if not self.visited[i]:
            self.topSortDFSHelper(i)

      print(self.stack)

   def topSortDFSHelper(self, i):
      self.visited[i] = True

      for j in range(len(self.graph[self.vertices[i]])):
         if not self.visited[self.vertices.index(self.graph[self.vertices[i]][j])]:
            self.topSortDFSHelper(self.vertices.index(self.graph[self.vertices[i]][j]))

      self.stack.insert(0, self.vertices[i])

   def topSortNonDFS(self):
      indegree = [0 for i in range(len(self.vertices))]
      order = []
      orderHelper = []

      for i in self.vertices:
         for j in self.graph[i]:
            indegree[self.vertices.index(j)] += 1

      for i in range(len(indegree)):
         if indegree[i] == 0:
            orderHelper.append(self.vertices[i])      

      while len(orderHelper) != 0:
         currentItem = orderHelper.pop(0)
         order.append(currentItem)

         for i in self.graph[currentItem]:
            indegree[self.vertices.index(i)] -= 1
            if indegree[self.vertices.index(i)] == 0:
               orderHelper.append(i)

      print(order)


def getGraph():
   graphDict = {}
   numV = int(input("\nEnter number of vertices: "))
   print("Enter vertices one by one.")
   for i in range(numV):
      temp = input("{}. Vertex: ".format(i+1))
      graphDict[temp] = list()

   print("\nEnter edges. Print - to exit.", end="")
   for x in graphDict.keys():
      temp = input("\nEdge from {}: ".format(x))
      while temp != "-":
         if temp not in graphDict.keys():
            print("This vertex doesn't exist, try again.")
         else:
            graphDict[x].append(temp)
         temp = input("Edge from {}: ".format(x))
         

   return graphDict


def TopDFS():
   graphDict = getGraph()
   graph = Graph(graphDict)
   print("\nDFS-BASED TOPOLOGICAL SORT")
   print("--------------------------")
   print("\nTopological sort: ")
   graph.topSortDFS()

def nonTopDFS():
   graphDict = getGraph()
   graph = Graph(graphDict)
   print("\nnon-DFS-BASED TOPOLOGICAL SORT")
   print("------------------------------")
   print("\nTopological sort: ")
   graph.topSortNonDFS()


#############################################################################

def power(a, n):
   if n == 0:
      return 1
   elif n%2 == 0:
      temp = power(a, n/2)
      return temp * temp
   else:
      temp = power(a, (n-1)/2)
      return temp * temp * a

def lognPower():
   print("\nCALCULATING a^n IN O(LOGN) TIME")
   print("-------------------------------")
   a = int(input("Please enter a: "))
   n = int(input("Please enter n: "))
   print("Result is:", end=" ")
   print(power(a, n))

#############################################################################


def isNumSafe(row, column, number, sudoku):
   for i in range(9):
      if sudoku[i][column] == number:
         return False

   for i in range(9):
      if sudoku[row][i] == number:
         return False

   boxStartRow = row - row%3
   boxStartCol = column - column%3
   for i in range(3):
      for j in range(3):
         if sudoku[i + boxStartRow][j + boxStartCol] == number:
            return False

   return True

def sudokuSolverHelper(sudoku, row, column):
   if (row == 8 and column == 9):
      return True
   elif column == 9:
      row = row + 1
      column = 0

   if sudoku[row][column] == 0:
      for i in range(1, 10):
         if isNumSafe(row, column, i, sudoku):
            sudoku[row][column] = i
            if sudokuSolverHelper(sudoku, row, column+1):
               return True
         sudoku[row][column] = 0
      return False
   else:
      return sudokuSolverHelper(sudoku, row, column+1)

def sudokuSolver(sudoku):
   return sudokuSolverHelper(sudoku, 0, 0)

def printSudoku(sudoku):
   for i in range(9):
      print("{} | {} | {} ||| {} | {} | {} ||| {} | {} | {}".format(sudoku[i][0], sudoku[i][1], sudoku[i][2], sudoku[i][3], sudoku[i][4], sudoku[i][5], sudoku[i][6], sudoku[i][7], sudoku[i][8]))
      if i == 2 or i == 5:
         print("=====================================")
      elif (i != 8):
         print("-------------------------------------")


def Sudoku():
   print("\nSOLVING 9x9 SUDOKU BY EXHAUSTIVE SEARCH")
   print("---------------------------------------")

   sudoku = []
   for i in range(9):
      temp = []
      for j in range(9):
         inp = int(input("Enter {}. row and {}. column: ".format(i+1, j+1)))
         while inp < 0 or inp > 9:
            print("Invalid input, try again.")
            inp = int(input("Enter {}. row and {}. column: ".format(i+1, j+1)))
         temp.append(inp)
      sudoku.append(temp)
      print()

   if not sudokuSolver(sudoku):
      print("Invalid sudoku.")
   printSudoku(sudoku)


################################################################################

userInput = int(input("Hello there! How can I help you, please choose:\n1 - DFS based topological order\n2 - non DFS based topological order\n3 - a^n\n4 - Sudoku\nEnter: "))
while userInput > 4 or userInput < 1:
   userInput = int(input("\nEnter again: "))
if (userInput == 1):
   TopDFS()
elif (userInput == 2):
   nonTopDFS()
elif (userInput == 3):
   lognPower()
elif (userInput == 4):
   Sudoku()
print("\nSO LONG!")