let count = 0;
let labelCount = 0; // counts how many times we've reached 10
let clapListening = false;
let audioContext = null;
let analyser = null;
let sourceNode = null;
let mediaStream = null;
let rafId = null;
let lastClapTime = 0;
const CLAP_THRESHOLD = 0.30; // adjust sensitivity (0-1)
const CLAP_COOLDOWN = 350; // ms to avoid double triggers

function increase() {
    count++;
    // When reaching 10, increment label, reset count to 0
    if (count >= 10) {
        labelCount++;
        const labelEl = document.getElementById('label');
        if (labelEl) labelEl.textContent = labelCount;
        count = 0;
    }
    updatecounter();
}
function decrease() {
    if (count > 0) {
        count--;
        updatecounter();
    }
}
function reset() {
    count = 0;
    updatecounter();
}

function resetLabel() {
    labelCount = 0;
    const labelEl = document.getElementById('label');
    if (labelEl) labelEl.textContent = labelCount;
}

function toggleClap() {
    if (clapListening) stopClap();
    else startClap();
}

function startClap() {
    if (!navigator.mediaDevices || !navigator.mediaDevices.getUserMedia) {
        alert('Microphone access not supported in this browser.');
        return;
    }
    navigator.mediaDevices.getUserMedia({ audio: true }).then(stream => {
        mediaStream = stream;
        audioContext = new (window.AudioContext || window.webkitAudioContext)();
        sourceNode = audioContext.createMediaStreamSource(stream);
        analyser = audioContext.createAnalyser();
        analyser.fftSize = 2048;
        sourceNode.connect(analyser);
        clapListening = true;
        const btn = document.getElementById('clapToggleBtn');
        if (btn) { btn.classList.add('active'); btn.textContent = 'Clap: ON'; }
        listenLoop();
    }).catch(err => {
        console.error('Microphone permission denied', err);
        alert('Microphone permission denied.');
    });
}

function stopClap() {
    clapListening = false;
    if (rafId) cancelAnimationFrame(rafId);
    if (sourceNode) sourceNode.disconnect();
    if (analyser) analyser.disconnect();
    if (mediaStream) {
        mediaStream.getTracks().forEach(t => t.stop());
        mediaStream = null;
    }
    if (audioContext) { try { audioContext.close(); } catch(e){} audioContext = null; }
    const btn = document.getElementById('clapToggleBtn');
    if (btn) { btn.classList.remove('active'); btn.textContent = 'Enable Clap'; }
}

function listenLoop() {
    if (!analyser) return;
    const buffer = new Uint8Array(analyser.fftSize);
    const sample = () => {
        analyser.getByteTimeDomainData(buffer);
        // compute peak normalized amplitude
        let max = 0;
        for (let i = 0; i < buffer.length; i++) {
            const v = Math.abs(buffer[i] - 128) / 128; // 0..1
            if (v > max) max = v;
        }
        const now = Date.now();
        if (max > CLAP_THRESHOLD && (now - lastClapTime) > CLAP_COOLDOWN) {
            lastClapTime = now;
            // found a clap
            increase();
            // visual feedback: briefly scale counter
            const counterEl = document.getElementById('counter');
            if (counterEl) {
                counterEl.classList.remove('pop');
                void counterEl.offsetWidth;
                counterEl.classList.add('pop');
            }
        }
        if (clapListening) rafId = requestAnimationFrame(sample);
    };
    rafId = requestAnimationFrame(sample);
}
function updatecounter() {
    const counterEl = document.getElementById('counter');
    if (counterEl) {
        counterEl.textContent = count;
        // small pop animation
        counterEl.classList.remove('pop');
        void counterEl.offsetWidth;
        counterEl.classList.add('pop');
    }

    // disable decrease when at zero
    const dec = document.getElementById('decreaseBtn');
    if (dec) dec.disabled = count <= 0;

    // ensure label shown
    const labelEl = document.getElementById('label');
    if (labelEl) labelEl.textContent = labelCount;
}

// initialize UI state on load
window.addEventListener('DOMContentLoaded', () => {
    updatecounter();
});