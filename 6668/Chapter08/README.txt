To build C++ programs, refer to the BDB XML reference guide.

On Unix, compile thus (your paths may differ):

  % g++ -I/usr/local/dbxml/install/include/ -I/usr/local/dbxml/install/include/dbxml/ -c test.cpp

Then link:

  % g++ -I/usr/local/dbxml/install/include/ -I/usr/local/dbxml/install/include/dbxml/ -c test.cpp

