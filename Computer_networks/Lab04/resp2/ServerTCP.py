import socket #importa modulo socket
 
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
print()
conn, addr = servidor.accept()
print ('Endereço conectado:', addr)
while 1:

    data = conn.recv(TAMANHO_BUFFER)
    if data: 
        print ("Cliente:", data.decode('utf-8'))
        
        MENSAGEM = input("Servidor: ")
        if (MENSAGEM == 'QUIT'):
            conn.send(MENSAGEM.encode('UTF-8'))
            servidor.close()
            break
            
        conn.send(MENSAGEM.encode('UTF-8'))  # envia string

