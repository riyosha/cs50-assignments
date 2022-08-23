# TODO

import cs50

def main():

    text = cs50.get_string("Text: ")
    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)

    grade = round(0.0588 * 100*letters/words - 0.296 * 100*sentences/words - 15.8)

    print(grade)
    print(letters)
    print(words)
    print(sentences)

    if grade < 1:
        print("Before Grade 1")
    elif grade > 16:
        print("Grade 16+")
    else:
        print("Grade " + str(grade))

def count_letters(txt):

    letter_count = 0
    for i in range (len(txt)):
        if txt[i].isalpha():
            letter_count += 1

    return letter_count

def count_words(txt):

    word_count = 1

    for i in range(len(txt)):
        if txt[i].isspace():
            word_count+=1

    return word_count

def count_sentences(txt):

    sentence_count = 0

    for i in range(len(txt)):
        if txt[i] == "." or txt[i] == "?" or txt[i] == "!":
            sentence_count += 1
    return sentence_count

main()
