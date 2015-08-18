#!/bin/bash

YBPI=2.0.0

PROJECT_ROOT=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
SRC_HOST=${PROJECT_ROOT}/source
SRC_GUEST=/home/user/src

VOLUMES="--volumes-from target-workspace -v ${SRC_HOST}:${SRC_GUEST}:ro"
CONTAINER="ybpi-sdk:${YBPI}"

