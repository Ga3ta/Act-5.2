#include <iostream>

using namespace std;

//Función para quitarle el puerto a una IP
string removePort(string ip){
    string newIP = "";
    for(char c : ip){
      if(c != ':')
          newIP += c;
      else
          break;
    }
    return newIP;
}

//Función que genera una nueva línea de log para el resumen de una IP
string makelog(string month, string day, string time, string error){
    string log = month + " " + day + " @ " + time + " - " + error + "\n";
    return log;
}

//Esta función le suma uno al número de accesos del resumen de una IP
string addAccess(string &log){
    string newlog;
    int count = 0;
    int accesses = 0;
    for(int i = 19; i < log.size(); i++){
        if(log[i] != '\n'){
            count++;
            accesses += 10*accesses + (int)log[i] - 48;
        }
        else
            break;
    }
    accesses++;
    log.erase(0, count + 19);
    newlog  = "Numero de accesos: " + to_string(accesses) + log;
    return newlog;
}

int main() {
    
}
