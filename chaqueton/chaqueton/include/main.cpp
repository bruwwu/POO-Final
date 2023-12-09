
/*
----------------------------SINGLETON
#pragma once
#include "Prerequisites.h"

  Singleton* SingleMan = Singleton::getInstance();
  SingleMan->setValue(27);

  //Muestra el valor almacenado en Singleton
  Singleton* SingleMan2 = Singleton::getInstance();
  cout << "Value: " << SingleMan2->getValue() << endl;

  
  
  //Obtiene las instancias del Singleton
  RegistroActividad* Registro = RegistroActividad::getInstance();
  RegistroActividad* Registro2 = RegistroActividad::getInstance();

  //Agrega actividades al primer registro
  Registro->addActivity("Primer actividad");
  Registro->addActivity("Segunda actividad");
  Registro->addActivity("Tercera actividad");
  Registro->addActivity("Cuarta actividad");


--------------------------------ABSTRACT FACTORY
#pragma once
#include "Prerequisites.h"

//Clase base para productos A
class ProductA {
public:
  virtual
    void
    operationA() = 0;
};

//Clase base para productos B
class ProductB {
public:
  virtual
    void
    operationB() = 0;
};

//Clase abstract factory
class AbstractFactory {
  public:
    virtual ProductA* crearProductoA() = 0;
    virtual ProductB* crearProductoB() = 0;
}; 

//Clase concreta para productos A
class productA1 : public ProductA {
public:
  void
    operationA() override {
    cout << "Operaci?n A en ProductoA1" << endl;
  }
};

//Clase concreta para productos B
class productB1 : public ProductB {
public:
  void
    operationB() override {
    cout << "Operacin B en ProductoA1" << endl;
  }
};

//Clase concreta para la implementacion de abstract factory
class ConcreteAbsFactory : public AbstractFactory {
public:
  ProductA* crearProductoA() override {
    return new productA1();
  }
  ProductB* crearProductoB() override {
    return new productB1();
  }
};
----------------------------INTERFAZ VIEJA 
Se crea la interfaz vieja y la nueva
  InterfazVieja* objViejo = new InterfazVieja();
  InterfazNueva* objNuevo = new Adapter(objViejo);

  //Se llama al newMethod desde el adapter
  objNuevo->newMethod();

  //Liberar memoria asignada
  delete objViejo;
  delete objNuevo;
  }
  ----------------------------------BUILDER

  Builder* constructor = new BuilderConcreto();

  //Se crea al director que se encargara de construir el producto
  Director director(constructor);

  //Construcción del producto usando el Director
  director.build();

  //Se obtiene el nuevo producto desde el constructor
  bProduct* producto = constructor->obtenerProducto();
  producto->print();

  //Liberar memoria asignada
  delete constructor;
  delete producto
  }

----------------------PROTOTYPE

#include "Prototype.h"



Prototype* prototype = new PrototipoConcreto();
prototype->configurar("Ejemplo");


Prototype* copia = prototype->clone();
prototype->print();
copia->print();

delete prototype;
delete copia;

#include "Header.h"
#include "Prototype.h"

int main()
{
    Circulo* circulo = new Circulo();
    Cuadrado* cuadrado = new Cuadrado();

    Dibujable* adaptadorCirculo = new CirculoAdapter(circulo);
    Dibujable* adaptadorCuadrado = new CuadradoAdapter(cuadrado);

    adaptadorCirculo->Dibujar();
    adaptadorCuadrado->Dibujar();

 
    delete circulo;
    delete cuadrado;
    delete adaptadorCirculo;
    delete adaptadorCuadrado;

    return 0;
}


-------------------------------------CAFETERIA DECORATOR
#include "Header.h"

int main()
{
    Cafeteria* cafeteria = new Cafeteria();
    Leche* cafeConLeche = new Leche(cafeteria);
    Azucar* cafeConAzucar = new Azucar(cafeteria);

    cafeteria->prepararCafe();
    cafeConLeche->decorar();
    cafeConAzucar->decorar();

    delete cafeteria;
    delete cafeConLeche;
    delete cafeConAzucar;

    return 0;
}

----------------Archivo Composite
 SistemaArchivo* archivo1 = new SistemaArchivo();
 SistemaArchivo* archivo2 = new SistemaArchivo();
 SistemaCarpeta* carpeta = new SistemaCarpeta();

 //La carpeta busca a los archivos dentro de cada caroeta
 carpeta->agregarSistema(archivo1);
 carpeta->agregarSistema(archivo2);

 //La carpeta manda a llamar la función para las operaciones en los archivos
 //Dado a la estructura realizada, los archivos están vacíos
 carpeta->mostrarInfo();

 //Liberar memoria asignada
 delete archivo1;
 delete archivo2;
 delete carpeta;
}