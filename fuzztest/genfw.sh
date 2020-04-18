#!/bin/bash

cd ../fw
sdcc sha_test.c
cd ..
python3 scripts/gen_text.py fw/aes_test.ihx rom/sha_test.dat
