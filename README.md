# Environment Setup
* [Sharing git credentials with your container](https://code.visualstudio.com/remote/advancedcontainers/sharing-git-credentials)
* Launch Dev Container (F1 -> Dev Containers: Reopen in Container)

# Build Environment
* Install python3
* Install pre-commit
  * Install pipx: `python -m pip install --user pipx` then `python -m pipx ensurepath`
  * Install pre-commit: `pipx install pre-commit`
* Download and install [Make for Windows](https://gnuwin32.sourceforge.net/packages/make.htm)
  * Add path (`C:\Program Files (x86)\GnuWin32\bin`) of make program to system environment variable
* Download and install [STM32CubeCLT v1.16.0](https://www.st.com/en/development-tools/stm32cubeclt.html)
* Run setup script: `./setup.sh`
* Build firmware: `./mk.sh G491RET6 -t NucleoFirmware`

# Debugging via VS Code (Windows)
* Install VS Code extension 'stmicroelectronics.stm32-vscode-extension'
* Press F5 to start debugger
