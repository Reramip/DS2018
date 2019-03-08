import random

with open("qwq.txt",mode='w') as f:
    for i in range(233333):
        rand=random.randint(0,25)
        print(chr(rand+ord('a')),end='',file=f)
