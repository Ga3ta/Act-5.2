#include <iostream>
#include <fstream>
#include <unordered_map>

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
  //Creamos el archivo para leer la bitácora
    ifstream archivo("bitacora-5_2.txt");

    //Creamos la tabla hash para la IP y su resumen
    unordered_map<string, string> ipResumen;

    //Creamos las variables para ir leyendo las líneas de la bitácora
    string month, day, time, ip, error, newlog;

    //Aquí leemos línea por línea la bitácora
    while(archivo>>month>>day){
        //Leemos todos los datos de una entrada de bitácora
        archivo>>time>>ip;
        getline(archivo, error);

        //Le quitamos el puerto a la ip
        ip = removePort(ip);

        //Generamos una nueva línea de resumen de la IP
        newlog = makelog(month, day, time, error);

        //Si en la tabla ya existe la entrada de la IP que leímos
        //utilizamos la función addAccess para sumarle un acceso
        if(ipResumen.find(ip) != ipResumen.end())
            ipResumen[ip] = addAccess(ipResumen[ip]);
        //De lo contrario, inicializamos el número de accesos a 1
        else
            ipResumen[ip] = "Numero de accesos: 1\n";
        //Le agregamos la nueva línea al resumen
        ipResumen[ip] += newlog;
    }
    //Generamos las variables para hacer la búsqueda del resumen de alguna IP proporcionada
    string input;
    char goOn;
    do{
        //Pedimos al usuario ingresar una IP e imprimimos el 
        //resumen de la IP proporcionada
        cout<<"Ingrese IP para consultar accesos: ";
        cin>>input;
        cout<<endl;
        //Imprimimos el resumen si existe la IP en la tabla
        if(ipResumen.find(input) != ipResumen.end())
            cout<<ipResumen[input]<<endl;
        //Si no, imprimimos un mensaje de error
        else
            cout<<"No se encontraron registros para la IP buscada\n\n";
        cout<<"Desea seguir consultando IPs? y/N ";
        cin>>goOn;
        cout<<endl;
    }while(goOn == 'y');
}