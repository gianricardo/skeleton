#!/bin/bash

PROJECT_ROOT=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
SRC_HOST=${PROJECT_ROOT}/source
SRC_GUEST=/home/user/src

docker run --rm -t --volumes-from host-workspace -v ${SRC_HOST}:${SRC_GUEST}:ro host-gcc cmake ${SRC_GUEST}
docker run --rm -t --volumes-from host-workspace -v ${SRC_HOST}:${SRC_GUEST}:ro host-gcc cmake --build . --target clean
