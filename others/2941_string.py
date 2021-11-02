words=['c=', 'c-', 'dz=', 'd-', 'lj', 'nj', 's=', 'z=']
s=input()
for i in words:
    s=s.replace(i, 'a')
print(len(s))