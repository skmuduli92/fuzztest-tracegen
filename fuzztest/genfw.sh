#!/bin/bash

cd ../fw
sdcc page_table_test.c
cd ..
python3 scripts/gen_text.py fw/page_table_test.ihx rom/page_table_test.dat
