#!/usr/bin/env python
# -*- coding: utf-8 -*-
# vi:ts=4 sw=4 et

def read_single_integer():
    return int(raw_input().strip())
def read_integers():
    return [int(x) for x in raw_input().split()]

while True:
    n = read_single_integer()

    if n == 0:
        break
    if not 1 <= n <= 98:
        print "ERRO: n (%d) fora do intervalo!" % (n,)

    arestas = 0

    for i in xrange(n):
        a, b = read_integers()
        if not (
            3 <= a <= 100
            and
            1 <= b <= 1000
        ):
            print "Erro no teste: a ou b fora do intervalo! (a=%d, b=%d)" % (a,b)

        arestas += a*b

    if (arestas % 2) == 1:
        print "Erro no teste: número ímpar de arestas (%d)" % (arestas, )

    print arestas // 2
