#!/bin/sh

kx509
. /cvmfs/dune.opensciencegrid.org/products/dune/setup_dune.sh
export DUNEVERSION=v08_57_00
setup -B dunetpc v08_57_00 -q e19:prof:py2
voms-proxy-init -noregen -rfc -voms dune:/dune/Role=Analysis
