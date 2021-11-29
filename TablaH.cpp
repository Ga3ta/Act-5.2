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

int main() {
    
}
