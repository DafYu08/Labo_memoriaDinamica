#include "SistemaDeMensajes.h"

SistemaDeMensajes::SistemaDeMensajes(): _conexiones(){
    for (int i = 0; i < 4; ++i) {
        _conexiones[i] = nullptr;
    }
}

SistemaDeMensajes::~SistemaDeMensajes(){
    for (int i = 0; i < 4; ++i) {
       delete _conexiones[i];
    }
}

void SistemaDeMensajes::registrarJugador(int id, string ip){
    _conexiones[id] = new ConexionJugador(ip);
}
void SistemaDeMensajes::enviarMensaje(int id, string mensaje){
   if(registrado(id) == true) {
       (*_conexiones[id]).enviarMensaje(mensaje);
   }
}
bool SistemaDeMensajes::registrado(int id) const{
    return (_conexiones[id] != nullptr);
}
string SistemaDeMensajes::ipJugador(int id) const{
    if(registrado(id) == true) {
        return (*_conexiones[id]).ip();
    }
}
