def ASCII(arr):
    res = ""
    for x in arr:
        res += chr(x)
    return res

a = [66, 97, 114, 116, 104, 95, 114, 104, 121, 116, 104, 109, 105, 99, 95, 103, 117, 115, 104, 105, 101, 115, 116] 
print(ASCII(a))
