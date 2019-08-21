import collections

if __name__ == '__main__':
    # 5 cards, 1..13 values
    cards = list(map(int, input().split()))
    cards_counter = collections.Counter(cards)

    # check 5 and 4
    result = cards_counter.most_common(1)[0]

    if result[1] == 5:
        print('Impossible')
        exit(0)
    elif result[1] == 4:
        print('Four of a Kind')
        exit(0)

    # check 3 and 3+2
    first_result = cards_counter.most_common(2)[0]
    second_result = cards_counter.most_common(2)[1]

    if first_result[1] == 3 and second_result[1] != 2:
        print('Three of a Kind')
        exit(0)
    elif first_result[1] == 3 and second_result[1] == 2:
        print('Full House')
        exit(0)

    # check 2 and 2 + 2

    if first_result[1] == 2 and second_result[1] != 2:
        print('One Pair')
        exit(0)
    elif first_result[1] == 2 and second_result[1] == 2:
        print('Two Pairs')
        exit(0)

    # check is straight
    sorted_cards = sorted(cards)
    diff = 0

    for i in range(1, len(sorted_cards)):
        diff += sorted_cards[i] - sorted_cards[i - 1]

    if diff == 4 and len(set(sorted_cards)) == 5:
        print('Straight')
        exit(0)
    else:
        print('Nothing')
        exit(0)
