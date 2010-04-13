#!/usr/bin/env python
# -*- coding: utf-8 -*-
# vi:ts=4 sw=4 et

#
#             pizza   ..--''\
#          da   ..--''     \ \ 
#    raio ..--''            | |
#   ..--'') 22.5 graus      |  |
#  -----------------------------
#        diametro do prato
#
# diametro * cos 22.5 >= raio da pizza
#

import math

def fatias_generator(pizzas):
    for raio in pizzas:
        for i in xrange(8):
            yield raio

cosseno = math.cos(math.pi/8)

while True:
    m, n = [int(x) for x in raw_input().split()]
    if m == n == 0:
        break

    # m -> pizzas
    # n -> pratos
    if not (
        1 <= m <= 1000000
        and
        1 <= n <= 1000000
    ):
        print "Erro no teste: m ou n fora do intervalo! (m=%d, n=%d)" % (m,n)

    pizzas = [int(x) for x in raw_input().split()]
    pratos = [int(x) for x in raw_input().split()]
    if m != len(pizzas):
        print "Erro no teste: m=%d, mas ha %d pizzas!" % (m, len(pizzas))
    if n != len(pratos):
        print "Erro no teste: n=%d, mas ha %d pratos!" % (n, len(pratos))

    pizzas.sort()
    pratos.sort()

    servidos = 0
    fatias = fatias_generator(pizzas)
    for p in pratos:
        diam_cos = 2 * p * cosseno
        # Este código está errado. Ele joga fora fatias sempre
        # que um prato é descartado.
        for f in fatias:
            if diam_cos >= f:
                servidos += 1
                break  # próximo prato!
        else: # acabaram as pizzas :(
            break

    print servidos
