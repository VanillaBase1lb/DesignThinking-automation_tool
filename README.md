# DesignThinking-automation_tool
Open source mouse automation tool for Windows.


Precompiled binaries can be found insidde `binaries` folder.
Download `autoclicker.exe` and `mouse_retracer.exe` directly.
Chrome might refuse to download `.exe` files and antivirus software may try to block it from executing.
Recommended to compile from scratch.

# To compile from source
Download the repository manually or using git clone:

`git clone https://github.com/VanillaBase1lb/DesignThinking-automation_tool`

`cd DesignThinking-automation_tool`

`mkdir binaries-new`

`g++ autoclicker.cpp -o .\binaries-new\autoclicker.exe`

`g++ mouse_retracer.cpp -o .\binaries-new\mouse_retracer.exe`

# Linux and MacOS users
Sorry, this project uses header files and syscalls exclusive to Windows. Try running under WINE or contribute to the project.

# Please open an issue if there is an error or the instructions are not clear enough
Sometimes it may not able to grab windows with admin privilages, in such case run as administrator.
