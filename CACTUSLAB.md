# Cactuslab build instructions

# Vips version

Specify the vips version to build with in `./CMakeLists.txt` and `./build.sh`:

```
set(JVIPS_VERSION 8.14.5)
```

```bash
VIPS_VERSION=8.14.5
```

## Generate

Update the installation of vips on your local machine, such as by using Homebrew, to the version specified above.

Confirm by running and comparing against the files listed above:

```shell
vips --version
```

Then generate updated files:

```shell
cd script/generate
nvm use
pnpm install
pnpm start
```

## Build

Start with a clean:

```shell
./clean.sh
```

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

Now combine the `build/all` folder from the two macOS machines with the ones from the Linux builds.

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
