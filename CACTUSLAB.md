# Cactuslab build instructions

Edit `pom.xml` to set the appropriate project version.

```shell
export JAVA_HOME=$(/usr/libexec/java_home -v 1.8)
docker build --build-arg UID=$(id -u) --build-arg GID=$(id -g) -f .github/docker/linux/Dockerfile -t builder .
docker run --rm -v $(pwd):/app -w /app -u root -it builder
./build.sh --with-macos --without-linux
```

The output files are `pom.xml` and `JVips.jar`.

```shell
source lib/VERSIONS
mvn -DnewVersion=${VIPS_VERSION}-CACTUSLAB versions:set
mvn install:install-file -Dfile=JVips.jar -DgroupId=com.criteo -DartifactId=jvips -Dversion=${VIPS_VERSION}-CACTUSLAB -Dpackaging=jar -DpomFile=pom.xml
mvn deploy:deploy-file -Durl=https://maven.cactuslab.com/thirdparty/ -DrepositoryId=cactuslab-thirdparty -DpomFile=pom.xml -Dfile=JVips.jar
mvn versions:revert
```
