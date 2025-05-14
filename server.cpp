#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <fstream>


//Setup socket connection
class Socket{
    public: // external access
        // constructors initialize ip and port as inputs
        Socket(int ip, int port);
        // de-constructor closes constructor when done
        ~Socket();

        // --data members--
        struct sockaddr_in serverAddress, clientAddress;

        // --Member Functions--
        // Set up address struct for server socket
        static void setupAddressStruct(struct sockaddr_in *address, const int portNumber) {
            // clear out address struct
            memset((char*) address, '\0', sizeof(*address));
            // Make network capable
            address->sin_family = AF_INET;
            // Store port number
            address->sin_port = htons(portNumber);
            // Allow a client at any address to connect to server
            address->sin_addr.s_addr = INADDR_ANY;
        }

    private: // internal only (things that doesn't get touched or changed from int main)
        // data members

        // Member Functions (can only be called on from inside the class)
        //                    (main can call on a public a class' public member function)
        //                    (that public member function can then call it's private member functions)
};

class Wrappers{
    public:
        static int sending(int socket, char *buf, size_t len) { // sends message to client and checks all data sent
            int sent = 0;
            size_t remaining = len;
            int n = 0;

            while (sent < len) {
                n = send(socket, buf + sent, remaining, 0);
                if (n == -1) break;
                sent += n;
                remaining -= n;
            }

            len = sent;
            return (n == -1) ? -1 : 0; // -1 failure, 0 success
        }

        static int receiving(int socket, char *buf, size_t len) { // Receives message from client and checks all data received
            int received = 0;
            size_t remaining = len;
            int n = 0;

            while (received < len) {
                n = recv(socket, buf + received, remaining, 0);
                if (n == -1) break;
                received += n;
                remaining -= n;
            }
            len = received;
            return (n == -1) ? -1 : 0; // -1 failure, 0 success
        }
};

class Encryption {
    public:
        // data members
        Encryption();
        ~Encryption();
        int numText, numKey = 0;
        char valid[28] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
        long i, j;
        int encrypted;

        void optEncryption(char *text, char *key, long size) {
            for (i = 0; i < size; ++i) {
                for (j = 0; j < 27; ++j) {
                    if (text[i] == valid[j]) {
                        numText = j;
                        break;
                    }
                }
                for (j = 0; j < 27; ++j) {
                    if (key[i] == valid[j]) {
                        numKey = j;
                        break;
                    }
                }
                encrypted = (encrypted + numKey) % 27;
                text[i] = valid[encrypted];
            }
        }
};

// open and read files. (work on me)
char *readFiles (std::string *file, long size) {
    ifstream input_stream(file);
    if (!input_stream) std::cerr << "Can't open file " << file << std::endl;

}

int main(){
    return 0;
}

