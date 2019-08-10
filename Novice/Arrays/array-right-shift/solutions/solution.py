number_of_elements = int(input())
array = list(map(int, input().split()))
shift_index = int(input())

[print(i) for i in (array[-shift_index:] + array[:-shift_index])]
