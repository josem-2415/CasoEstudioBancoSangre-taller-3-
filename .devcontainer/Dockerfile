FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive \
    USER=dev \
    UID=1000 \
    WORKDIR=/home/dev/project

# instalar herramientas C++ + debugging + librerías
RUN apt-get update \
 && apt-get install -y --no-install-recommends \
    git \
    build-essential \
    gdb \
    gdbserver \
    cmake \
    ninja-build \
    clang \
    lldb \
    valgrind \
    make \
    sudo \
    ca-certificates \
    openssh-client \
    procps \
    # librerías extra
    libcurl4-openssl-dev \
    nlohmann-json3-dev

# Instalar GoogleTest
RUN apt-get install -y libgtest-dev && \
    cd /usr/src/gtest && \
    cmake . && \
    make && \
    mv lib/*.a /usr/lib

# RUN rm -rf /var/lib/apt/lists/*

# crear usuario no-root
RUN useradd -m -u ${UID} ${USER} \
 && echo "${USER} ALL=(ALL) NOPASSWD:ALL" > /etc/sudoers.d/${USER} \
 && chmod 0440 /etc/sudoers.d/${USER}

WORKDIR ${WORKDIR}
USER ${USER}

EXPOSE 2345

ENTRYPOINT ["tail", "-f", "/dev/null"]
