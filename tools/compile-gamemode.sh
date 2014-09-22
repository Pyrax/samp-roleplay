#! /bin/bash

set -e

TOOLSPATH=$(dirname $0)

export LD_LIBRARY_PATH="tools/pawnc:$LD_LIBRARY_PATH"

pushd $TOOLSPATH/.. > /dev/null

sudo tools/pawnc/pawncc gamemodes/roleplay.pwn -i./pawno/include -\; -\( -\Z

popd > /dev/null
