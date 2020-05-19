#!/bin/bash

cd ../fw
sdcc exp_test.c

cd ..
python3 scripts/gen_text.py fw/exp_test.ihx rom/exp_test.dat
