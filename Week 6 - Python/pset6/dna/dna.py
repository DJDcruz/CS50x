from sys import argv
import csv


# If not enough command-line arguments, Error occurs
if len(argv) != 3:
    print("Error. Usage .python dna.py <file> <sequence>")

csv_name = argv[1]


def match(strs, dna, i):
    # Function to match person with the sequence of dna   
    for str in strs:
        if dna[str] != int(i[str]):
            return False
        return True

        
def max_str_repeat(str, dna):
    # Function to find particular strand in the sequence and count the number of repetitions 
    ctr = 0
    while str*(ctr + 1) in dna:
        ctr += 1
    return ctr
    

# Opening the csv file and reading to the memory
with open(csv_name) as csvf:
    creader = csv.DictReader(csvf)
    
    sequence_name = argv[2]
    with open(sequence_name) as seq:
        sreader = seq.read()
        
    strs = creader.fieldnames[1:]
    
    dna = {}
    
    for str in strs:
        dna[str] = max_str_repeat(str, sreader)
    
    # Traversing through the database trying to find a match for the dna sequence
    for i in creader:
        if match(strs, dna, i):
            print(i["name"])
            quit()
    
    # If seq is not found, print no match
    print("No match")
    