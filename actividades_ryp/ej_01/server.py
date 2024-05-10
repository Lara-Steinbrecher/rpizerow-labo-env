import socket

HOST = ''                 # Symbolic name meaning all available interfaces
PORT = 50007              # Arbitrary non-privileged port

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    # Ata el socket a una direccion IP y puerto especifico 
    s.bind((HOST, PORT))
    # Acepta 1 sola conexion
    s.listen(1)

    # Acepta una conexion, devuelve socket que representa al cliente
    # Y la direccion del cliente
    # Hasta que no se conecte nadie el programa queda trabado aca
    client, addr = s.accept()
    with client:
        print('Connected by', addr)
        while True:
            # Recibio data
            data = client.recv(1024)
            # Devuelvo data
            client.sendall(data)
