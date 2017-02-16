# -*- coding: utf-8 -*-
"""
Created on Thu Feb 16 07:26:36 2017

@author: Gary
"""

from subprocess import PIPE, run

'''
The purpose of this code is to approximate the value of Pi.
'''

R = run(args = ["Simple Monte Carlo Integration.exe"], stdout = PIPE)

print(R.stdout.decode('UTF-8'))
