Hi! I made a simple program to make minecraft bedrock better.

Pre-requisites:
LeviLauncher for Windows

Installation:
Just download the file and execute it. Ctrl + C to stop the process.

Build from source:
1. Install [msys2](msys2.org) and follow default prompts.
2. Open MSYS32 MINGW64
3. Paste this command:
   
pacman -S mingw-w64-ucrt-x86_64-gcc

5. Add C:\msys64\ucrt64\bin to your Windows System PATH
6. Open a terminal on where the source is located and execute this command:

g++ script.cpp -o my_program.exe -static
