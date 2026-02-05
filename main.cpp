#include <iostream>
#include <fstream>
#include <string>

int main() {
	// Definiendo las variables
    std::string nombreArchivo;
	std::string contenido;
	char opcion;
    
	std::cout << "--- PROGRAMA PARA LEER Y ESCRIBIR ARCHIVOS ---" << std::endl;
    
    // Registrar el nombre del archivo
	std::cout << "Ingrese el nombre del archivo: ";
	getline(std::cin, nombreArchivo);
    
    // Usando fstream para manejar el archivo
    std::ifstream archivoLectura(nombreArchivo);
    
    if (archivoLectura.is_open()) {
        std::cout << "\nContenido actual del archivo: " << std::endl;
        
        // Obteniendo cada una de las líneas del .txt
        std::string linea;
        
        // Revisa cada una de las líneas del archivo y coloca el resultado en la variable 'linea'
        while (getline(archivoLectura, linea)) 
            std::cout << linea << std::endl;
        
        // Cerrar el archivo para que no hayan problemas de memoria
        archivoLectura.close();

        // Escribiendo sobre el archivo
        std::cout << "\n¿Desea realizar modificaciones al archivo? (s/n)" << std::endl;
        std::cin >> opcion;
        std::cin.ignore(); // Limpiar el buffer para el siguiente getline()

        if(opcion == 's' || opcion == 'S'){
            std::cout << "Escriba el contenido nuevo: " << std::endl;
            
            std::string nuevaLinea;
            contenido = "";

            // Bucle que correrá siempre que haya contenido en la línea
            while(true){
                std::getline(std::cin, nuevaLinea);
                if(nuevaLinea.empty())
                    break;
                
                contenido += nuevaLinea + "\n";
            }

            // Sobrescribir el archivo
            std::ofstream archivoEscritura(nombreArchivo);

            if(archivoEscritura.is_open()) {
                archivoEscritura << contenido;
                archivoEscritura.close();
                
                std::cout << "\nArchivo modificado con éxito" << std::endl;
            } else {
                // En caso de que ocurra un error y no pueda abrirse el archivo
                std::cerr << "Error: No se pudo abrir el archivo" << std::endl;
                return 1; 
            }
        } else if(opcion == 'n' || opcion == 'N') {
            std::cout << "¡Hasta luego!" << std::endl;
            return 0;
        }
    } else {
        // Crear el archivo en caso de que no se encuentre
        std::cout << "\nEl archivo no existe. ¿Deseas crearlo? (s/n): ";
        
        std::cin >> opcion;
        std::cin.ignore();
        
        if (opcion == 's' || opcion == 'S') {
            std::cout << "Escribe el contenido:" << std::endl;
            std::string nuevaLinea;
            contenido = "";
            
            while (true) {
                std::getline(std::cin, nuevaLinea);
                if (nuevaLinea.empty()) break;
                contenido += nuevaLinea + "\n";
            }
            
            // Crear y escribir archivo
            std::ofstream archivoNuevo(nombreArchivo);
            
            if (archivoNuevo.is_open()) {
                archivoNuevo << contenido;
                archivoNuevo.close();
                std::cout << "\nArchivo creado exitosamente" << std::endl;
            } else {
                std::cerr << "Error: No se pudo crear el archivo" << std::endl;
                return 1;
            }
        }
    }
    
	return 0;
}
