#ifndef REUSABLES_H
#define REUSABLES_H

// constants and MACROS

// Classes
class Socket {
    public:
        Socket(int ip, int port);
        ~Socket();

        // data members
        struct sockadd_in serverAddress, clientAddress;

        static void setupAddressStruct(struct sockaddr_in *address, const int portNumber);

#endif //REUSABLES_H
