number_of_elements = input()
array = list(map(int, input().split()))
index, number = list(map(int, input().split()))
array.insert(index, number)
[print(i) for i in array]