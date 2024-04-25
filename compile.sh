#!/bin/csh -f

clear
#source /home/skofl/sklib_gcc4.8.5/cshenv_gcc4.8.5_skofl_16c+atmpd_16c
# source /usr/local/sklib_gcc8/skofl_23a/env.csh
# source /usr/local/sklib_gcc8/atmpd_23a/env.csh
#env | grep ROOT
make clean
make
# cd build
# rm -rf *
# cmake ..
# cd -