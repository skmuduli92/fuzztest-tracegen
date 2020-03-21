#!/bin/bash

# setting up google-test framework
sudo apt-get install googletest libpthread-workqueue0
cd /usr/src/googletest
sudo cmake .
sudo make
sudo make install

# installing boost libraries for boost::spirit::x3 parser
sudo apt-get install libboost-all-dev

