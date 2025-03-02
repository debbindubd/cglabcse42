# Setting Up Codeblocks with MinGW and GLUT

Follow these steps to set up Codeblocks with MinGW and GLUT:

1. **Install Codeblocks**
    - Download and install Codeblocks from the official website without MinGW setup: [Codeblocks 20.03 Setup](https://sourceforge.net/projects/codeblocks/files/Binaries/20.03/Windows/codeblocks-20.03-setup.exe/download)

2. **Unzip MinGW**
    2. **Unzip MinGW**
        - Download and install 7-Zip from the official website: [7-Zip 19.00 Setup](https://www.7-zip.org/a/7z2409-x64.exe)
        - Unzip `MinGW.7z` using 7-Zip software.

3. **Copy MinGW**
    - Copy the `MinGW` folder to `C:\`.

4. **Copy GLUT DLL**
    - Copy `glut32.dll` from `glut 3.7.6` and paste it into `C:\Windows\SysWOW64`.

5. **Configure Codeblocks**
    - Go to `Settings` > `Compiler` > `Linker settings`.
    - Press `Clear`.

6. **Add Libraries**
    - Press `Add` and browse to `C:\MinGW\lib`.
    - Select the following files:
      - `glut32.lib`
      - `libglu32.a`
      - `libopengl32.a`
    - Press `OK`.

7. **Create a New Project**
    - Press `Create a new project`.
    - Select `GLUT project`.
    - Enter the `Project title` and press `Next`.
    - Browse to `C:\MinGW` and press `Next`.
    - Press `Finish`.

8. **Edit main.cpp**
    - Open `main.cpp`.
    - Add `#include <windows.h>` on the 14th line.

9. **Extra: Open Project in Management View**
    - Go to `View` > `Management`.
    - Open and select the `.cbp` file.

By following these steps, you will have a working setup of Codeblocks with MinGW and GLUT.