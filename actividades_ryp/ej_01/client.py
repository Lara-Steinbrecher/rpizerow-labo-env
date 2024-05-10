import socket

# HOST = "" 
# Solo funciona en este caso donde el server y cliente estan en el mismo dispositivo
# En otro caso se debe escribir el host no buscarlo con funciones
HOST = socket.gethostbyname(socket.gethostname())    # The remote host
PORT = 50007              # The same port as used by the server

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    # Intento conectarme al servidor
    s.connect((HOST, PORT))
    s.sendall(b'Hello, world')
    data = s.recv(1024)

print('Received', repr(data))