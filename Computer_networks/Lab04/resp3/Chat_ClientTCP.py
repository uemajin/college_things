import socket #importa modulo socket
import concurrent.futures as cf

TCP_IP = 'localhost' # endereço IP do servidor 
TCP_PORTA = 31843      # porta disponibilizada pelo servidor
TAMANHO_BUFFER = 1024

# Criação de socket TCP do cliente
cliente = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# Conecta ao servidor em IP e porta especifica 
cliente.connect((TCP_IP, TCP_PORTA))

sPrograma = 'ON'
aStatus = ['rec','esc']

def connect(status):
    while 1:
        global sPrograma
        if (status == 'rec'):
            if (sPrograma == 'OFF'):
                break
            else:
                data, addr = cliente.recvfrom(1024)
                if (data.decode('utf-8') == 'QUIT'):
                    print('Servidor fechado =(')
                    cliente.close()
                    sPrograma = 'OFF'
                    break
                print ("Servidor:", data.decode('utf-8'))
            
        elif (status == 'esc'):
            if (sPrograma == 'OFF'):
                break
            else:
                 MENSAGEM  = input("Cliente: ")
                 if (MENSAGEM == 'QUIT'):
                    cliente.send('Cliente saiu do Chat =('.encode('UTF-8'))
                    # fecha conexão com servidor
                    cliente.close()
                    sPrograma = 'OFF'
                    break
                 cliente.send(MENSAGEM.encode('UTF-8'))
        
        else:
            print('Algo deu errado')
            break

with cf.ThreadPoolExecutor() as executor:
    executor.map(connect,aStatus)
