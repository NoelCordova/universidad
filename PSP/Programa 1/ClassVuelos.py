#!/usr/bin/env python

file = open("registro.txt", "r")

class Vuelos():
    def __init__(self):
        self.nombreAerolinea    = []
        self.numVuelo           = []
        self.origen             = []
        self.destino            = []
        self.fechaSalida        = []
        self.horaSalida         = []
        self.duracion           = []
        self.precioEjecutivo    = []
        self.precioEconomico    = []
        self.numVueloEjecutivo  = []
        self.numVueloEconomico  = []
        self.llegada            = []

        
    def separar(self):
        cont = 1
        
        lines = file.read()
        line = lines.split("\n")

        for x in range(len(line)):
            cadena = line[x]
            newCad = cadena.split(" ")

            for y in range(len(newCad)):
                if cont == 1:
                    self.nombreAerolinea.append(newCad[y])
                    cont = cont + 1

                elif cont == 2:
                    self.numVuelo.append(newCad[y])
                    cont = cont + 1

                elif cont == 3:
                    self.origen.append(newCad[y])
                    cont = cont + 1

                elif cont == 4:
                    self.destino.append(newCad[y])
                    cont = cont + 1

                elif cont == 5:
                    self.fechaSalida.append(newCad[y])
                    cont = cont + 1

                elif cont == 6:
                    self.horaSalida.append(newCad[y])
                    cont = cont + 1

                elif cont == 7:
                    self.duracion.append(newCad[y])
                    cont = cont + 1

                elif cont == 8:
                    self.precioEjecutivo.append(newCad[y])
                    cont = cont + 1

                elif cont == 9:
                    self.precioEconomico.append(newCad[y])
                    cont = cont + 1

                elif cont == 10:
                    self.numVueloEjecutivo.append(newCad[y])
                    cont = cont + 1

                elif cont == 11:
                    self.numVueloEconomico.append(newCad[y])
                    cont = cont + 1

                elif cont == 12:
                    self.llegada.append(newCad[y])
                    cont = 1
    
    
    def consultaAerolinea(self):
        dato = raw_input("Nombre de la aerolinea: ")


        if dato in self.nombreAerolinea:

            print '\nInformacion de vuelos de la aerolinea ' + dato + '\n'

            print   (
                        #"Vuelo\t\t"               +
                        "Num. Vuelo\t"          +
                        "Origen\t\t"              +
                        "Destino\t\t"             +
                        "F - Salida\t"          +
                        "H - Salida\t"          +
                        "Duracion\t"            +
                        "Precio-Ejecutivo\t"    +
                        "Precio-Economico\t"    +
                        "Plazas-Ejecutivo\t"    +
                        "Plazas-Economico\n"
                    )
            
            for x in range(len(self.nombreAerolinea)):
                
                if dato == self.nombreAerolinea[x]:

                    print   (
                                #self.nombreAerolinea[x]     + "\t" +
                                self.numVuelo[x]            + "\t\t" +
                                self.origen[x]              + "\t" +
                                self.destino[x]             + "\t\t" +
                                self.fechaSalida[x]         + "\t" +
                                self.horaSalida[x]          + "\t\t" +
                                self.duracion[x]            + "\t\t" +
                                self.precioEjecutivo[x]     + "\t\t\t" +
                                self.precioEconomico[x]     + "\t\t\t" +
                                self.numVueloEjecutivo[x]   + "\t\t\t" +
                                self.numVueloEconomico[x]
                            )
        else:
            print 'Error, el dato no existe'


    def consultaOrigen(self):
        dato = raw_input("Nombre origen: ")


        if dato in self.origen:

            print '\nInformacion de vuelos desde ' + dato + '\n'

            print   (
                        #"Vuelo\t\t"               +
                        "Num. Vuelo\t"          +
                        "Origen\t\t"              +
                        "Destino\t\t"             +
                        "F - Salida\t"          +
                        "H - Salida\t"          +
                        "Duracion\t"            +
                        "Precio-Ejecutivo\t"    +
                        "Precio-Economico\t"    +
                        "Plazas-Ejecutivo\t"    +
                        "Plazas-Economico\n"
                    )
            
            for x in range(len(self.origen)):
                
                if dato == self.origen[x]:

                    print   (
                                #self.nombreAerolinea[x]     + "\t" +
                                self.numVuelo[x]            + "\t\t" +
                                self.origen[x]              + "\t" +
                                self.destino[x]             + "\t\t" +
                                self.fechaSalida[x]         + "\t" +
                                self.horaSalida[x]          + "\t\t" +
                                self.duracion[x]            + "\t\t" +
                                self.precioEjecutivo[x]     + "\t\t\t" +
                                self.precioEconomico[x]     + "\t\t\t" +
                                self.numVueloEjecutivo[x]   + "\t\t\t" +
                                self.numVueloEconomico[x]
                            )
        else:
            print 'Error, el dato no existe'


    def consultaFS(self):
        dato = raw_input("Fecha de salida: ")


        if dato in self.fechaSalida:

            print '\nInformacion de salida de los vuelos\n'

            print   (
                        #"Vuelo\t\t"               +
                        "Num. Vuelo\t"          +
                        "Origen\t\t"              +
                        "Destino\t\t"             +
                        "F - Salida\t"          +
                        "H - Salida\t"          +
                        "Duracion\t"            +
                        "Precio-Ejecutivo\t"    +
                        "Precio-Economico\t"    +
                        "Plazas-Ejecutivo\t"    +
                        "Plazas-Economico\n"
                    )
            
            for x in range(len(self.fechaSalida)):
                
                if dato == self.fechaSalida[x]:

                    print   (
                                #self.nombreAerolinea[x]     + "\t" +
                                self.numVuelo[x]            + "\t\t" +
                                self.origen[x]              + "\t" +
                                self.destino[x]             + "\t\t" +
                                self.fechaSalida[x]         + "\t" +
                                self.horaSalida[x]          + "\t\t" +
                                self.duracion[x]            + "\t\t" +
                                self.precioEjecutivo[x]     + "\t\t\t" +
                                self.precioEconomico[x]     + "\t\t\t" +
                                self.numVueloEjecutivo[x]   + "\t\t\t" +
                                self.numVueloEconomico[x]
                            )
        else:
            print 'Error, el dato no existe'


    def consultaLlegada(self):
        dato = raw_input("Fecha de llegada: ")

        print '\nInformacion de llegada de los vuelos\n'

        print   (
                    #"Vuelo\t\t"               +
                    "Num. Vuelo\t"          +
                    "Origen\t\t"              +
                    "Destino\t\t"             +
                    "F - Salida\t"          +
                    "H - Salida\t"          +
                    "Duracion\t"            +
                    "Precio-Ejecutivo\t"    +
                    "Precio-Economico\t"    +
                    "Plazas-Ejecutivo\t"    +
                    "Plazas-Economico\n"
                )
            
        for x in range(len(self.llegada)):
                
           if dato == self.llegada[x]:

                print   (
                            #self.nombreAerolinea[x]     + "\t" +
                            self.numVuelo[x]            + "\t\t" +
                            self.origen[x]              + "\t" +
                            self.destino[x]             + "\t\t" +
                            self.fechaSalida[x]         + "\t" +
                            self.horaSalida[x]          + "\t\t" +
                            self.duracion[x]            + "\t\t" +
                            self.precioEjecutivo[x]     + "\t\t\t" +
                            self.precioEconomico[x]     + "\t\t\t" +
                            self.numVueloEjecutivo[x]   + "\t\t\t" +
                            self.numVueloEconomico[x]
                        )


    def consultaPrecios(self):
        Min = int(raw_input("Precio Minimo: "))
        Max = int(raw_input("Precio Maximo: "))

        print '\nInformacion de los vuelos con un rango entre ' + str(Min) + ' y ' + str(Max) + '\n'

        print   (
                    #"Vuelo\t\t"               +
                    "Num. Vuelo\t"          +
                    "Origen\t\t"              +
                    "Destino\t\t"             +
                    "F - Salida\t"          +
                    "H - Salida\t"          +
                    "Duracion\t"            +
                    "Precio-Ejecutivo\t"    +
                    "Precio-Economico\t"    +
                    "Plazas-Ejecutivo\t"    +
                    "Plazas-Economico\n"
                )

        for x in range(len(self.llegada)):

            if int(self.precioEjecutivo[x]) > Min and int(self.precioEjecutivo[x]) < Max and int(self.precioEconomico[x]) > Min and int(self.precioEconomico[x]) < Max: 
                print   (
                            #self.nombreAerolinea[x]     + "\t" +
                            self.numVuelo[x]            + "\t\t" +
                            self.origen[x]              + "\t" +
                            self.destino[x]             + "\t\t" +
                            self.fechaSalida[x]         + "\t" +
                            self.horaSalida[x]          + "\t\t" +
                            self.duracion[x]            + "\t\t" +
                            self.precioEjecutivo[x]     + "\t\t\t" +
                            self.precioEconomico[x]     + "\t\t\t" +
                            self.numVueloEjecutivo[x]   + "\t\t\t" +
                            self.numVueloEconomico[x]
                        )