def RLE(string, show_one=True):

    compressed = ""
    count = 1
    letter = ""
    
    if not string:
        return False

    for i in string:
        if letter == "":
            letter = i
        elif letter == i:
            count += 1
        else:
            compressed += str(count) + letter
            letter = i
            count = 1

    compressed += str(count) + letter

    if not show_one:
        compressed = compressed.replace("1", "")

    return compressed


    

if __name__ == "__main__":
    string = input("Enter a string to compress: ")
    show_one = input("Show counts of 1? (y/n): ").lower() == "y"
    compressed = RLE(string, show_one)

    if not compressed:
        print("Invalid input")
    else:
        print("Compressed string:", compressed)