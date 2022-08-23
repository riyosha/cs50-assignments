# TODO
def main():
    try:
        number = int(input("Number:"))
    except ValueError:
        number = int(input("Number:"))

    i = number
    o = number
    odd_sum = 0
    even_sum = 0

    #even sum
    while i>1:
        i = (i-i%10)/10
        ed = i%10
        split_ed = (2*ed)%10 + (2*ed - (2*ed)%10)/10
        even_sum += split_ed
        i = (i-i%10)/10

    #odd sum
    while o > 1:
        od = o%10
        odd_sum += od
        o = (o-o%10)/10
        o = (o-o%10)/10

    total_sum = even_sum + odd_sum

    if total_sum%10 == 0.0:
        if (len(str(number)) == 13 and first_digits(number) in range(40, 50)):
            print("VISA")
        elif (len(str(number)) == 16):
            if first_digits(number) in range(40, 50):
                print("VISA")
            elif first_digits(number) in range(51, 56, 1):
                print("MASTERCARD")
            else:
                print("INVALID")
        elif (len(str(number)) == 15 and (first_digits(number) == 37 or first_digits(number) == 34)):
            print("AMEX")
        else:
            print("INVALID")
    else:
        print("INVALID")

def first_digits(start):
    while start >= 100:
        start = (start - start%10)/10
    return start

main()