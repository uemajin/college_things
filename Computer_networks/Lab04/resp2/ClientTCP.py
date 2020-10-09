import socket #importa modulo socket

TCP_IP = 'localhost' # endereço IP do servidor 
TCP_PORTA = 31843      # porta disponibilizada pelo servidor
TAMANHO_BUFFER = 1024

# Criação de socket TCP do cliente
cliente = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# Conecta ao servidor em IP e porta especifica 
cliente.connect((TCP_IP, TCP_PORTA))

while 1:

    MENSAGEM  = input("Cliente: ")
    
    if (MENSAGEM == 'QUIT'):
        cliente.send('Cliente saiu do Chat =('.encode('UTF-8'))
        # fecha conexão com servidor
        cliente.close()
        break
    else:
        # envia mensagem para servidor 
        cliente.send(MENSAGEM.encode('UTF-8'))
        
        # recebe dados do servidor 
        data, addr = cliente.recvfrom(1024)
        
        if (data.decode('utf-8') == 'QUIT'):
            print('Servidor fechado =(')
            cliente.close()
            break
            
        print ("Servidor:", data.decode('utf-8'))
