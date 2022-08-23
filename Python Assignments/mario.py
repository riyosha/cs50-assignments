# TODO
try:
    height = int(input("Height: "))
    while height < 1 or height > 8:
        height = int(input("Height: "))
except ValueError:
    height = int(input("Height: "))

for i in range(1, height+1):
    print(" " * (height - i), end = "")
    print("#" * i, end = "")
    print("  ", end = "")
    print("#" * i)
