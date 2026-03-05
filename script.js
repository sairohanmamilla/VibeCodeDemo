// Load the WebAssembly module
Module.onRuntimeInitialized = function() {
    console.log("WebAssembly module loaded");
};

// Choices array for display
const choices = ["Rock", "Paper", "Scissors"];
const results = ["Draw", "You Win!", "You Lose"];

document.getElementById('rock').addEventListener('click', () => playGame(0));
document.getElementById('paper').addEventListener('click', () => playGame(1));
document.getElementById('scissors').addEventListener('click', () => playGame(2));

function playGame(userChoice) {
    const encodedResult = Module.ccall('play', 'number', ['number'], [userChoice]);
    const computerChoice = encodedResult & 3;
    const result = encodedResult >> 2;

    document.getElementById('computer-choice').textContent = `Computer chose: ${choices[computerChoice]}`;
    document.getElementById('result').textContent = results[result];
}