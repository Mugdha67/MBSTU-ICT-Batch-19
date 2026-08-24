// script.js
let screen = document.getElementById('screen');

function appendToScreen(value) {
    screen.innerText += value;
}

function clearScreen() {
    screen.innerText = '';
}

function deleteLast() {
    screen.innerText = screen.innerText.slice(0, -1);
}

function calculate() {
    try {
        // eval handles the string math (e.g., "7+3*2")
        screen.innerText = eval(screen.innerText);
    } catch {
        screen.innerText = "Error";
        setTimeout(clearScreen, 1500);
    }
}