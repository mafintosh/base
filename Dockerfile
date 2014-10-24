FROM ubuntu:14.04
RUN apt-get update && apt-get -qy install curl git-core build-essential python
ADD ./spawn.c /
RUN cc /spawn.c -o /bin/spawn && rm /spawn.c