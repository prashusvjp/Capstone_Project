from bluetooth import *
import subprocess, psutil
import RPi.GPIO as io

autoPilotState=False

io.setmode(io.BCM)
pins=[19,13,6,5]
for i in pins:
    io.setup(i,io.OUT)


autoPilotProcess=None
pAutoPilotProcess=None

server_sock=BluetoothSocket( RFCOMM )
server_sock.bind(("",PORT_ANY))
server_sock.listen(1)

connection=False
port = server_sock.getsockname()[1]

uuid = "94f39d29-7d6d-437d-973b-fba39e49d4ee"

advertise_service( server_sock, "RCpiServer",
                   service_id = uuid,
                   service_classes = [ uuid, SERIAL_PORT_CLASS ],
                   profiles = [ SERIAL_PORT_PROFILE ] )
client_info=None
client_socket=None

while True:
    if(connection == False):
        print("Waiting for connection on RFCOMM channel %d" % port)
        client_socket,client_info=server_sock.accept()
        connection = True
        print("Accepted connection from ", client_info)
    else :
        data = client_socket.recv(1024)
        data=int.from_bytes(data,"big")
        print(data)
        if data==11:
            autoPilotState=not autoPilotState          
            if autoPilotState:
                if autoPilotProcess==None:
                    autoPilotProcess=subprocess.Popen("./Histogram")
                    pAutoPilotProcess= psutil.Process(autoPilotProcess)
                else:
                    pAutoPilotProcess.resume()
            else:
                pAutoPilotProcess.suspend()
        elif data==15:
            autoPilotProcess=False
            pAutoPilotProcess.kill()
        else:
            data=format(data,"b").zfill(4)
            print(data)
            for i in range(len(data)):
                io.output(pins[i],int(data[i]))