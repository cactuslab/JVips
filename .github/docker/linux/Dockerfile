FROM ubuntu:22.04

# Set default build arguments.
ARG NODE_VERSION=18.x

# Set default user (overriden in the command line with Jenkins' actual user).
ARG UNAME=jenkins
ARG UID=1000
ARG GID=1000

# Set default environment variables.
ENV PATH="${OSX_CROSS_HOME}/bin:${PATH}"
ENV APT_OPTIONS="-y --no-install-recommends"
ENV DEBIAN_FRONTEND noninteractive

# Install system dependencies.
RUN apt-get update && \
    apt-get install ${APT_OPTIONS} \
    wget \
    curl \
    git \
    cmake \
    meson \
    ninja-build \
    patch \
    clang \
    nasm \
    yasm \
    autoconf \
    automake \
    libtool \
    diffutils \
    libssl-dev \
    libexpat1-dev \
    zlib1g-dev \
    libxml2-dev \
    liblzma5 liblzma-dev \
    libmpfr-dev \
    libgmp3-dev \
    libmpc-dev \
    gtk-doc-tools \
    gobject-introspection \
    libgirepository1.0-dev \
    openjdk-17-jdk \
    python3-pip \
    libglib2.0-dev

RUN apt-get install ${APT_OPTIONS} curl && \
    cd /opt && \
    curl -OL https://dlcdn.apache.org/maven/maven-3/3.9.1/binaries/apache-maven-3.9.1-bin.tar.gz && \
    tar -zxf apache-maven-3.9.1-bin.tar.gz
ENV PATH="/opt/apache-maven-3.9.1/bin:${PATH}"

RUN ln -s /usr/lib/jvm/java-17-openjdk-* /usr/lib/jvm/java-17-openjdk
ENV JAVA_HOME="/usr/lib/jvm/java-17-openjdk"

# Switch to a non-root user.
RUN groupadd -g $GID -o $UNAME
RUN useradd -l -m -u $UID -g $GID -o -s /bin/bash -d /home/$UNAME $UNAME && \
    mkdir -p /app && \
    chown $UID:$GID /app

VOLUME /app
WORKDIR /app
USER $UNAME

# The ls -la fixes git permissions issues on the /app dir
CMD ls -la && bash -l -ex build.sh --with-linux --without-w64 --without-macos
