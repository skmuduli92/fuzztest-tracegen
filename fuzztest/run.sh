#! /bin/bash
if [[ $# -ne 1 ]]; then
    echo 'Syntax error.'
else 
    echo make && afl-fuzz -i afl-in/$1 -o afl-out/$1 -t 20000 -- ./$1
fi

