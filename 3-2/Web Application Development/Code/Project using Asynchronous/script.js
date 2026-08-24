function getResult() {
    document.getElementById("status").innerText = "Loading...";
    console.log("Request sent to server");
    setTimeout(() => {
        document.getElementById("status").innerText = "Result loaded successfully!";
        document.getElementById("result").innerText = "Name: Kuldip Saha Mugdha | CGPA: 3.75";
        console.log("Result received from server");
    }, 4000);
}
