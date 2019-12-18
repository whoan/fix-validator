FROM whoan/quickfix:debian-buster as build-stage

RUN \
  apt-get update && \
  apt-get install --yes cmake g++ && \
  rm -rf /var/lib/apt/lists/*

COPY src /app/src
COPY CMakeLists.txt /app/

WORKDIR /app

RUN \
  mkdir build && cd build && \
  cmake .. && \
  make -j$(nproc) install


FROM debian:buster-slim

COPY --from=build-stage /usr/local/lib/libquickfix.so* /usr/lib/
COPY --from=build-stage /usr/local/bin/fix-validator /usr/bin

ENTRYPOINT ["fix-validator"]
