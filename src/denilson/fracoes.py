#!/usr/bin/env python
# -*- coding: utf-8 -*-
# vi:ts=4 sw=4 et

n = int(raw_input())
for teste in xrange(n):
    nums = [int(x) for x in raw_input().split()]
    if len(nums) != 4:
        print "Erro no teste %d: foram lidos %d numeros!" % (teste, len(nums))

    for i in nums:
        if not 0 < i <= 100:
            print "Erro no teste %d: numero %d fora do intervalo!" % (teste, i)

    a,b,c,d = nums
    if a*d == b*c:
        print "SIM"
    else:
        print "NAO"
