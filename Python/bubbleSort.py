def bubbleSort(list):

    for ordenation in range(len(list)-1,0,-1):
        for bs in range(ordenation):
            if list[bs]>list[bs+1]:
                temp = list[bs]
                list[bs] = list[bs+1]
                list[bs+1] = temp


list = [20,12,33,57,46,8,21,28]
bubbleSort(list)
print(list)
