FROM ubuntu:22.04
LABEL title="Unit Testing CPP"
LABEL version=0.1
ENV GTEST_REPO=/googletest
ENV GTEST_DIR=${GTEST_REPO}/googletest
ENV WORKDIR=/usr/src
WORKDIR /usr/src
COPY . ${WORKDIR}

# Install dependencies
RUN apt-get update && \
    DEBIAN_FRONTEND=noninteractive \
    apt-get install -y \
            build-essential \
            g++ \
            cmake \
            git-all \
            dos2unix

# Setup GoogleTest
RUN git clone https://github.com/google/googletest ${GTEST_REPO}
RUN mkdir ${GTEST_REPO}/build
RUN cd ${GTEST_REPO}/build && cmake .. -DBUILD_GMOCK=OFF
RUN make
RUN cd ${WORKDIR}

# Assure Unix linefeed in shell command
RUN find . -type f -print0 | xargs -0 dos2unix --

# Build and run tests
CMD sh -c ${WORKDIR}/test_runner.sh