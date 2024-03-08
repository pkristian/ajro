# Build and run:
#   docker build --build-arg UID=$(id -u) -t clion/ubuntu/cpp-env:1.0 -f Dockerfile .

FROM ubuntu:22.04

RUN DEBIAN_FRONTEND="noninteractive" apt-get update && apt-get -y install tzdata




RUN apt-get update \
  && apt-get install -y build-essential \
      gcc \
      g++ \
      gdb \
      clang \
      make \
      cmake \
      ninja-build \
      autoconf \
      automake \
      libtool \
      valgrind \
      locales-all \
      dos2unix \
      rsync \
      tar \
      python3 \
      python3-dev \
      python-is-python3 \
  && apt-get clean


ARG UID=1000
RUN useradd -m -u ${UID} -s /bin/bash builder
USER builder