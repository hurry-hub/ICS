#it's a test
car = input("What kind of car do you want to rent")
print("Let me see if I ca find a" + car)

people = input("How many men go to dinner")
people = int(people)
if people > 8:
    print("There is no table available")
else:
    print("Welcome")

num = input("Please input a number")
num = int(num)
if num % 10 == 0:
    print("Yes")
else:
    print("No")
