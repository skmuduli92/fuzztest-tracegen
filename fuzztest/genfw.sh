#!/bin/bash

cd ../fw
sdcc aes_test.c
# sdcc rsa_only.c rsa.rel

cd ..
python3 scripts/gen_text.py fw/aes_test.ihx rom/aes_test.dat
