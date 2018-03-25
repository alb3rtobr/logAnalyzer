#!/usr/bin/python
import json,subprocess,sys,os,signal

def ctrl_c_handler(signal, frame):
    sys.exit(0)

CONFIG_FILE_NAME = './config.json'
ENV_PATH = 'env LD_LIBRARY_PATH=./libLogFilters/Debug/:./libRabbitmq/Debug:./rabbitmq-c/rabbitmq-c/build/librabbitmq/'

running_procs=[]

signal.signal(signal.SIGINT, ctrl_c_handler)
with open(CONFIG_FILE_NAME, 'r') as config_file:
    PROCESSES = json.load(config_file)['config']

for process in PROCESSES:
    cmd = './launch_component.sh'
    proc = subprocess.Popen([cmd,process['order'],process['name'],' '.join(process['args'])])
    running_procs.append(proc)

print ('Press ctrl + c to kill.')

while True :
    pass
