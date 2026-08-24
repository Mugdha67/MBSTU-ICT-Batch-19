import ipaddress


def calculate_subnet():
    try:
        ip_input = input("Enter IP Address (e.g., 192.168.1.10): ")
        prefix = int(input("Enter CIDR Prefix (e.g., 24): "))

        network = ipaddress.IPv4Network(f"{ip_input}/{prefix}", strict=False)

        total_addresses = network.num_addresses
        host_bits = 32 - prefix
        subnet_bits = prefix

        print("\n" + "=" * 50)
        print(f"{'SUBNET RESULTS (Python)':^50}")
        print("=" * 50)

        print(f"IP Address:        {ip_input}/{prefix}")
        print(f"Network ID:        {network.network_address}")
        print(f"Subnet Mask:       {network.netmask}")
        print(f"Broadcast ID:      {network.broadcast_address}")

        # Block size calculation
        last_octet_mask = int(str(network.netmask).split('.')[-1])
        block_size = 256 - last_octet_mask if last_octet_mask != 0 else 256
        print(f"Block Size:        {block_size}")

        print("-" * 50)

        # Usable IP logic (handles /31, /32 properly)
        if prefix < 31:
            first_usable = network.network_address + 1
            last_usable = network.broadcast_address - 1
            usable_hosts = total_addresses - 2
        else:
            first_usable = "N/A"
            last_usable = "N/A"
            usable_hosts = 0

        print(f"First Usable IP:   {first_usable}")
        print(f"Last Usable IP:    {last_usable}")
        print(f"Total Usable Hosts:{usable_hosts}")

        print("-" * 50)

        print(f"Subnet Bits:       {subnet_bits}")
        print(f"Host Bits:         {host_bits}")

        print("-" * 50)

        # Binary representations (Lab Report ready)
        print(
            f"Binary IP Address: {'.'.join(format(int(x), '08b') for x in ip_input.split('.'))}"
        )
        print(
            f"Binary Network ID: {'.'.join(format(int(x), '08b') for x in str(network.network_address).split('.'))}"
        )
        print(
            f"Binary Mask:       {'.'.join(format(int(x), '08b') for x in str(network.netmask).split('.'))}"
        )

        print("=" * 50 + "\n")

    except ValueError as e:
        print(f"Error: {e}")


if __name__ == "__main__":
    calculate_subnet()
