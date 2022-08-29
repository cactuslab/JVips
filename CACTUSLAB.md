# Cactuslab build instructions

Edit `pom.xml` to set the appropriate project version.

```shell
export JAVA_HOME=$(/usr/libexec/java_home -v 1.8)
docker build --build-arg UID=$(id -u) --build-arg GID=$(id -g) -f .github/docker/linux/Dockerfile -t jvips-builder-linux .
docker run --rm -v $(pwd):/app -w /app -u root -it jvips-builder-linux
./build.sh --with-macos --without-linux
```

The output files are `pom.xml` and `JVips.jar`.

```shell
source lib/VERSIONS
suffix=CACTUSLAB
mvn -DnewVersion=${VIPS_VERSION}-$suffix versions:set
mvn install:install-file -Dfile=JVips.jar -DgroupId=com.criteo -DartifactId=jvips -Dversion=${VIPS_VERSION}-$suffix -Dpackaging=jar -DpomFile=pom.xml
mvn deploy:deploy-file -Durl=https://maven.cactuslab.com/thirdparty/ -DrepositoryId=cactuslab-thirdparty -DpomFile=pom.xml -Dfile=JVips.jar
mvn versions:revert
```

Note if doing a re-release, use `-CACTUSLAB1` etc as a suffix.
