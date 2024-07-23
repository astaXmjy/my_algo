def deeksha_solution(arr):
    import math

    max_ele = 0
    for i in range(len(arr)):
        max_ele = max(max_ele, arr[i])
        arr[i] = math.gcd(max_ele, arr[i])

    arr.sort()
    groups = []
    for i in range(len(arr) // 2):
        groups.append([arr[i], arr[len(arr) - 1 - i]])

    deeksha_req_arr = []

    for i in range(len(groups)):
        deeksha_req_arr.append(math.gcd(groups[i][0], groups[i][1]))

    return deeksha_req_arr


arr = [1, 14, 11, 19]

deeksha_time_traveller = deeksha_solution(
    arr
)  # idon't pass n instead of these i use len function kido 😁

print(deeksha_time_traveller)

# def greeting(msg):
#     print(f'le tera msg {msg}')

# greeting("you are amazing lol😀")


