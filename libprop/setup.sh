#!/bin/bash

sudo apt-get install googletest libpthread-workqueue0
cd /usr/src/googletest
sudo cmake .
sudo make
sudo make install
