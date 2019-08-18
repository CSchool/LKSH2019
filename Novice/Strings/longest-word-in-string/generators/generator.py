import sys

strings = {
    1 : "Hello, world! How are you?",
    2 : "Something??3409403-:. Some text:;'..;''",
    3 : "He went such dare good mr fact. The small own seven saved man age ﻿no offer. Suspicion did mrs nor furniture smallness. Scale whole downs often leave not eat. An expression reasonably cultivated indulgence mr he surrounded instrument. ",
    4 : "6666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666?:"
}

number_of_string = int(sys.argv[1])
print(strings.get(number_of_string))