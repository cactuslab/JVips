# Cactuslab build instructions

Edit `pom.xml` to set the appropriate project version.

```shell
export JAVA_HOME=$(/usr/libexec/java_home -v 1.8)
./build.sh --with-macos --without-linux
docker build --build-arg UID=$(id -u) --build-arg GID=$(id -g) -f .github/docker/linux/Dockerfile -t builder .
docker run --rm -v $(pwd):/app -w /app -u root -it builder
mvn package -DskipTests -Pminimal
```

The output files are `pom.xml` and `JVips.jar`.

Deploy to a repository or install locally using:

```shell
mvn install -DskipTests -Pminimal
```

## Minimal

We use the `minimal` profile when building the `JVips.jar` so we only include the JVips native code, rather than
all of the Linux dependencies as well. This is because the Linux dependencies may not be compatible with all
flavours of Linux, so we instead rely on locally installed dependencies.
