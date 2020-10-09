import socket #importa modulo socket
import concurrent.futures as cf
import os
 
TCP_IP = '' # endereço IP do servidor 
TCP_PORTA = 31843       # porta disponibilizada pelo servidor
TAMANHO_BUFFER = 1024     # definição do tamanho do buffer
 
# Criação de socket TCP
# SOCK_STREAM, indica que será TCP.
servidor = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# IP e porta que o servidor deve aguardar a conexão
servidor.bind((TCP_IP, TCP_PORTA))

#Define o limite de conexões. 
servidor.listen(1)

# Aceita conexão 
print('Conexão estabelecida')
conn, addr = servidor.accept()
print ('Endereço conectado:', addr)

sPrograma = 'ON'
aStatus = ['rec','esc']

def connect(status):
    while 1:
        global sPrograma
        if (status == 'esc'):
            if (sPrograma == 'OFF'):
                break
            else:
                data = conn.recv(TAMANHO_BUFFER)
                print ("Cliente:", data.decode('utf-8'))
                
        elif (status == 'rec'):
            if (sPrograma == 'OFF'):
                break
            else:
                MENSAGEM = input("Servidor: ")
                if (MENSAGEM == 'QUIT'):
                    conn.send(MENSAGEM.encode('UTF-8'))
                    servidor.close()
                    sPrograma = 'OFF'
                    break
                
                conn.send(MENSAGEM.encode('UTF-8'))  # envia string
            
        else:
            print('Algo deu errado')
            break
        
with cf.ThreadPoolExecutor() as executor:
    executor.map(connect,aStatus)
