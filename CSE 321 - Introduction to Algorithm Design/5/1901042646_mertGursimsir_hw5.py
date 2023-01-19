import random

def longest_substring(strings):
  if len(strings) == 0:
    return ""

  if len(strings) == 1:
    return strings[0]

  if len(strings) == 2:
    commonPart = compare_characters(strings[0], strings[1])

  else:
    middle = len(strings) // 2
    left = strings[:middle]
    right = strings[middle:]

    commonInLeft  = longest_substring(left)
    commonInRight = longest_substring(right)

    commonPart = compare_characters(commonInLeft, commonInRight)

  return commonPart

def compare_characters(string1, string2):
  commonPart = ""
  limit = min(len(string1), len(string2))
  for i in range(limit):
    if string1[i] == string2[i]:
      commonPart += string1[i]
    else:
      break
  return commonPart

def firstQuestion():
  strings = []
  inputSize = int(input("\nEnter size of the array: "))
  print()
  for i in range(inputSize):
    strings.append(input("Enter {}. string: ".format(i+1)))
  
  print("\nLongest common substring is: ", end="")
  print(longest_substring(strings))

##########################################################################################

def find_min_and_index(array, left, right):
  minimum = array[left]
  index = left
  for i in range(left + 1, right + 1):
    if array[i] < minimum:
      minimum = array[i]
      index = i
  return (minimum, index)

def find_max_and_index(array, left, right):
  maximum = array[left]
  index = left
  for i in range(left + 1, right + 1):
    if array[i] > maximum:
      maximum = array[i]
      index = i
  return (maximum, index)

def merchant(array, left, right):
    if left >= right:
        return (0, len(array)-1, len(array)-1)

    middle = (left + right) // 2

    left_difference_max  = merchant(array, left, middle)
    right_difference_max = merchant(array, middle + 1, right)

    left_min  = find_min_and_index(array, left, middle)
    right_max = find_max_and_index(array, middle + 1, right)

    if max(left_difference_max[0], right_difference_max[0]) >= (right_max[0] - left_min[0]):
      if left_difference_max[0] >= right_difference_max[0]:
        return left_difference_max
      else:
        return right_difference_max
    else:
      return (right_max[0]-left_min[0], left_min[1], right_max[1])

def secondQuestionA():
  array = createRandomArray()
  size = len(array)
  if size == 0:
    print("\nNo sufficient number of prices.")
  elif size == 1:
    print("\nBuy on Day0 for {}₺ and sell on Day0 for {}₺.".format(array[0], array[0]))
    print("Your profit is 0₺.")
  else:
    info = merchant(array, 0, len(array)-1)
    print("\nBuy on Day{} for {}₺ and sell on Day{} for {}₺.".format(info[1], array[info[1]], info[2], array[info[2]]))
    print("Your profit is {}₺.".format(info[0]))

##########################################################################################

def merchant_linear(array):
  maxDiff = (0, len(array)-1, len(array)-1)
  maxElement = array[-1]
  index = len(array)-1
  for i in range(len(array)-2, -1, -1):
    if array[i] > maxElement:
      maxElement = array[i]
      index = i
    else:
      if maxDiff[0] <= (maxElement-array[i]):
        maxDiff = (maxElement-array[i], i, index)
  return maxDiff

def secondQuestionB():
  array = createRandomArray()
  size = len(array)
  if size == 0:
    print("\nNo sufficient number of prices.")
  elif size == 1:
    print("\nBuy on Day0 for {}₺ and sell on Day0 for {}₺.".format(array[0], array[0]))
    print("Your profit is 0₺.")
  else:
    info = merchant_linear(array)
    print("\nBuy on Day{} for {}₺ and sell on Day{} for {}₺.".format(info[1], array[info[1]], info[2], array[info[2]]))
    print("Your profit is {}₺.".format(info[0]))

##########################################################################################

def longest_subarray(array):
  table = [1]*len(array)

  for i in range(1, len(array)):
    if array[i] > array[i-1]:
      table[i] += table[i-1]

  return (max(table), table.index(max(table)))


def thirdQuestion():
  array =  createRandomArray()

  if len(array) == 0:
    print("0")
  else:
    info = longest_subarray(array)
    print("{} --> (the sub-array is ".format(info[0]), end="")
    print(array[info[1]-info[0]+1 : info[1]+1], end="")
    print(")")


##########################################################################################

def createRandomArray():
  array = []
  size = int(input("\nPlease enter array size: "))
  print("Array: ", end="")
  for i in range(size):
    array.append(random.randint(0, 121))
    print(array[i], end=" ")
  print()
  return array

##########################################################################################

def max_path(cost, m, n, path):
  table = [[0 for x in range(n+1)] for x in range(m+1)]
  table[0][0] = cost[0][0]
 
  for j in range(1, n+1):
    table[0][j] = table[0][j-1] + cost[0][j]

  for i in range(1, m+1):
    table[i][0] = table[i-1][0] + cost[i][0]

  for i in range(1, m+1):
    for j in range(1, n+1):
      table[i][j] = max(table[i-1][j], table[i][j-1]) + cost[i][j]

  i = m
  j = n
  while i != 0 or j != 0:
    if i == 0:
      j = j - 1
    elif j == 0:
      i = i - 1
    elif cost[i][j] + table[i-1][j] == table[i][j]:
      i = i-1
    else:
      j = j-1
    path.append([i, j])
  return table[m][n]

def fourthQuestionA():
  n = int(input("\nPlease enter n: "))
  m = int(input("Please enter m: "))
  if n == 0 or m == 0:
    print("Invalid sizes.")
    return
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

  path   = []
  res = max_path(array, m-1, n-1, path)
  print("\n\nRoute: ", end="")
  for i in range(len(path)-1, -1, -1):
    print("A{}B{} -> ".format(path[i][0]+1, path[i][1]+1), end="")
  print("A{}B{}".format(m, n))
  print("Points: ", end="")
  for i in range(len(path)-1, -1, -1):
    print("{} + ".format(array[path[i][0]][path[i][1]]), end="")
  print("{} = {}".format(array[m-1][n-1], res))



##########################################################################################

def greedy_map(array, n, m, path):
  i = 0
  j = 0
  total = array[0][0]
  path.append([0, 0])
  while i != m or j != n:
    if i == m:
      j += 1
    elif j == n:
      i += 1
    elif array[i+1][j] <= array[i][j+1]:
      j += 1
    elif array[i+1][j] > array[i][j+1]:
      i += 1
    total += array[i][j]
    path.append([i, j])
  return total

def fourthQuestionB():
  n = int(input("\nPlease enter n: "))
  m = int(input("Please enter m: "))
  if n == 0 or m == 0:
    print("Invalid sizes.")
    return
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
  res = greedy_map(array, n-1, m-1, path)
  print("\n\nRoute: ", end="")
  for i in range(len(path)-1):
    print("A{}B{} -> ".format(path[i][0]+1, path[i][1]+1), end="")
  print("A{}B{}".format(m, n))
  print("Points: ", end="")
  for i in range(len(path)-1):
    print("{} + ".format(array[path[i][0]][path[i][1]]), end="")
  print("{} = {}".format(array[m-1][n-1], res))


##########################################################################################

userInput = int(input("\nHello there! How can I help you, please choose:\n1 - Longest Common Substring\n2 - Divide & Conquer Merchant Problem\n3 - Linear Merchant Problem\n4 - Longest Increasing Subarray\n5 - 2D Map Game Dynamic Programming\n6 - 2D Map Game Greedy Algorithm\nEnter: "))
if (userInput == 1):
  firstQuestion()
elif (userInput == 2):
  secondQuestionA()
elif (userInput == 3):
  secondQuestionB()
elif (userInput == 4):
  thirdQuestion()
elif (userInput == 5):
  fourthQuestionA()
elif (userInput == 6):
  fourthQuestionB()

print("\nSO LONG!")
