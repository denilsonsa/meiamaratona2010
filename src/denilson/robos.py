#!/usr/bin/env python
# -*- coding: utf-8 -*-
# vi:ts=4 sw=4 et

def read_integers():
    return [int(x) for x in raw_input().split()]


def floodfill(mapa, rows, cols):
    # tesouros = 0

    # Workaround for lack of nonlocal
    # http://stackoverflow.com/questions/141642/what-limitations-have-closures-in-python-compared-to-language-x-closures/141710#141710
    tesouros = [ 0 ]  

    x = y = -1
    for i in xrange(rows):
        for j in xrange(cols):
            if mapa[i][j] == 'I':
                if x != -1 or y != -1:
                    raise RuntimeError("Duas posicoes iniciais no labirinto")
                else:
                    x,y = i,j

    def visit(x,y):
        min_y = max_y = y

        while mapa[x][min_y] in '.$':
            min_y -= 1
        min_y += 1

        while mapa[x][max_y] in '.$':
            max_y += 1
        max_y -= 1

        for i in xrange(min_y, max_y+1):
            mapa[x][i] = '#'

        for i in xrange(min_y, max_y+1):
            for nx, ny in (
                (x-1, i+0),
                (x+1, i+0),
            ):
                if mapa[nx][ny] in '.$':
                    if mapa[nx][ny] == '$':
                        tesouros[0] += 1
                    visit(nx,ny)


    mapa[x][y] = '.'
    visit(x,y)
    return tesouros[0]


while True:
    m, n = read_integers()

    if m == 0 and n == 0:
        break
    if not (
        3 <= m <= 1000  # linhas
        and
        3 <= n <= 1000  # colunas
    ):
        print "ERRO: m,n (%d,%d) fora do intervalo!" % (m,n)

    mapa = [
        list(raw_input().strip())
        for i in xrange(m)
    ]

    if any(len(linha) != n for linha in mapa):
        print "ERRO: Linha com largura diferente de %d" % (n,)

    if (
        any(c != '#' for c in mapa[0]) or
        any(c != '#' for c in mapa[-1]) or
        any(c != '#' for c in (linha[0] for linha in mapa[1:-2]) ) or
        any(c != '#' for c in (linha[-1] for linha in mapa[1:-2]) )
    ):
        print "ERRO: Labirinto nao eh contornado por '#'"

    total = sum( linha.count('$') for linha in mapa )
    alcancaveis = floodfill(mapa, m, n)

    print "%d/%d" % (alcancaveis, total)
