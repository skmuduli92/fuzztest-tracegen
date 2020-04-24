#!/bin/bash

cd ../fw
sdcc memwr.c
# sdcc rsa_only.c rsa.rel

cd ..
python3 scripts/gen_text.py fw/memwr.ihx rom/memwr.dat
