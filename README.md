# UnitTestPractice

## Getting Started

Prerequisites:
* Docker (\*nix) or Docker Desktop (Windows/Mac)

With Docker running, execute the following commands in order.

This will generate the container image. It needs to be run each time the
container configuration changes.

`docker build -t gtest .`

This will use the current code, attempt to build it, and run its tests
within the container. If you change the code (and not the container
configuration), you only need to repeat this command.

`docker run --mount type=bind,source="$(pwd)",target=/usr/src -it gtest`
