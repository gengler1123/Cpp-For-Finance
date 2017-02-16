# -*- coding: utf-8 -*-
"""
Created on Thu Feb 16 07:26:36 2017

@author: Gary
"""

from subprocess import PIPE, run


R = run(args = ["multiThreading.exe"], stdout = PIPE)

print(R.stdout.decode('UTF-8'))
