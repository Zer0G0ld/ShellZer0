import subprocess
import threading
import time
import os
from platformSys import get_operating_system

# Criei esse arquivo para guardar os parâmetros do comando 'ps'
# como o comando 'ps aux' ou 'ps -U username'

system = get_operating_system
windows = system == 'Windows'
linux = system == 'Linux'
darwin = system == 'Darwin'

def ps_help():
    try:              
        if system == Windows:
            PSHelper = os.system('tasklist /?')
            print(PSHelper)
        elif system == 'Linux':
            PSHelper = os.system('ps --help')
            print(PSHelper)
        elif system == 'Darwin':
            PSHelper = os.system('man ps')
    except Exception as error:
        print('Erro ao mostra no terminal a ajuda do comando ps' + str(error))

def ps_aux():
    try:
        