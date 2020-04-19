#!/bin/bash

cd ../fw
sdcc sha_pycomp.c
cd ..
python3 scripts/gen_text.py fw/sha_pycomp.ihx rom/sha_pycomp.dat
