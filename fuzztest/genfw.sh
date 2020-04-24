#!/bin/bash

cd ../fw
sdcc rsa_only.c
# sdcc rsa_only.c rsa.rel

cd ..
python3 scripts/gen_text.py fw/rsa_only.ihx rom/rsa_only.dat
