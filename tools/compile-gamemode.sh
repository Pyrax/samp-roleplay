#! /bin/bash

set -e

TOOLSPATH=$(dirname $0)

export LD_LIBRARY_PATH="../tools/pawn:$LD_LIBRARY_PATH"

pushd $TOOLSPATH/../gamemodes > /dev/null

../tools/pawnc/pawncc roleplay.pwn -i../pawno/include -\; -\(

popd > /dev/null