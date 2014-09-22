#! /bin/bash

set -e

TOOLSPATH=$(dirname $0)

export LD_LIBRARY_PATH="tools/pawnc"

pushd $TOOLSPATH/.. > /dev/null

tools/pawnc/pawncc gamemodes/roleplay.pwn -i./pawno/include -\; -\( -\Z

popd > /dev/null
