#include <stdio.h>
#include "restServer.h"

using namespace std;

int main(){

    RestServer restServer;
    restServer.initialize("http://localhost:5000");

    while(1);

    return 0;
}