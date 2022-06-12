#pragma once 

struct Header {
    int size;
};

struct Header swapHeader(struct Header _header);

int sendData(int fd, void* buf, int size);

void* recvData(int fd);

struct PayloadHeader {
    int type;
    int size;
    int slot1;
    int slot2;
    int slot3;
    int slot4;
};

struct Payload {
    struct PayloadHeader header;
    const char* data;
};

struct PayloadHeader alignPayloadHeader(struct PayloadHeader header);

void freePayload(struct Payload* payload);

int sendPayload(int fd, struct Payload payload);

struct Payload* recvPayload(int fd);

int test_main(int argc, char* argv[]);

