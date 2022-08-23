import csv
import sys


def main():

    dna_list = []

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("usage: python dna.py file.csv file.txt")
        return 1

    # TODO: Read database file into a variable

    file = open(sys.argv[1], "r")

    dna_dict = csv.DictReader(file)
    for row in dna_dict:
        dna_list.append(row)

    str_names = list(dna_list[0].keys())
    str_names = str_names[1:]
    #print(str_names)

    # TODO: Read DNA sequence file into a variable

    dna = open(sys.argv[2], "r")
    sequence = str(next(csv.reader(dna)))

    # TODO: Find longest match of each STR in DNA sequence

    sequence_match = {}

    for i in range(len(str_names)):
        lm = longest_match(sequence, str_names[i])
        sequence_match[str_names[i]] = str(lm)


    #print(sequence_match)


    # TODO: Check database for matching profiles


    dna_list_alt = []
    for i in range(len(dna_list)):
        dna_list_alt.append(removekey(dna_list[i], "name"))


    for i in range(len(dna_list)):
        if sequence_match == dna_list_alt[i]:
            print(dna_list[i]["name"])
            return 0
    print("no match\n")
    return



def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run

def removekey(d, key):
    r = dict(d)
    del r[key]
    return r


main()
