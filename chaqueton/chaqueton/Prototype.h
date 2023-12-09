/*

--------------------SINGLETON
#pragma once

class Singleton
{
public:
	Singleton() : m_value(0) {};

	static
		Singleton*
		getInstance() {
		if (m_instance != nullptr) // Verifica si m_instance ya esta inicializado
		{
			return m_instance; // Devuelve un Singleton existente
		} else {
		m_instance = new Singleton; // Devuelve un Singleton creado
		}
		return m_instance; // Devuelve el Singleton creado o existente
	}

	~Singleton() = default;

	//Establecer el valor de la variable m_value
	void
		setValue(int _v) {
		m_value = _v;
	}

	//Obtener el valor de la variable m_value
	int
		getValue() {
		return m_value;
	}

private:
	static Singleton* m_instance;
	int m_value;
};

-----------------ABSTRACT FACTORY
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
    cout << "OperaciOn A en ProductoA1" << endl;
  }
};

//Clase concreta para productos B
class productB1 : public ProductB {
public:
  void
    operationB() override {
    cout << "Operacion B en ProductoA1" << endl;
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
----------------------SINGLETON
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Clase de ejemplo para el pattern de Singleton
class RegistroActividad {
public:
  RegistroActividad() : m_numActs(0) {}

  static
	RegistroActividad*
	getInstance() { //Obtiene la instancia del Singleton
	if (m_instance != nullptr) 
	{
	  return m_instance;
	}
	else {
	  m_instance = new RegistroActividad;
	}
	return m_instance;
  }

  void
	addActivity(const string actividad) { //Funcion para agregar una actividad al registro
	if (m_numActs < m_maxActs) { //Verificar que el registro no esta lleno
	  //m_acts[m_numActs++] = actividad;
	  m_acts.push_back(actividad); //Agrega la actividad al vector m_acts
	}
	else {
	  cout << "Registro de actividades est? lleno." << endl;
	}
  }

  void
	showActivities() { //Funcion para mostrar todas las actividades registradas
	cout << "Registro de Actividades:" << endl;
	for (const string actividad:m_acts) {
	  //for (int i = 0; i < m_numActs; i++)
	  //cout << m_acts[i] << endl;
	  cout << actividad << endl;
	}
  }

private:
  static RegistroActividad* m_instance;
  static const int m_maxActs = 20;
  //string m_acts[m_maxActs];
  vector<string> m_acts;
  int m_numActs;
};
-----------------------------------PROTOTYPE
#pragma once
#include "Prerequisitos.h"
#include <iostream>


class Prototype 
{
public : 
	virtual Prototype clone() = 0;
	virtual void configurar(string _value) = 0;
	virtual void print() = 0;
};

class PrototipoConcreto : public Prototype
{
public: 
	Prototype* clone() override
	{
		PrototipoConcreto* copy = new PrototipoConcreto();
		copy->configurar(n_value);
		return copy;
	}

	void configurar(string _value) override
	{
		n_value = _value;
	}

	void print() override
	{
		cout << "Value: " << n_value << endl;
	}

private:
	string n_value;
}


-------------------------------CIRCULO
#include "Header.h"



class Circulo
{
public: 
	virtual void dibujarCirculo()
	{
		cout << "Circulo pro" << endl;
	}
};

class Cuadrado
{
	public:
		 virtual void dibujarCuadrado()
		{
			cout << "Cuadrado medio pro" << endl;
		}
};

class Dibujable
{
public:
	virtual void Dibujar() = 0;
};

class CirculoAdapter : public Dibujable
{
public: 
	CirculoAdapter(Circulo* _circulo) : m_Circulo(_circulo){}

	void Dibujar() override
	{
		cout << "Adapador de circulo pro" << endl;
		m_Circulo->dibujarCirculo();
	}

public:
	Circulo* m_Circulo;
};


class CuadradoAdapter : public Dibujable
{
public:
	CuadradoAdapter(Cuadrado* _cuadrado) : m_Cuadrado(_cuadrado) {}

	void Dibujar() override
	{
		cout << "Adapador de cuadrado pro" << endl;
		m_Cuadrado->dibujarCuadrado();
	}

public:
	Cuadrado* m_Cuadrado;
};


---------------------------COMPONENT
#pragma once
#include "Header.h"

class component 
{
 public: 
	virtual void operacion() = 0;
};

class ConcreteComponent : public Component
{
public:
	void operacion 
};
-----------------------------------CAFETERIA DECORATOR
#pragma once
#include "Prerequisites.h"

//Clase concreta para la cafeteria
class
  Cafeteria {
public:
  void prepararCafe() {
	cout << "Cafe preparado" << endl;
  }
};

//Clase base para los condimentos
class
  Condimento {
public:
  virtual void decorar() = 0;
};

//Decorador base para añadir la leche usando Condimento
class
  Leche : public Condimento {
public:
  Leche(Cafeteria* _condimento) :
	m_component(_condimento) { }

  void decorar() override {
	m_component->prepararCafe();
	cout << "Cafe con leche" << endl;
  }

private:
  Cafeteria* m_component;
};

//Decorador base para añadir la azucar usando Condimento
class
  Azucar : public Condimento {
public:
  Azucar(Cafeteria* _condimento) :
	m_component(_condimento) { }

  void decorar() override {
	m_component->prepararCafe();
	cout << "Cafe con azucar" << endl;
  }

private:
  Cafeteria* m_component;
};


----------------------------------------ARCHIVO
#pragma once
#include "Header.h"

// Interfaz Sistema
class Sistema {
public:
	virtual void mostrarInfo() const = 0;
};

// Clase Archivo
class Archivo : public Sistema {
public:
	void mostrarInfo() const override {
		cout << "Soy archivo" << endl;
	}
};

// Clase Carpeta
class Carpeta : public Sistema {
public:
	vector<Sistema*> sistemas;

	// Método para agregar un sistema a la carpeta
	void agregarSistema(Sistema* sistema) {
		sistemas.push_back(sistema);
	}

	void mostrarInfo() const override {
		cout << "Soy carpeta" << endl;
		cout << "Contenido de la carpeta:" << endl;
		for (const auto& sistema : sistemas) {
			sistema->mostrarInfo();
		}
	}

	// Destructor para liberar la memoria de los sistemas en la carpeta
	~Carpeta() {
		for (const auto& sistema : sistemas) {
			delete sistema;
		}
	}
};

// Clase sistemaArchivo hereda de Archivo y Carpeta
class SistemaArchivo : public Archivo, public Carpeta {
public:
	// Implementación del método mostrarInfo() de la interfaz Sistema
	void mostrarInfo() const override {
		cout << "Soy sistemaArchivo" << endl;
	}
};

// Clase SistemaCarpeta que hereda de Carpeta y Sistema
class SistemaCarpeta : public Carpeta, public Sistema {
public:
	// Implementación del método mostrarInfo() de la interfaz Sistema
	void mostrarInfo() const override {
		cout << "Soy sistemaCarpeta" << endl;
	}
};






















