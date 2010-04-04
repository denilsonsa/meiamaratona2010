#!/usr/bin/env python
# -*- coding: utf-8 -*-
# vi:ts=4 sw=4 et

# Gerador puramente aleatório. Gera uma quantidade muito pequena de "SIM"

import random
import sys

if len(sys.argv) == 2:
    n = int(sys.argv[1])
else:
    n = random.randrange(100, 10000)

print n
for i in xrange(n):
    print "%d %d %d %d" % tuple(random.randint(1,100) for x in xrange(4))
