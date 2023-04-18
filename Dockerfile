FROM alpine:latest

LABEL maintainer "srz_zumix <https://github.com/srz-zumix>"

ARG BRANCH_OR_TAG=main
RUN env \
  && apk update && apk upgrade \
  && apk add --no-cache -q -f git cmake make g++ lcov gettext-base jq curl

RUN git clone --depth=1 -b $BRANCH_OR_TAG -q https://github.com/google/googletest.git /googletest
RUN mkdir -p /googletest/build
WORKDIR /googletest/build
RUN cmake .. && make && make install
RUN mkdir -p /code
WORKDIR /code


COPY . /code/

ENV GTEST_REPO=/googletest
ENV GTEST_DIR=${GTEST_REPO}/googletest
ENV WORKDIR=/usr/src


# sleep forever to keep container running

# CMD ash -c "while true; do sleep 1; done"

CMD /code/test_runner.sh