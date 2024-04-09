FROM ubuntu:latest
LABEL title="CPP Container"
LABEL version=0.1
ENV GTEST_REPO=/googletest
ENV GTEST_DIR=${GTEST_REPO}/googletest
ENV WORKDIR=/usr/src
WORKDIR /usr/src

# Set Docker arguments
ARG DEBIAN_FRONTEND=noninteractive

# Install dependencies
RUN apt-get update && \
    apt-get install -y \
            build-essential \
            g++ \
            cmake \
            git-all \
            dos2unix

# Setup GoogleTest
RUN git clone --depth=1 https://github.com/google/googletest ${GTEST_REPO}
RUN mkdir ${GTEST_REPO}/build && cd ${GTEST_REPO}/build \
    && cmake .. -DBUILD_GMOCK=OFF && make && cd ${WORKDIR}

# Copy repo source into container
COPY . ${WORKDIR}

# Assure Unix linefeed for all files
RUN find . -type f -print0 | xargs -0 dos2unix --

# Build project
CMD sh -c ${WORKDIR}/test_runner.sh