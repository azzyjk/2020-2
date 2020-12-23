FROM ubuntu:latest

RUN apt-get update
RUN apt-get upgrade -y
RUN apt-get install gcc -y
RUN apt-get install vim -y

WORKDIR /home/
