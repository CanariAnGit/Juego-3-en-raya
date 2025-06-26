#include <stdio.h>
#include <string.h>

int Matrixcrtr();
void Printr();
//int Matrixeditr();
void Cover();
void TheEnd();

int main() {

    int Matrix[256][256], i, j, byebye=0, difference, size, f, c, turn, tie, endgame, tokenid, repetition, idfrst, idscnd;

    //Matrix: Matriz que recoge el tablero del juego.                                                                                          byebye: condicion de parada del bucle que repite el juego entero, si =1 sale y termina el juego.                                                     difference: recoge el resultado de la funcion strcmp y se usa para saber si los nombres de los jugadores son iguales.
    //size: define el tamaño del tablero de juego.                                                                                             f y c (fila y columna): coordenada introducida por el usuario para situar su ficha.                                                                  turn: contador para saber a quien le toca. tie: condicion de parada si el juego llega a un empate si=1 termina el juego.
    //endgame: si=1 alguno de los jugadores ha conseguido formar un 3 en raya y termina la partida.                                            tokenid: sirve para llevar a la funcion que imprime el tablero la informacion sobre que valor hay que imprimir (X si=1 y O si=0).
    //repetition: condicion parada bucle que pide al usuario meter la coordenada de su ficha hasta que la ponga correctamente.                 idfirst y second: asignan el valor de la ficha que corresponde a cada jugador segun su nombre (si=1 es X, si=0 es O).

    char NameA[256], NameB[256], ans, beginer, first[256], second[256];

    //Name A y NameB: Nombres de los jugadores. ans: respuesta a la pregunta de si repetir el juego o no.                                      beginer: recoge la respuesta de quien empieza primero (x, X, o 0).
    //first y second: almacenan los nombres de los jugadores una vez decidido quien es el first y el second.

    printf("Hola hola holaaaaaaaa!!! Hoy estoy super emocionado por lo que te traigo!  ^_^  \n");
    printf("Que te parece si nos echamos una  partida al clasico juego del 3 en raya?\n");

    printf(" \n");

    printf("Las reglas son sencillas, en su correspondiente turno, cada jugador debe elegir una casilla\n");
    printf("del tablero,  que no  este seleccionada ya por el otro  jugador,  ganando aquel que consiga\n");
    printf("colocar 3  de sus fichas seguidas,  una al lado de la otra,  ya sea en vertical, horizontal\n");
    printf("o diagonal.\n");

    printf(" \n");
    printf("Pero la mejor forma de aprender es practicando, asi que vamos a ello. A JUGAR!\n");
    printf(" \n");

    while(byebye==0){                                                                                                   //Este bucle recoge al programa entero y para cuando termina la partida y el jugador decide no volver a jugar.

        Cover();                                                                                                        //Llama a la funcion que imprime la portada.

        printf("Primero lo primero. Necesito saber el nombre de cada uno de los jugadores.\n");
        printf("Jugador1 dime tu nombre (usaras las X como ficha):\n");
        scanf("%s",NameA);                                                                                       //Guardamos el nombre del jugador A.

        printf(" \n");
        printf("Bonito nombre.\n");

        printf(" \n");
        printf("Te toca a ti jugador2, (usaras las 0 como ficha) como te llamas?\n");
        scanf("%s",NameB);                                                                                       //Guardamos el nombre del jugador B.

        printf(" \n");
        printf("Tambien me gusta tu nombre. :)\n");

        difference=strcmp(NameA, NameB);                                                                                //Comparamos los nombres para saber si son iguales. En ese caso le añadimos un 1 o un 2 al final del nombre de cada uno.

        if(difference==0){                                                                                              //Si los nombres son iguales entonces...

            strcat(NameA, "1");                                                                             //Añadimos un 1 al final del nombre de jugador A.
            strcat(NameB, "2");                                                                             //Añadimos un 2 al final del nombre del jugador B.

            printf("Vaya, veo que los nombres de los jugadores son iguales asi que hare el siguiente cambio.\n");
            printf(" \n");

            printf("Jugador1 se llamara: %s\n",NameA);                                                           //Imprimir los nuevos nombres de los jugadores.
            printf("Jugador2 se llamara: %s\n",NameB);

        }

        printf(" \n");
        printf("Muy bien, ahora toca decidir quien empieza primero.\n");

        beginer='a';                                                                                                    //Inicializar la variable para que al repetir el juego se entre en este bucle.

        while(beginer!='x' && beginer!='0' && beginer!='X'){                                                            //Si la respuesta no es ninguna de las opciones posibles seguimos pidiendola.

            printf("Debes escribir 'X' para %s  o '0'(cero) para %s?\n",NameA, NameB);
            scanf("%s",&beginer);

        }

        switch((int)beginer){                                                                                           //Clasificamos las respuestas de quien empieza primero. Si=X asignamos el nombre del jugador A al primero y su ficha, la X (idfirst=1).

            case 'X':
                strcpy(first,NameA);
                strcpy(second,NameB);
                idfrst=1;
                idscnd=0;
                break;

            case 'x':
                strcpy(first,NameA);
                strcpy(second,NameB);
                idfrst=1;
                idscnd=0;
                break;

            case '0':                                                                                                   //Si empieza el jugador 2, le asignamos el nombre del jugador a la variable second y otorgamos las fichas a cada uno: idfrst=0, idscnd=1 (X).
                strcpy(first,NameB);
                strcpy(second,NameA);
                idfrst=0;
                idscnd=1;
                break;

        }

        printf(" \n");
        printf("De acuerdo, me lo apunto. Ahora, que tan grande quieres que sea el tablero?\n");

        size=0;                                                                                                         //Inicializamos la variable del tamaño para cada repeticion poder elegirla.

        while(size<3){

            printf("(Recuerda que debe ser mayor o igual que 3 y no recomiendo que sea muy grande\n");
            printf("pues puede que no quepa en la pantalla   XD )\n");
            scanf("%d",&size);

        }

        printf(" \n");
        printf("Muy bien, veo que tienes ganas de jugar asi que vamos ya.\n");
        printf(" \n");

        Matrixcrtr(size, Matrix);                                                                                       //Inicializamos la matriz en cada repeticion.
        Printr(size, Matrix);                                                                                           //Imprimimos el tablero tal como esta.

        turn=1;                                                                                                         //Controla en que turno estamos, si es impar le tocara al jugador 1, si es par le toca al jugador 2.
        repetition=0;                                                                                                   //Dice si la coordenada ya esta ocupada por una ficha.

        while(tie==0 && endgame==0){                                                                                    //Bucle que pide turnos hasta que termine el juego.

            if(turn%2==1){                                                                                              //Si el turno es impar le toca al primer jugador.

                printf("Es el turno de %s.",first);                                                              //Pedimos la coordenada a primer jugador.
                tokenid=idfrst;                                                                                         //Pasa el valor de la ficha a la funcion que escribe el tablero. 1 = X, 0 = O.

                while(repetition==0){//Meter este bucle en una funcion que sirve para ambos jugadores.                                                                                   //Bucle que repite la peticion de coordenadas mientras esten repetidas.

                    while(f>=0 && f<=(size-1) && c>=0 && c<=(size-1)){                                                  //Bucle que repite la peticion de coordenadas mientras estas no pertenezcan al tablero.

                        printf("Escribe la coordenada donde quieres colocar tu ficha.\n");
                        printf("(Recuerda que no debe estar ya ocupada, y que debe escribirse como el ejemplo:\n");
                        printf("1,3 o 0,0 sin espacios, primero la fila y luego la columna).\n");
                        scanf("%d%c%d",f,c);                                                                     //Leemos la coordenada en fila, columna.

                    }

                    //Matrixeditr(tokenid, repetition, f, c, tie, endgame);                                               //Funcion que primero comprueba si la coordenada ya esta ocupada y si no la rellena.

                }

            }

            if(turn%2==0){//Copia del primer turno pero cambiando el nombre.

                printf("Es el turno de %s.",second);
                tokenid=idscnd;

                while(repetition==0){

                    while(f>=0 && f<=(size-1) && c>=0 && c<=(size-1)){

                        printf("Escribe la coordenada donde quieres colocar tu ficha.\n");
                        printf("(Recuerda que no debe estar ya ocupada, y que debe escribirse como el ejemplo:\n");
                        printf("1,3 o 0,0 sin espacios, primero la fila y luego la columna).\n");
                        scanf("%d%c%d",f,c);

                    }

                    //Matrixeditr(tokenid, repetition, f, c, tie, endgame);

                }

            }

            turn++;

        }

        //printf("%s. Tu turno.\n",plyr);









        printf("Y hasta aqui esta partida, que te parece si jugamos otra vez?(s/n)\n");
        scanf("%s",&ans);

        switch((int)ans){

            case 's':
                byebye=0;
                break;

            case 'n':
                byebye=1;
                break;

            case 'S':
                byebye=0;
                break;

            case 'N':
                byebye=1;
                break;

            default:

                printf("Vaya, no te he entendido. Vamos a ponerlo mas simple.\n");
                printf("Escribe un 1 si quieres salir, o un 0 si quieres repetir:");
                scanf("%d",&byebye);
                break;

        }
    }

    TheEnd();


}

int Matrixcrtr(int size, int Matrix[size][size]){                                                                      //Inicializa la matriz de juego.

    int i, j;

    for(i=0;i<=size-1;i++){

        for(j=0;j<=size-1;j++){

            Matrix[i][j]=-2;

        }

    }

    return Matrix;

}

void Printr(int size, int Matrix[size][size]){

    int i, j, k;

    printf(" \n");

    printf("          ");

    for(j=0;j<=(size-1);j++){

        printf("   C%d     ",j);

    }

    printf(" \n");


    for(i=0;i<=(size-1);i++){

        printf("          ");

        for(k=0;k<=(size-1);k++){

            printf("----------");

        }

        printf(" \n");

        printf("    F%d   |",i);

        for(j=0;j<=(size-1);j++){

            switch(Matrix[i][j]){

                case 0:
                    printf("    O    |");
                    break;

                case 1:
                    printf("    X    |");
                    break;

                case -2:
                    printf("         |");
                    break;

            }

        }

        printf(" \n");

    }

    printf("          ");

    for(k=0;k<=(size-1);k++){

        printf("----------");

    }

    printf(" \n");
    printf(" \n");

}

void Cover(){

    printf("                        *$$M:\n");
    printf("                         *$$I:\n");
    printf("  *********** :********:  *$$M******:   ******:\n");
    printf("  M$$$$$$$$$$ *$$$$$$$$$*  $$$$$$$$$V  M$$$$$$$*\n");
    printf("  M$$$$$$$$$$ *$$$IFM$$$M  $$$$$NMMM* *$$N**N$$I\n");
    printf("     *$$$V    *$$$:  F$$N  $$$$$N:    V$$M  *IFV\n");
    printf("     :$$$*    *$$$:  I$$M  $$$N$$N**  *$$$NF*:\n");
    printf("     :$$$*    *$$$MMN$$$V  $$$$$$$$$: :N$$$$$$V\n");
    printf("     :$$$*    *$$$$$$$NV   $$$$$$$$$*  :VN$$$$$M\n");
    printf("     :$$$*    *$$$VM$$M:   $$$I***N$N:   :*VN$$$*\n");
    printf("     :$$$*    *$$$::N$$N:  $$$V   :M$NFIM*  :$$$*\n");
    printf("     :$$$*    *$$$: V$$$V  $$$I    V$$$$$M  *$$$:\n");
    printf("     :$$$*    *$$$: :$$$N  $$$$$$$$$MM$$$$NIN$$M\n");
    printf("     :$$$*    *$$$:  V$$$V $$$$$$$$$F:M$$$$$$$M:\n");
    printf("     :***:    :***:  :**** ********** :M$$NVV*\n");
    printf("                                        I$$*\n");
    printf("                                         I$$*\n");
    printf("                                      VVVF$$$VV* :VVV*   *VV*\n");
    printf("                                      M$$$$$$$$V :$$$N   V$$I\n");
    printf("                                      M$$NIIM$$I.:$$$$V  V$$I\n");
    printf("                                      M$$I   V$$V:$$$$$* V$$I\n");
    printf("                                      M$$M****M$$M$$$$$M V$$I\n");
    printf("                                      M$$$$$$$$I$$$$$$$$VV$$I\n");
    printf("                                      M$$$$$$$$:V$$$$*$$$M$$I\n");
    printf("                                      M$$M*****  V$$$:I$$$$$I\n");
    printf("                                      M$$I       :$$$I:N$$$$I\n");
    printf("                                      M$$M****** :$$$$IV$$$$I\n");
    printf("                                      M$$$$$$$$M :$$$$$MN$$$I\n");
    printf("                                      M$$$$$$$$M :$$$*$$$$$$I\n");
    printf("                                      ********** :*** *$$$V**\n");
    printf("                                                       *N$M:\n");
    printf("                                                        *N$M:\n");
    printf("                                                 :VVVVVVVM$$M:   VVVV*   :VVV*   :VVV*    VVVV:\n");
    printf("                                                 :$$$$$$$$$$$N: :$$$$I   .V$$$:  I$$N:   *$$$$V\n");
    printf("                                                 :$$$FVVN$$$N$N:V$$$$$:   :N$$I.*$$$*    V$$$$N\n");
    printf("                                                 :$$$*  *$$$*M$NN$$M$$*    *$$$*M$$I     N$$M$$*\n");
    printf("                                                 :$$$* :I$$N :N$$$M*$$I.    I$$$$$$:    *$$IV$$F\n");
    printf("                                                 :$$$NN$$$$V  :N$$V:$$$:    :$$$$$V     V$$V:$$N\n");
    printf("                                                 :$$$$$$$M*   .N$$$*M$$V     *$$$M      $$$: N$$*\n");
    printf("                                                 :$$$VV$$N*   *$$$$$M$$M      $$$V     *$$$**M$$I\n");
    printf("                                                 :$$$* M$$$*  V$$$$$$$$$:     $$$V     I$$$$$$$$$:\n");
    printf("                                                 :$$$* *$$$I .N$$$$$$$$$V     $$$V    :$$$$$$$$$$*\n");
    printf("                                                 :$$$*  M$$$:*$$$***I$$$M     $$$V    *$$$****M$$I\n");
    printf("                                                 :$$$*  *$$$FF$$M    F$$$*    $$$V    M$$I    V$$$:\n");
    printf("                                                 .***:   *******:     F$$V    ***:    ***:    :***:\n");
    printf("                                                                       V$$V\n");
    printf("                                                                        V$$V\n");
    printf(" \n");

}

void TheEnd(){

    printf("Guauuuu, espero que te haya gustado tanto como a mi, asi como espero verte pronto. Adiooooos\n");
    printf(" \n");

    printf("                        .-+#####*+-      -+*#####+-.\n");
    printf("                      .+############=  =############+.\n");
    printf("                     :################################:\n");
    printf("                    .##################################.\n");
    printf("                    -##################################-\n");
    printf("                    -##################################-\n");
    printf("                    .##################################.\n");
    printf("                     :################################:\n");
    printf("                      .*############################*.\n");
    printf("                        :*########################*:\n");
    printf("                          -*####################*-\n");
    printf("                            :*################*:\n");
    printf("                              :+############+:\n");
    printf("                                .=########=.\n");
    printf("                                  :*##*:\n");
    printf("                                    ..\n");


}


