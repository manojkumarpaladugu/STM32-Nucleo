# Docker

* Build: `docker build -f Build/Docker/Dockerfile -t arm-gcc .`

* Run: `docker run --rm -it -v ${PWD}:/home/workspace arm-gcc /bin/bash`
