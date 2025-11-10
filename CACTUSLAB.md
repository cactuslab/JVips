# Cactuslab build instructions

# Vips version

We build using the version of Vips that's installed in our Docker container, and on the macOS machine where we build.
So to upgrade Vips, first upgrade the version of Vips in the libvips PPA that we use.

We should run the generate script on the OLDEST version of Vips that we're supporting with this release, and that's the
version that we should use to version the JVips package.

## Build

Start with a clean:

```shell
./clean.sh
```

We build with an old version of Ubuntu to ensure that the native library we creates works on that version, and any later versions.

First we build for Linux on x86:

```shell
export JAVA_HOME=$(/usr/libexec/java_home -v 17)

# Build the Docker image
docker buildx build --platform linux/amd64 --pull --build-arg UID=$(id -u) --build-arg GID=$(id -g) -f .github/docker/linux/Dockerfile -t jvips-builder-linux .

# Generate source files
docker run --platform linux/amd64 --rm -v $(pwd):/app -it jvips-builder-linux ./generate.sh

# Build
docker run --platform linux/amd64 --rm -v $(pwd):/app -it jvips-builder-linux
```

Note that the AVIF tests fail as libheif on Ubuntu 20 doesn't support that codec. As long as it's
just those tests failing we can move on.

Then we build for Linux on ARM:

```shell
docker buildx build --platform linux/arm64 --pull --build-arg UID=$(id -u) --build-arg GID=$(id -g) -f .github/docker/linux/Dockerfile -t jvips-builder-linux-arm .
docker run --platform linux/arm64 --rm -v $(pwd):/app -it jvips-builder-linux-arm
```

Then we build for macOS on an Intel machine, and then again on an Apple Silicon:

```shell
brew install cmake
./build.sh --with-macos --without-linux
```

Now combine the `build/all` folder from the two macOS machines with the ones from the Linux builds.

Decide the version number of the JVips library to publish. Ideally we've used the same version:

```shell
docker run --rm --platform linux/amd64 jvips-builder-linux vips -v
docker run --rm --platform linux/arm64 jvips-builder-linux-arm vips -v
vips -v
```

It's probably best to use the version from `jvips-builder-linux vips` as that's the one we use to generate our code.

```shell
VIPS_VERSION=8.17.3
```

The output files are `pom.xml` and `JVips.jar`.

```shell
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
