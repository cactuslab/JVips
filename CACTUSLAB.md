# Cactuslab build instructions

First we build for Linux on x86:

```shell
export JAVA_HOME=$(/usr/libexec/java_home -v 17)

docker pull --platform linux/amd64 ubuntu:20.04
docker build --platform linux/amd64 --build-arg UID=$(id -u) --build-arg GID=$(id -g) -f .github/docker/linux/Dockerfile -t jvips-builder-linux .
docker run --platform linux/amd64 --rm -v $(pwd):/app -it jvips-builder-linux
```

Note that the AVIF tests fail as libheif on Ubuntu 20 doesn't support that codec. As long as it's
just those tests failing we can move on.

Then we build for Linux on ARM:

```shell
docker pull --platform linux/arm64 ubuntu:20.04
docker build --platform linux/arm64 --build-arg UID=$(id -u) --build-arg GID=$(id -g) -f .github/docker/linux/Dockerfile -t jvips-builder-linux-arm .
docker run --platform linux/arm64 --rm -v $(pwd):/app -it jvips-builder-linux-arm
```

Note that Java on Linux on ARM in Docker doesn't work well and will fail.
See https://github.com/moby/buildkit/issues/2612

Then we build for macOS on an Intel machine, and then again on an Apple Silicon:

```shell
./build.sh --with-macos --without-linux
```

For macOS we also build on an Apple Silicon machine and then copy the `JVips.jar` to the Intel machine.

On the Intel machine:

```shell
# In this folder
mkdir applesilicon
cd applesilicon
# Extract the jar from the other machine
jar xf ~/Desktop/JVips.jar
mkdir universal
for i in *.dylib; do lipo ../build/all/$i $i -create -output universal/$i ; done
cp -f universal/* ../build/all
cd ..
```

The output files are `pom.xml` and `JVips.jar`.

```shell
source lib/VERSIONS
suffix=CACTUSLAB
version=${VIPS_VERSION}-$suffix
mvn -DnewVersion=$version versions:set
mvn package -P deploy -DskipTests
mvn install:install-file -Dfile=JVips.jar -DgroupId=com.criteo -DartifactId=jvips -Dversion=${VIPS_VERSION}-$suffix -Dpackaging=jar -DpomFile=pom.xml -Dsources=target/jvips-$version-sources.jar -Djavadoc=target/jvips-$version-javadoc.jar
mvn deploy:deploy-file -Durl=https://maven.cactuslab.com/thirdparty/ -DrepositoryId=cactuslab-thirdparty -DpomFile=pom.xml -Dfile=JVips.jar -Dsources=target/jvips-$version-sources.jar -Djavadoc=target/jvips-$version-javadoc.jar
mvn versions:revert
```

Note if doing a re-release, use `-CACTUSLAB1` etc as a suffix.

Note we do a final packaging using the "deploy" profile to generate sources and javadoc.
