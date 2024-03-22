import csv
import sys

#import os #these 2 lines are used for debugging this program which takes cmd line argument
#sys.argv = [os.path.basename(__file__),"dna/databases/large.csv","dna/sequences/5.txt"]

def main():

    # TODO: Check for command-line usage
    if (len(sys.argv) != 3):
        print("Not valid include database and the sample file")
        sys.exit(0)

    # TODO: Read database file into a variable
    dataset = []
    with open(sys.argv[1],'r') as database:
        reader1 = csv.DictReader(database)
        for row in reader1:
            temp = list(row.keys())[1:]
            for i in temp:
                row[i] = int(row[i])
            dataset.append(row)
    print(dataset)

    # TODO: Read DNA sequence file into a variable
    with open(sys.argv[2],'r') as sample_person:
        sample1 = sample_person.read() #FILE.read(default is -1 which is till EOF)

    # TODO: Find longest match of each STR in DNA sequence
    result= {}
    keys = dataset[0].keys()
    keys1 = list(keys)
    large = keys1[1:]  #Or large = list(dataset[0].keys())[1:]
    for i in large:
        result[i] = longest_match(sample1,i)
    print("result is",result)
    print(len(large))

    # TODO: Check database for matching profiles
    person = "No match"
    for value in dataset:
        match = 0
        for key in result:
            if value[key] != result[key]:
                break
            else:
                match +=1
                person = value["name"]
                print(f"as of now person is: {person}")
        if match == len(result):
            print(person)
            sys.exit(0)
    print("No match") #should not print person here bcoz if there is some temp person got selected he will get printed here not the 'No match' string
    print(f"Not a 10/10 match: {person}")
    return   #return and sys.exit(0) boht mean same thing


    ''' OLD code used when result is stored as list rather than dictionary
    person = "No match"
    flag = 0
    for value in dataset:
        for i in range(len(large)):
            if value[large[i]] != result[i]:
                break
            else:
                person = value["name"]
                print(f"as of now person is: {person}")
                if i == len(large)-1:
                    flag = 1
                    break
        if flag == 1:
            break
    print(person)'''


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


if __name__ == "__main__":
    main()


