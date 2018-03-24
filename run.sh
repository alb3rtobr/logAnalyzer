#!/bin/bash

ENV_PATH='env LD_LIBRARY_PATH=./libLogFilters/Debug/:./libRabbitmq/Debug:./rabbitmq-c/rabbitmq-c/build/librabbitmq/'

pids=()
(xterm -hold -e "echo 'STEP 1';${ENV_PATH} logGenerator/Debug/logGenerator 100 brokerLogIdentifier")&
pids[0]=$!

(xterm -hold -e "echo 'STEP 2';${ENV_PATH} Broker/Debug/Broker brokerLogIdentifier logIdentifier")&
pids[1]=$!

(xterm -hold -e "echo 'STEP 3';${ENV_PATH} LogIdentifier/Debug/LogIdentifier logIdentifier AppLogNormalizerBroker SystemLogNormalizerBroker")&
pids[2]=$!

(xterm -hold -e "echo 'STEP 4a';${ENV_PATH} Broker/Debug/Broker SystemLogNormalizerBroker SystemLogNormalizer")&
pids[3]=$!

(xterm -hold -e "echo 'STEP 4b';${ENV_PATH} Broker/Debug/Broker AppLogNormalizerBroker AppLogNormalizer")&
pids[4]=$!

(xterm -hold -e "echo 'STEP 5b';${ENV_PATH} AppLogNormalizer/Debug/AppLogNormalizer AppLogNormalizer WordSeparatorBroker")&
pids[5]=$!

(xterm -hold -e "echo 'STEP 5a';${ENV_PATH} SystemLogNormalizer/Debug/SystemLogNormalizer SystemLogNormalizer WordSeparatorBroker")&
pids[6]=$!

(xterm -hold -e "echo 'STEP 6';${ENV_PATH} Broker/Debug/Broker WordSeparatorBroker WordSeparator")&
pids[7]=$!

(xterm -hold -e "echo 'STEP 7';${ENV_PATH} WordSeparator/Debug/WordSeparator WordSeparator WordFilterBroker")&
pids[8]=$!

(xterm -hold -e "echo 'STEP 8';${ENV_PATH} Broker/Debug/Broker WordFilterBroker WordFilter")&
pids[9]=$!

(xterm -hold -e "echo 'STEP 9';${ENV_PATH} WordFilter/Debug/WordFilter WordFilter StandardRecorderBroker")&
pids[10]=$!

(xterm -hold -e "echo 'STEP 10';${ENV_PATH} Broker/Debug/Broker StandardRecorderBroker StandardRecorder")&
pids[11]=$!

(xterm -hold -e "echo 'STEP 11';${ENV_PATH} StandardRecorder/Debug/StandardRecorder StandardRecorder CriticalRecorderBroker NetworkRecorderBroker UnknownRecorderBroker")&
pids[12]=$!

(xterm -hold -e "echo 'STEP 12a';${ENV_PATH} Broker/Debug/Broker CriticalRecorderBroker CriticalRecorder")&
pids[13]=$!

(xterm -hold -e "echo 'STEP 12b';${ENV_PATH} Broker/Debug/Broker NetworkRecorderBroker NetworkRecorder")&
pids[14]=$!

(xterm -hold -e "echo 'STEP 12c';${ENV_PATH} Broker/Debug/Broker UnknownRecorderBroker UnknownRecorder")&
pids[15]=$!

(xterm -hold -e "echo 'STEP 13a';${ENV_PATH} CriticalRecorder/Debug/CriticalRecorder CriticalRecorder")&
pids[16]=$!

(xterm -hold -e "echo 'STEP 13b';${ENV_PATH} NetworkRecorder/Debug/NetworkRecorder NetworkRecorder")&
pids[17]=$!

(xterm -hold -e "echo 'STEP 13c';${ENV_PATH} UnknownRecorder/Debug/UnknownRecorder UnknownRecorder")&
pids[18]=$!


echo "Press any key to exit."
read something

kill -9 ${pids[0]}
kill -9 ${pids[1]}
kill -9 ${pids[2]}
kill -9 ${pids[3]}
kill -9 ${pids[4]} 
kill -9 ${pids[5]}
kill -9 ${pids[6]}
kill -9 ${pids[7]}
kill -9 ${pids[8]}
kill -9 ${pids[9]}
kill -9 ${pids[10]}
kill -9 ${pids[11]}
kill -9 ${pids[12]}
kill -9 ${pids[13]}
kill -9 ${pids[14]}
kill -9 ${pids[15]}
kill -9 ${pids[16]}
kill -9 ${pids[17]}
kill -9 ${pids[18]}
