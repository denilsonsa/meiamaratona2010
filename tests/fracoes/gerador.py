#!/usr/bin/env python
# -*- coding: utf-8 -*-
# vi:ts=4 sw=4 et

import random
import sys


# Limite do problema
MAX_N = 10000  # não tem limite na descrição
MAX_INT = 100


def generate1(output_file, n):
    """Gerador puramente aleatório, gera uma quantidade muito pequena de SIM."""
    output_file.write("%d\n" % (n,))
    for i in xrange(n):
        output_file.write("%d %d %d %d\n" % tuple(random.randint(1,MAX_INT) for x in xrange(4)))


def generate2(output_file, n):
    """Gerador de 75% NAO e 25% SIM."""
    output_file.write("%d\n" % (n,))
    for i in xrange(n):
        a = random.randint(1, MAX_INT)
        b = random.randint(1, MAX_INT)
        if max(a,b) > MAX_INT/2:
            c = random.randint(1, MAX_INT)
            d = random.randint(1, MAX_INT)
        else:
            fator = int(MAX_INT/max(a,b))
            fator = random.randint(1, fator)
            c = a*fator
            d = b*fator
        output_file.write("%d %d %d %d\n" % (a,b,c,d))


def main():
    if len(sys.argv) == 2:
        n = int(sys.argv[1])
    else:
        n = random.randrange(10, MAX_N)

    generate2(sys.stdout, n)


if __name__ == '__main__':
    main()
