# STM32 Nucleo Firmware Development

## Development Environment

### [ Windows ]

* Install python3

* Install pre-commit

  * Install pipx: `python -m pip install --user pipx` then `python -m pipx ensurepath`

  * Install pre-commit: `pipx install pre-commit`

* Download and install [Make for Windows](https://gnuwin32.sourceforge.net/packages/make.htm)

  * Add path (`C:\Program Files (x86)\GnuWin32\bin`) to system environment variable

* Download and install [STM32CubeCLT v1.16.0](https://www.st.com/en/development-tools/stm32cubeclt.html)

### [ Linux ]

* Not tried yet

### [ Dev Container ]

* [Sharing git credentials with your container](https://code.visualstudio.com/remote/advancedcontainers/sharing-git-credentials)

* Launch Dev Container (F1 -> Dev Containers: Reopen in Container)

## Build Firmware

* Clone this repository: `git clone https://github.com/manojkumarpaladugu/STM32-Nucleo.git`

* Run setup script: `./setup.sh`

* Build firmware for G491RET6: `./mk.sh G491RE`

## Debugging via VS Code

Note: Debugging via VS Code is not tried on Linux and Dev Container as of now.

* Install VS Code extension `stmicroelectronics.stm32-vscode-extension`

* Press F5 to start debugger
