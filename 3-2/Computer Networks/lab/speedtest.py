import speedtest

def test_internet_speed():
    print("📡 Checking Internet Speed...\n")

    st = speedtest.Speedtest()

    print("🔍 Finding best server...")
    st.get_best_server()

    print("⬇️ Testing download speed...")
    download_speed = st.download()

    print("⬆️ Testing upload speed...")
    upload_speed = st.upload()

    ping = st.results.ping

    # Convert bits to Mbps
    download_mbps = download_speed / 1_000_000
    upload_mbps = upload_speed / 1_000_000

    print("\n📊 Internet Speed Results")
    print("----------------------------")
    print(f"📥 Download Speed : {download_mbps:.2f} Mbps")
    print(f"📤 Upload Speed   : {upload_mbps:.2f} Mbps")
    print(f"⏱️ Ping           : {ping} ms")
    print("----------------------------")

if __name__ == "__main__":
    test_internet_speed()
