import csv

filename = "packets.csv"
protocol_input = input("Enter protocol (e.g. TCP, UDP, HTTP): ").upper()

count = 0

with open(filename, 'r') as file:
    reader = csv.DictReader(file) 
    for row in reader:
        protocol = row['Protocol'].upper() if 'Protocol' in row else ''
        if protocol_input in protocol:  # <-- check if input is in protocol
            count += 1

print(f"Total packets using protocol {protocol_input}: {count}")
