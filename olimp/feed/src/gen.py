import os, shutil
from random import *
import random
seed("grievous")

class SandwichesTestGen:
    def __init__(self):
        self.test_number = 0

    def generate_random_array(self, n, maxvalue):
        a = []
        for i in range(n):
            a.append(random.randint(1, maxvalue))
        return a

    def generate_samples(self):
        self.print_test(3, 4, [1, 3, 2])
        self.print_test(3, 2, [1, 2, 3])

    def generate_min_tests(self):
        self.print_test(1, 1, [1])
        self.print_test(1, 1, [2])
        self.print_test(1, 2, [2])
        self.print_test(2, 1, [4, 1])
        self.print_test(2, 2, [1, 3])
        self.print_test(2, 2, [3, 1])
        self.print_test(2, 4, [2, 2])
        self.print_test(2, 5, [2, 2])

    def generate_max_tests(self, maxn, maxk, maxvalue):
        a = []
        for i in range(maxn):
            a.append(1)
        self.print_test(maxn, maxk, a)
        self.print_test(maxn, 2 * maxn, a)

        for i in range(5):
            a = self.generate_random_array(maxn, maxvalue)
            self.print_test(maxn, maxk, a)
            self.print_test(maxn, 2 * maxn, a)
        

    def generate_hand_tests(self):
        pass
                                 
    def generate_random_test(self, maxa, maxb, maxc):
        a = random.randint(0, maxa)
        b = random.randint(0, maxb)
        c = random.randint(0, maxc)
        self.print_test(a, b, c)

                             
    def print_test(self, n, k, a):
        self.test_number += 1
        test_name = "../tests/" + "{0:0=2d}".format(self.test_number)
        test_file = open(test_name, "w")
        print(n, k, a, file=test_file)
        test_file.close()

    def generate_all_tests(self):
        #for i in range(15):
        #  self.generate_medium_test()
        self.print_test(0, 0, 1)
        self.print_test(2, 0, 1)
        self.print_test(1, 1, 1)
        self.print_test(0, 0, 0)


        for i in range(10):
          self.generate_random_test(10, 10, 10)
        for i in range(10):
          self.generate_random_test(100, 100, 100)
        for i in range(10):
          self.generate_random_test(1000, 1000, 1000)
        for i in range(3):
          self.generate_random_test(0, 1000, 1000)
        for i in range(3):        
          self.generate_random_test(1000, 0, 1000)
        for i in range(3):        
          self.generate_random_test(1000, 1000, 0)
        self.print_test(1000, 1000, 1000)





if os.path.exists('../tests'):
    shutil.rmtree('../tests', ignore_errors=False, onerror=None)
try:
    os.makedirs('../tests')
except OSError:
    pass

writer = SandwichesTestGen()
writer.generate_all_tests()
