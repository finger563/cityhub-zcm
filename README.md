# cityhub-zcm
=============

ZCM example for pulling sensor data through REST into ZCM for data
analysis.

Example Dependency
----------------

* Install library dependencies

```bash
$ sudo apt-get install autoconf automake libtool curl
```

* Install libzmq

```bash
$ git clone https://github.com/zeromq/libzmq
$ cd libzmq
$ ./autogen.sh && ./configure && make -j 4
$ make check && sudo make install && sudo ldconfig
```

* Download and copy cppzmq headers

```bash
$ git clone https://github.com/zeromq/cppzmq
$ cd cppzmq
$ sudo cp *.hpp /usr/local/include/.
```

* Install ZCM

```bash
$ git clone https://github.com/pranav-srinivas-kumar/zcm
$ cd zcm
$ make
$ sudo make install
$ sudo ldconfig
```

* Install cpprestsdk

[CPPRESTSDK](http://github.com/Microsoft/cpprestsdk) is reqiured for
the REST interaction with cityhub-sdk.  Please follow the instructions
[here](http://github.com/Microsoft/cpprestsdk/wiki/How-to-build-for-Linux)
here for building and installing CPPRESTSDK.

Running this Example
-----------------

```bash
$ make
$ make run
```