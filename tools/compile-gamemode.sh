#! /bin/bash

set -e

TOOLSPATH=$(dirname $0)

export LD_LIBRARY_PATH="../tools/pawnc:$LD_LIBRARY_PATH"

pushd $TOOLSPATH/../gamemodes > /dev/null

../tools/pawnc/pawncc roleplay.pwn -i./../pawno/include -\; -\( -\Z

popd > /dev/null
