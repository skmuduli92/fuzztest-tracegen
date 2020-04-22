#!/bin/bash

cd ../fw
sdcc rsa_test.c
# sdcc rsa_test.c rsa.rel

cd ..
python3 scripts/gen_text.py fw/rsa_test.ihx rom/rsa_test.dat
