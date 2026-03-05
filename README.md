# VibeCodeDemo

A simple Rock-Paper-Scissors web game implemented with C++ game logic compiled to WebAssembly using Emscripten. The user interface is built with HTML, Tailwind CSS, and JavaScript.

## Features

- Rock-Paper-Scissors game logic in C++
- WebAssembly compilation for fast execution in the browser
- Clean UI with Tailwind CSS
- Static site deployable on GitHub Pages

## How to Build

1. Install Emscripten SDK:
   ```bash
   git clone https://github.com/emscripten-core/emsdk.git
   cd emsdk
   ./emsdk install latest
   ./emsdk activate latest
   source ./emsdk_env.sh
   ```

2. Compile the C++ code to WebAssembly:
   ```bash
   emcc game.cpp -o game.js -s EXPORTED_FUNCTIONS='["_play"]' -s EXPORTED_RUNTIME_METHODS='["ccall"]'
   ```

3. Open `index.html` in a web browser to play the game.

## Files

- `index.html`: Main HTML file with Tailwind CSS UI
- `script.js`: JavaScript for handling user interactions and WebAssembly calls
- `game.cpp`: C++ source code for game logic
- `game.js` and `game.wasm`: Compiled WebAssembly files (generated)

## Deployment

This is a static site, so you can deploy it directly on GitHub Pages by pushing the files to your repository.