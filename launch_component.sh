#!/bin/bash

ENV_PATH='env LD_LIBRARY_PATH=./libLogFilters/Debug/:./libRabbitmq/Debug:./rabbitmq-c/rabbitmq-c/build/librabbitmq/'

order=$1
name=$2
args=$3

(xterm -hold -e "echo 'STEP ${order}';${ENV_PATH} ${name}/Debug/${name} ${args}")&
pid=$!

