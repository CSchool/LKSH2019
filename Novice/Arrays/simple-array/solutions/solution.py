
number_of_elements, element_to_sum = map(int, input().split())

array = list(map(int, input().split()))

[print(i + element_to_sum) for i in array]

