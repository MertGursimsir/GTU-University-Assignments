array = [1, 1,1,2,2, 3, 4, 5, -25] #ab
n = 1
size = len(array)

if n<0:
  print("invalid number")
  quit()

frequency_dict = {}

for i in range(0, size):
  if frequency_dict.get(array[i]):
    frequency_dict[array[i]] = frequency_dict[array[i]] + 1
  else:
    frequency_dict[array[i]] = 1

  if n == 0 and frequency_dict[array[i]] > 1:
    print("pair: ({}, {})".format(array[i], array[i]))

if (n != 0):
  for i in range(0, size):
    if(frequency_dict.get(n+array[i])):
      print("pair: ({}, {})".format(array[i], n+array[i]))