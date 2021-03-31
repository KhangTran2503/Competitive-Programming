import base64


def base64_encode(data):
    encodedBytes = base64.b64encode(data.encode("utf-8"))   
    return str(encodedBytes, "utf-8")

def find_key():
    for i in range(128):
        for j in range(128):
            for k in range(128):
                s = chr(i) + chr(j) + chr(k)
                t = base64_encode(s)
                if t[0:3] == s: return s

ans = find_key()
while len(ans) < 50:
    ans = base64_encode(ans)[0:len(ans) + 1]

print(ans)


