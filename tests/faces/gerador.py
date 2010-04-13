#!/usr/bin/env python
# -*- coding: utf-8 -*-
# vi:ts=4 sw=4 et

import random
import sys


# Limites do problema
MAX_CASOS = 10000  # não tem limite na descrição
LIMIT_N = (1, 98)
LIMIT_A = (3, 100)
LIMIT_B = (1, 1000)


def generate_test_case(output_file):
    """Gerador puramente aleatório"""

    n = random.randint(*LIMIT_N)
    faces = [
        [ i, random.randint(*LIMIT_B) ]
        for i in random.sample(xrange(LIMIT_A[0], LIMIT_A[1]+1), n)
    ]
    num_arestas = sum(a*b for a,b in faces)

    if sum(b for a,b in faces) < 4:
        raise RuntimeError("Ferrou")

    # Checagem para número ímpar de arestas
    if (num_arestas % 2) == 1:
        # Fato curioso: o código dentro deste if tem uma probabilidade de
        # aproximadamente 50% de ser executado

        #output_file.write("# fixing!\n")
        # Acha alguma face de tamanho ímpar
        impar = random.choice(filter(lambda i: (i[0]%2) == 1, faces))
        if impar[1] == LIMIT_B[1]:
            impar[1]-=1
        else:
            impar[1]+=1

    # Sanity check...
    num_arestas = sum(a*b for a,b in faces)
    if (num_arestas % 2) == 1:
        raise RuntimeError("Nao conseguiu consertar o impar...")

    output_file.write("%d\n" % (n,))
    for a, b in faces:
        output_file.write("%d %d\n" % (a, b))


def generate_file(output_file, casos):
    for i in xrange(casos):
        generate_test_case(output_file)
    output_file.write("0\n")


def main():
    if len(sys.argv) == 2:
        casos = int(sys.argv[1])
    else:
        casos = random.randrange(10, MAX_CASOS)

    generate_file(sys.stdout, casos)


if __name__ == '__main__':
    main()
