FROM ubuntu:20.04

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
    curl \
    ca-certificates \
    cmake \
    openjdk-17-jdk \
    software-properties-common \
    make \
    build-essential \
    git

RUN cd /opt && \
    curl -OL https://dlcdn.apache.org/maven/maven-3/3.9.2/binaries/apache-maven-3.9.2-bin.tar.gz && \
    tar -zxf apache-maven-3.9.2-bin.tar.gz
ENV PATH="/opt/apache-maven-3.9.2/bin:${PATH}"

RUN ln -s /usr/lib/jvm/java-17-openjdk-* /usr/lib/jvm/java-17-openjdk
ENV JAVA_HOME="/usr/lib/jvm/java-17-openjdk"

RUN add-apt-repository -y ppa:0k53d-karl-f830m/vips && \
    apt-get install ${APT_OPTIONS} libvips42 libvips-dev

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
