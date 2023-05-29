import sys

def is_word(word, dictionary):
    return word in dictionary

def split_words(string, dictionary):
    n = len(string)
    dp = [0] * (n + 1)
    dp[n] = 1

    split_point = [-1] * (n + 1)

    for i in range(n - 1, -1, -1):
        for j in range(i + 1, n + 1):
            if is_word(string[i:j], dictionary) and dp[j]:
                dp[i] = 1
                split_point[i] = j
                break

    if not dp[0]:
        return None

    words = []
    i = 0
    while i < n:
        j = split_point[i]
        words.append(string[i:j])
        i = j

    return words

with open("diction10k.txt", "r") as f:
    dictionary = set(f.read().split())

lines = sys.stdin.readlines()
phrases = [line.strip() for line in lines[1:]]
phrase_num = int(lines[0])

for i, phrase in enumerate(phrases):
    print("phrase", i + 1)
    print(phrase)
    print()

    words = split_words(phrase, dictionary)
    if words:
        print("output", i + 1)
        print("YES, can split.")
        print(' '.join(words))
    else:
        print("output", i + 1)
        print("NO, cannot split.")
    print()
