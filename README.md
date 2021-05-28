# DesignThinking-automation_tool
Open source mouse automation tool for Windows.

`autoclicker.exe` simulates multiple clicks without any restriction over mouse position.

`mouse_retracer_static.exe` saves mouse positions on screen any repeats it any number of times with a constatnt time delay between 2 clicks.

`mouse_retracer_dynamic.exe` saves mouse positions on screen any repeats it any number of times with the original time delay (that existed while recording mouse steps) between 2 clicks.

# How to download
Precompiled binaries can be found insidde `binaries` folder.:
Download `autoclicker.exe`,  `mouse_retracer_static.exe`, `mouse_retracer_dynamic.exe` directly.
Chrome might refuse to download `.exe` files and antivirus software may try to block it from executing.
Recommended to compile from scratch.

# To compile from source
Download the repository manually or using git clone:

`git clone https://github.com/VanillaBase1lb/DesignThinking-automation_tool`

`cd DesignThinking-automation_tool`

`mkdir binaries-new`

`g++ autoclicker.cpp -o .\binaries-new\autoclicker.exe`

`g++ mouse_retracer_static.cpp -o .\binaries-new\mouse_retracer_static.exe -static-libstdc++ -static-libgcc`    --- static flags optional

`g++ mouse_retracer_dynamic.cpp -o .\binaries-new\mouse_retracer_dynamic.exe -static-libstdc++ -static-libgcc`    --- static flags optional

# Linux and MacOS users
Sorry, this project uses header files and syscalls exclusive to Windows. Try running under WINE or contribute to the project.

# Please open an issue if there is an error or the instructions are not clear enough
Sometimes it may not able to grab windows with admin privilages, in such case run as administrator.
