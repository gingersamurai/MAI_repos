import random

cnt = 10
for _ in range(cnt):
    f = open("input.txt", "a");
    gl = 'eyuioa';
    sogl = 'qwrtpsdfghklzxcvbnm';

    # surname
    len = random.randint(2, 4) * 2 + 1
    for i in range(len):
        if i % 2 != 0:
            print(random.choice(gl), end="")
        else:
            print(random.choice(sogl), end="")
    print(end=" ")

    #initials
    print(
        random.choice(gl) + "." +  
        random.choice(gl) + ".",
        end=" "
        )

    #count of things
    print(random.randint(1, 10), end=" ")

    #total weight
    print(random.randint(1, 100), end=" ")

    #destination
    print(   
        random.choice(
            [
            "Moscow", "Kiev", 
            "Stambul", "Tokyo", 
            "NewYork", "Torroto"
            ]
        ),
        end=" "
        
    )

    #departure time
    print(
        random.randint(0,1),
        random.randint(0,9), ":",
        random.randint(0,5),
        random.randint(0,9),
        sep="", end=" "

    )

    #count of transfers
    print(random.randint(0, 9), end=" ")

    #child data
    print(random.choice(["have", "havent"]))
    f.close()
