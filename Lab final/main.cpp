#include "ques2.hpp"

int main(){
    string message, processedMessage;
    cout << "Enter a string: ";
    getline(cin, message);
    processedMessage = pre_process(message);

    cout << "Binary representation of Input Message after padding (Processed Message): " << endl << processedMessage << endl;
    cout << message.size()<< endl;
    cout << processedMessage.size() << endl;

    return 0;
}