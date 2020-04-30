#!/bin/bash

cd ../fw
sdcc memwr.c

cd ..
python3 scripts/gen_text.py fw/memwr.ihx rom/memwr.dat
