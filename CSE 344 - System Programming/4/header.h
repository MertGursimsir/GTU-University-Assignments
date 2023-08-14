#define CLIENT_FIFO_TEMPLATE "/tmp/%ld"
#define CLIENT_FIFO_NAME_LEN (sizeof(CLIENT_FIFO_TEMPLATE) + 20)
#define REQUEST_SIZE 5120
#define RESPONSE_SIZE 65000
#define INITIAL_MESSAGE_SIZE 1024
#define PATH_MAX 4096

struct request{
    pid_t pid; //CLIENT PID
    char currentDirectory[PATH_MAX];
    char seq[REQUEST_SIZE];
};

struct response{
    char seq[RESPONSE_SIZE];
    //int continued;
};