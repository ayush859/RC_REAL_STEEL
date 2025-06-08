import socket
import threading

# Define server address and port
SERVER_IP = '192.168.4.1'
SERVER_PORT = 5005

client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

def send_command(command):
    try:
        client_socket.sendto(command.encode(), (SERVER_IP, SERVER_PORT))
        print(f"Sent command: {command}")
    except Exception as e:
        print(f"Error sending command: {e}")

def get_user_input():
    print("Control Commands:")
    print("  start       - Start the motor")
    print("  stop        - Stop the motor")
    print("  left        - Turn left")
    print("  right       - Turn right")
    print("  speedup     - Increase speed")
    print("  speeddown   - Decrease speed")
    print("  exit        - Exit the program")
    print("\nEnter command:")

    while True:
        command = input("> ").strip().lower()
        if command == 'exit':
            print("Exiting...")
            break
        elif command in ['start', 'stop', 'left', 'right', 'speedup', 'speeddown']:
            send_command(command)
        else:
            print("Invalid command. Please try again.")

if __name__ == "__main__":
    get_user_input()
