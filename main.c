#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXZOO 10
#define MAXANIMAL 300

/*
Asignatura: Metodología de la programación
Alumno 1: <Leiro Arroyo Guillermo>
Alumno 2: <Void>
Grupo: <37>
Curso: 1º - Fecha: < 29Abril 2018>
*/

/**************************************************************************/
/* Estructuras de datos*/
/**************************************************************************/
typedef struct{

    char codigo[7];
    char grupo[10];
    char especie[20];
    char nacimiento[11];
    char sexo;
    char premio;
    char nomre[30];

}struct_animal;

typedef struct{

    char codigo[6];
    char tipo[10];
    char ciudad[20];
    float extension;
    int n_especies;
    float importe;
    char guia[30];
    int cont_animales;
    struct_animal reg_animales[MAXANIMAL];

}struct_zoo;


/**************************************************************************/
/* Funciones generales */
/**************************************************************************/
void opcion_incorrecta();
void banner();
int redo();
int date_check(const char date[10]);
void quitar_n(char cadena[]);
void menus(struct_zoo reg_zoos[],int *contador_zoologicos);
void get_code_animal(char codigo[]);
void get_code_zoologico(char codigo[]);


/**************************************************************************/
/* Funciones opciones de menus */
/**************************************************************************/
void mant_alta_zoo(struct_zoo reg_zoos[],int *contador_zoologicos);
void mant_baja_zoo(struct_zoo reg_zoos[],int *contador_zoologicos);
void mant_mood_zoo(struct_zoo reg_zoos[],int *contador_zoologicos);
void mant_orden_zoo(struct_zoo reg_zoos[],int *contador_zoologicos);
void mant_importar_zoo_txt(struct_zoo reg_zoos[],int *contador_zoologicos);
void mant_alta_animal(struct_zoo reg_zoos[],int *contador_zoologicos);
void mant_baja_animal(struct_zoo reg_zoos[],int *contador_zoologicos);
void mant_mood_animal(struct_zoo reg_zoos[],int *contador_zoologicos);
void mant_orden_animal(struct_zoo reg_zoos[],int *contador_zoologicos);
void mant_importar_animal_txt(struct_zoo reg_zoos[],int *contador_zoologicos);
void mant_importar_animal_dat(struct_zoo reg_zoos[],int *contador_zoologicos);
void mant_premiar_animal(struct_zoo reg_zoos[],int *contador_zoologicos);

void inf_listzoo_full(struct_zoo reg_zoos[],int *contador_zoologicos);
void inf_listzoo_partial(struct_zoo reg_zoos[],int *contador_zoologicos);
void inf_listanimales_full(struct_zoo reg_zoos[],int *contador_zoologicos);
void inf_listanimales_partial(struct_zoo reg_zoos[],int *contador_zoologicos);
void inf_listzoo_actualizado(struct_zoo reg_zoos[],int *contador_zoologicos);
void inf_listanimales_actualizado(struct_zoo reg_zoos[],int *contador_zoologicos);


int main(){

    struct_zoo reg_zoos[MAXZOO];
    int i,contador_zoologicos;
    FILE *file_zoo_actual;



    for(i=0;i<MAXZOO;i++){
        strcpy(reg_zoos[i].codigo,"-----");
    }

    file_zoo_actual=fopen("ZooActual.dat","rb");
    fread(reg_zoos,sizeof(reg_zoos),1,file_zoo_actual);
    fclose(file_zoo_actual);

    for(contador_zoologicos=0,i=0;i<MAXZOO;i++){
        if(strcmp(reg_zoos[i].codigo,"-----")!=0){
            contador_zoologicos++;
        }
    }

    banner();
    menus(reg_zoos,&contador_zoologicos);

    file_zoo_actual=fopen("ZooActual.dat","wb");
    fwrite(reg_zoos,sizeof(reg_zoos),1,file_zoo_actual);
    fclose(file_zoo_actual);

    system("cls");
    system("color 2");
    printf("\n\n\tGracias por utilizar nuestra aplicacion.\n\n\t");
    system("pause");


    return 0;
}


/**************************************************************************/
/* Subprograma: Menus principales */
/* Tipo: Procedimiento (función tipo void) */
/* Prerrequisitos: Recibe array de la estructura zoologicos y la variable contador_zoologicos*/
/* Objetivo: Contiene los menus mantenimiento e informes y se encarga de llamar a las subfuncines para los diversos procesos del zoo */
/**************************************************************************/
void menus(struct_zoo reg_zoos[],int *contador_zoologicos){

    int elecion=0;

    do{
        system("cls");
        switch(elecion){

        case 0:
            break;
        case 1:
            do{
                printf("\n\tMENU MANTENIMIENTO\n\n\t1 .-Alta de Zoologico.\n\t2 .-Baja de Zoologico.\n\t3 .-Modificacion Zoologico.\n\t4 .-Ordenar Zoologicos por tipo (ascendente).\n\t5 .-Importar zoloogicos(txt).\n\n\t6 .-Alta de Animal.\n\t7 .-Baja de Animal.\n\t8 .-Modificacion de Animal.\n\t9 .-Ordenar Animales de un zoo por grupo (descendente).\n\t10.-Importal Animales (txt).\n\t11.-Importar Animales (dat).\n\t12.-Premiar Animales.\n\n\t0.-Salir.\n\n\t-> ");
                scanf("%i",&elecion);
                switch(elecion){
                    case 0:
                        break;
                    case 1:
                        mant_alta_zoo(reg_zoos,contador_zoologicos);
                        break;
                    case 2:
                        mant_baja_zoo(reg_zoos,contador_zoologicos);
                        break;
                    case 3:
                        mant_mood_zoo(reg_zoos,contador_zoologicos);
                        break;
                    case 4:
                        mant_orden_zoo(reg_zoos,contador_zoologicos);
                        break;
                    case 5:
                        mant_importar_zoo_txt(reg_zoos,contador_zoologicos);
                        break;
                    case 6:
                        mant_alta_animal(reg_zoos,contador_zoologicos);
                        break;
                    case 7:
                        mant_baja_animal(reg_zoos,contador_zoologicos);
                        break;
                    case 8:
                        mant_mood_animal(reg_zoos,contador_zoologicos);
                        break;
                    case 9:
                        mant_orden_animal(reg_zoos,contador_zoologicos);
                        break;
                    case 10:
                        mant_importar_animal_txt(reg_zoos,contador_zoologicos);
                        break;
                    case 11:
                        mant_importar_animal_dat(reg_zoos,contador_zoologicos);
                        break;
                    case 12:
                        mant_premiar_animal(reg_zoos,contador_zoologicos);
                        break;
                    default:
                        opcion_incorrecta();
                        break;


                }
                system("cls");
            }while(elecion!=0);
            break;
        case 2:
            do{
                printf("\n\tMENU INFORMES\n\n\t1.-Listar Fichero de Zoologicos (completo).\n\t2.-Listar Ficherro de Zoologicos (solo de un tipo).\n\n\t3.-Listar Fichero de Animales (completo).\n\t4.-Listado Actualizado de Animales (grupo y especie).\n\n\t5.-Listado actualizado de Zoologicos.\n\t6.-Listado actualizado de Animales.\n\n\t0.-Salir.\n\n\t->");
                scanf("%i",&elecion);
                switch(elecion){
                    case 0:
                        break;
                    case 1:
                        inf_listzoo_full(reg_zoos,contador_zoologicos);
                        break;
                    case 2:
                        inf_listzoo_partial(reg_zoos,contador_zoologicos);
                        break;
                    case 3:
                        inf_listanimales_full(reg_zoos,contador_zoologicos);
                        break;
                    case 4:
                        inf_listanimales_partial(reg_zoos,contador_zoologicos);
                        break;
                    case 5:
                        inf_listzoo_actualizado(reg_zoos,contador_zoologicos);
                        break;
                    case 6:
                        inf_listanimales_actualizado(reg_zoos,contador_zoologicos);
                        break;
                    default:
                        opcion_incorrecta();
                        break;


                }
                system("cls");
            }while(elecion!=0);
            break;
        default:
            opcion_incorrecta();
        }
        printf("\n\tMENU PRINCIPAL\n\n\t1.-Mantenimiento.\n\t2.-Informes.\n\n\t0.-Salir.\n\n\t-> ");
        scanf("%i",&elecion);

    }while(elecion!=0);


}


/**************************************************************************/
/* Subprograma: Obtencion y chequeo codigo zoologico */
/* Tipo: Procedimiento (función tipo void) */
/* Prerrequisitos: Recibe un array en el que almacena el codigo del zoologico*/
/* Objetivo: ingreso del codigo del zoologico y comprobacion de que este sea correcto */
/**************************************************************************/
void get_code_zoologico(char codigo[]){

    do{
        printf("\n\n Introduzca el codigo del zologico de la siguiente forma (AAA00): ");
        codigo[0]=toupper(getch());
        putchar(codigo[0]);
        codigo[1]=toupper(getch());
        putchar(codigo[1]);
        codigo[2]=toupper(getch());
        putchar(codigo[2]);
        codigo[3]=getch();
        putchar(codigo[3]);
        codigo[4]=getch();
        putchar(codigo[4]);
        codigo[5]='\0';

    }while(((64>codigo[0])||(90<codigo[0]))||((64>codigo[1])||(90<codigo[1]))||((64>codigo[2])||(90<codigo[2]))||((48>codigo[3])||(57<codigo[3]))||((48>codigo[4])||(57<codigo[4])));

}


/**************************************************************************/
/* Subprograma: Obtencion y chequeo codigo animal */
/* Tipo: Procedimiento (función tipo void) */
/* Prerrequisitos: Recibe un array en el que almacena el codigo del animal*/
/* Objetivo: Ingreso del codigo del animal y comprobacion de que este sea correcto */
/**************************************************************************/
void get_code_animal(char codigo[]){

    do{
        printf("\n\n Introduzca el codigo del animal de la forma (AA-000): ");
        codigo[0]=toupper(getch());
        putchar(codigo[0]);
        codigo[1]=toupper(getch());
        putchar(codigo[1]);
        printf("-");
        codigo[2]='-';
        codigo[3]=getch();
        putchar(codigo[3]);
        codigo[4]=getch();
        putchar(codigo[4]);
        codigo[5]=getch();
        putchar(codigo[5]);
        codigo[6]='\0';
    }while(((64>codigo[0])||(90<codigo[0]))||((64>codigo[1])||(90<codigo[1]))||((48>codigo[3])||(57<codigo[3]))||((48>codigo[4])||(57<codigo[4]))||((48>codigo[5])||(57<codigo[5])));

}


/**************************************************************************/
/* Subprograma: Opcion erronea */
/* Tipo: Procedimiento (función tipo void) */
/* Prerrequisitos: No recibe nada*/
/* Objetivo: Hacer saber al usuario que la opcion introducida es incorrecta */
/**************************************************************************/
void opcion_incorrecta(){

    system("cls");
    system("color 4");
    printf("\n\t Valor invalido, intentelo de nuevo.\n\n\n\t");
    system("pause");
    system("color 7");
    system("cls");
}


/**************************************************************************/
/* Subprograma: Banner */
/* Tipo: Procedimiento (función tipo void) */
/* Prerrequisitos: Void*/
/* Objetivo: Mostrar un mensaje de bienbenida al iniciar la aplicacion */
/**************************************************************************/
void banner(){

    system("color 2");
    //system("color F0");

    printf("\n\n\n\tBienvenido a la aplicacion ControlZoo\n\n\n\n\n");

    printf("\t              ___.-~\"~-._   __....__                \n");
    printf("\t            .'    `    \\ ~\"~        ``-.            \n");
    printf("\t           /` _      )  `\\              `\\          \n");
    printf("\t          /`  a)    /     |               `\\        \n");
    printf("\t        :`        /      |                 \\        \n");
    printf("\t    <`-._|`  .-.  (      /   .            `;\\\\      \n");
    printf("\t     `-. `--'_.'-.;\\___/'   .      .       | \\\\     \n");
    printf("\t  _     /:--`     |        /     /        .'  \\\\    \n");
    printf("\t (\"\\   /`/        |       '     '         /    :`;  \n");
    printf("\t `\\'\\_/`/         .\\     /`~`=-.:        /     ``   \n");
    printf("\t   `._.'          /`\\    |      `\\      /(          \n");
    printf("\t                 /  /\\   |        `Y   /  \\         \n");
    printf("\t                J  /  Y  |         |  /`\\  \\        \n");
    printf("\t               /  |   |  |         |  |  |  |       \n");
    printf("\t              \"---\"  /___|        /___|  /__|       \n");
    printf("\t                     '\"\"\"         '\"\"\"  '\"\"\"        \n\t");

    system("pause");
    system("color 7");

}


/**************************************************************************/
/* Subprograma: Rehacer */
/* Tipo: Procedimiento (función tipo int) */
/* Prerrequisitos: Devuelve la opcion seleccionada por el usuaario*/
/* Objetivo: Mostrar al usuario la opcion de (S/n) almacenar su entrada y veracidad */
/**************************************************************************/
int redo(){

    char resp;

    do{
        printf(" (S/n): ");
        fflush(stdin);
        resp=toupper(getchar());

    }while(resp!='N' && resp!='S' && resp!='\n');
    if(resp=='S'||resp=='\n'){
            return 1;
        }else{
            return 0;
        }
}


/**************************************************************************/
/* Subprograma: Comprovador de fecha */
/* Tipo: Procedimiento (función tipo int) */
/* Prerrequisitos: Cadena de caracteres con la fecha en el formato DD/MM/AAAA*/
/* Objetivo: Comprueba que la fecha introducida sea coerente */
/**************************************************************************/
int date_check(const char date[10]){//devolver 1 si fecha erronea

    int day,mounth,year;


    day=((date[0]-48)*10)+(date[1]-48);
    mounth=((date[3]-48)*10)+(date[4]-48);
    year=((date[6]-48)*1000)+((date[7]-48)*100)+((date[8]-48)*10)+(date[9]-48);

    if(mounth>12){return 1;}
    else{
        if(day<28){return 0;}
        else{
            switch(day){
                case 28:
                    if(mounth==2){
                        return 0;
                    }else{
                        return 1;
                    }
                    break;
                case 29://((año divisible por 4) Y ((año no divisible por 100) O (año divisible por 400)))
                    if((mounth==2) && ((year%4==0)&&(year%100!=0)||(year%400==0))){
                        return 0;
                    }else{
                        return 1;
                    }
                    break;
                case 30:
                    if(mounth==4||mounth==6||mounth==9||mounth==11){
                        return 0;
                    }else{
                        return 1;
                    }
                    break;
                case 31:
                    if(mounth==1||mounth==3||mounth==5||mounth==7||mounth==8||mounth==10||mounth==12){
                        return 0;
                    }else{
                        return 1;
                    }
                    break;
                default:
                    return 1;
            }
        }
    }

}


/**************************************************************************/
/* Subprograma: Quitar el \n */
/* Tipo: Procedimiento (función tipo void) */
/* Prerrequisitos: Una cadena de caracteres*/
/* Objetivo: Eliminar el \n de la cadena de caracteres y sustituirlo por \0 */
/**************************************************************************/
void quitar_n(char cadena[]){

    int i;

    for(i=0;cadena[i]!='\n' && i<=strlen(cadena);i++){


    }
    if(cadena[i]=='\n'){
        cadena[i]='\0';
    }

}






/**************************************************************************/
/* Subprograma: Alta zoologico */
/* Tipo: Procedimiento (función tipo void) */
/* Prerrequisitos: Recibe array de la estructura zoologicos y la variable contador_zoologicos*/
/* Objetivo: Da la opcion al usuario de añadir un nuevo zoologico a la aplicacion */
/**************************************************************************/
void mant_alta_zoo(struct_zoo reg_zoos[],int *contador_zoologicos){

    int i,check;
    char aux,codigo[6];

    do{
        do{
            system("cls");
            printf("\n\tALTA ZOOLOGICO\n\n");
            get_code_zoologico(codigo);

            for(i=0,check=1;(i<*contador_zoologicos) && (check!=0);i++){
                check=strcmp(codigo,reg_zoos[i].codigo);
            }
            i--;

            if(check==0){
                printf("\n\n\tEl codigo introducido ya esta en uso.\n\t");
                system("pause");
            }
        }while(check==0);

        do{
            printf("\n\n\t(acuatico/terrestre)\n");
            printf("  Tipo de zologico(A/T): ");
            fflush(stdin);
            aux=toupper(getchar());
        }while(aux!='A'&&aux!='T');

        if(aux=='A'){
            strcpy(reg_zoos[*contador_zoologicos].tipo,"Acuatico\0");
        }else{
            strcpy(reg_zoos[*contador_zoologicos].tipo,"Terrestre\0");
        }

        printf("\n  Ciuda de la instalacion: ");
        fflush(stdin);
        fgets(reg_zoos[*contador_zoologicos].ciudad,20,stdin);
        quitar_n(reg_zoos[*contador_zoologicos].ciudad);

        printf("\n  Extenxion de las instalaciones en Km: ");
        scanf("%f",&reg_zoos[*contador_zoologicos].extension);
        fflush(stdin);//estos fflush() despues de coger un numero los pongo por si se introduce una letra que no se salte los guientes campos aunque el numero almacenado sera el correspondiente al caracter ascii.

        /*printf("\n  Numero de especies: ");
        scanf("%i",&reg_zoos[*contador_zoologicos].n_especies);
        fflush(stdin);*/
        reg_zoos[*contador_zoologicos].n_especies=0;

        printf("\n  Importe: ");
        scanf("%f",&reg_zoos[*contador_zoologicos].importe);
        fflush(stdin);

        printf("\n  Guia del centro: ");
        fflush(stdin);
        fgets(reg_zoos[*contador_zoologicos].guia,30,stdin);
        quitar_n(reg_zoos[*contador_zoologicos].guia);


        printf("\n\tDesea guadar el nuevo zoologico");
        if(redo()==1){
            strcpy(reg_zoos[*contador_zoologicos].codigo,codigo);
            reg_zoos[*contador_zoologicos].cont_animales=0;
            (*contador_zoologicos)++;
        }

        printf("\n\tDesea volver a realizar la operacion");

    }while(redo()==1);


}


/**************************************************************************/
/* Subprograma: Baja zoologico */
/* Tipo: Procedimiento (función tipo void) */
/* Prerrequisitos: Recibe array de la estructura zoologicos y la variable contador_zoologicos*/
/* Objetivo: Da la opcion al usuario de eliminar un zoologico de la aplicacion */
/**************************************************************************/
void mant_baja_zoo(struct_zoo reg_zoos[],int *contador_zoologicos){

    int i,j,check;
    char codigo[6];

    do{
            system("cls");
            printf("\n\tBAJA ZOOLOGICO\n\n");
            get_code_zoologico(codigo);

            for(i=0,check=1;(i<*contador_zoologicos) && (check!=0);i++){
                check=strcmp(codigo,reg_zoos[i].codigo);
            }
            i--;
            if(check!=0){
                printf("\n\n\tEl zoologico a eliminar no se encuentra en nuestra base de datos.\n\t");
                system("pause");
            }else{
                printf("\n\n\tEsta seguro de que desea eliminarel zoologico %s",codigo);
                if(redo()==1){
                    //lo que haya que hacer para eliminar el zoologico.
                    for(j=i;j<*contador_zoologicos;j++){
                        reg_zoos[j]=reg_zoos[j+1];
                    }
                    strcpy(reg_zoos[*contador_zoologicos].codigo,"-----");
                    (*contador_zoologicos)--;
                }

            }

            printf("\n\tDeseas eliminar otro zoologico");
        }while(redo()==1);

}


/**************************************************************************/
/* Subprograma: Modificacion zoologico */
/* Tipo: Procedimiento (función tipo void) */
/* Prerrequisitos: Recibe array de la estructura zoologicos y la variable contador_zoologicos*/
/* Objetivo: Da la opcion al usuario de modificar un zoologico */
/**************************************************************************/
void mant_mood_zoo(struct_zoo reg_zoos[],int *contador_zoologicos){

    int i,check,option,codigo[6];
    char aux;

    do{
        system("cls");
        printf("\n\tMODIFICACION ZOOLOGICO\n\n");
        get_code_zoologico(codigo);

        for(i=0,check=1;(i<*contador_zoologicos) && (check!=0);i++){
            check=strcmp(codigo,reg_zoos[i].codigo);
        }
        i--;

        if(check!=0){
            printf("\n\n\tEl zoologico a modificar no se encuentra en nuestra base de datos.\n\t");
            system("pause");
        }else{
            do{
                system("cls");
                printf("\n\tMODIFICANDO ZOOLOGICO %s\n\n",codigo);
                printf("\t1.-Tipo: %s\n\t2.-Localizacion: %s\n\t3.-Extension(Km): %f\n\t4.-Especies: %i\n\t5.-Importe: %.2f$\n\t6.-Guia: %s\n\n\t0.-Salir.\n\n\tSelecione la opcion a modificar->",reg_zoos[i].tipo,reg_zoos[i].ciudad,reg_zoos[i].extension,reg_zoos[i].n_especies,reg_zoos[i].importe,reg_zoos[i].guia);
                scanf("%i",&option);
                //modificacion del zoologico.

                switch(option){

                case 0:
                    break;
                case 1:
                    do{
                        printf("\n\n\t(acuatico/terrestre)\n");
                        printf("  Tipo de zologico(A/T): ");
                        fflush(stdin);
                        aux=toupper(getchar());
                    }while(aux!='A'&&aux!='T');

                    if(aux=='A'){
                        strcpy(reg_zoos[i].tipo,"Acuatico \0");
                    }else{
                        strcpy(reg_zoos[i].tipo,"Terrestre\0");
                    }
                    break;
                case 2:
                    printf("\n  Ciuda de la instalacion: ");
                    fflush(stdin);
                    fgets(reg_zoos[i].ciudad,20,stdin);
                    quitar_n(reg_zoos[i].ciudad);
                    break;
                case 3:
                    printf("\n  Extenxion de las instalaciones en Km: ");
                    scanf("%f",&reg_zoos[i].extension);
                    fflush(stdin);//estos fflush() despues de coger un numero los pongo por si se introduce una letra que no se salte los guientes campos aunque el numero almacenado sera el correspondiente al caracter ascii.
                    break;
                case 4:
                    printf("\n  Numero de especies: ");
                    scanf("%i",&reg_zoos[i].n_especies);
                    fflush(stdin);
                    break;
                case 5:
                    printf("\n  Importe: ");
                    scanf("%f",&reg_zoos[i].importe);
                    fflush(stdin);
                    break;
                case 6:
                    printf("\n  Guia del centro: ");
                    fflush(stdin);
                    fgets(reg_zoos[i].guia,30,stdin);
                    quitar_n(reg_zoos[i].guia);
                    break;
                default:
                    opcion_incorrecta();
                    break;
                }
            }while(option!=0);
            }
            printf("\n\tDeseas modificar otro zoologico");
        }while(redo()==1);

}


/**************************************************************************/
/* Subprograma: Ordenar zoologicos */
/* Tipo: Procedimiento (función tipo void) */
/* Prerrequisitos: Recibe array de la estructura zoologicos y la variable contador_zoologicos*/
/* Objetivo: Da la opcion al usuario de ordenar los zoologicos */
/**************************************************************************/
void mant_orden_zoo(struct_zoo reg_zoos[],int *contador_zoologicos){


    int i,j;
    struct_zoo aux;


    for(i=0;i<*contador_zoologicos-1;i++){
        for(j=i;j<*contador_zoologicos;j++){
            if(strcmp(reg_zoos[i].tipo,reg_zoos[j].tipo)>0){
                aux=reg_zoos[i];
                reg_zoos[i]=reg_zoos[j];
                reg_zoos[j]=aux;
            }
        }
    }
    system("cls");
    printf("\n\tORDENAR ZOOLOGICOS\n\n");
    printf(" Codigo\tTipo\t\tImporte $\tExtension(Km)\tEspecies\t\tCiudad\t\t\t\tGuia\n");
    printf(" -----------------------------------------------------------------------------------------------------------------------\n");
    for(i=0;i<*contador_zoologicos;i++){
        printf(" %s\t%s\t%02f\t%07f\t%03i\t%20s\t%30s\n",reg_zoos[i].codigo,reg_zoos[i].tipo,reg_zoos[i].importe,reg_zoos[i].extension,reg_zoos[i].n_especies,reg_zoos[i].ciudad,reg_zoos[i].guia);

    }

    printf("\n\n\n\t");
    system("pause");

}


/**************************************************************************/
/* Subprograma: Importar zoologicos */
/* Tipo: Procedimiento (función tipo void) */
/* Prerrequisitos: Recibe array de la estructura zoologicos y la variable contador_zoologicos*/
/* Objetivo: Da la opcion al usuario de importar zoologicos desde un fichero txt */
/**************************************************************************/
void mant_importar_zoo_txt(struct_zoo reg_zoos[],int *contador_zoologicos){

    int i,j,check,line_position,zoos_preimport;
    char line[300],codigo[6],aux[12],fich_importacion[]="zoologicos.txt";
    FILE *fzoo_txt;

    zoos_preimport=*contador_zoologicos;
    fzoo_txt=fopen(fich_importacion,"r");

    for(i=0;feof(fzoo_txt)==0;i++){
        fgets(line,300,fzoo_txt);

        for(line_position=0;line[line_position]!='#';line_position++){
            codigo[line_position]=line[line_position];
        }
        codigo[line_position]='\0';

        for(j=0,check=1;(j<*contador_zoologicos) && (check!=0);j++){
                check=strcmp(codigo,reg_zoos[j].codigo);
        }

        if(check!=0){
                //copia string line a structura
            for(j=0,line_position++;line[line_position]!='#';line_position++,j++){
                reg_zoos[*contador_zoologicos].tipo[j]=line[line_position];
            }
            reg_zoos[*contador_zoologicos].tipo[j]='\0';


            for(j=0,line_position++;line[line_position]!='#';line_position++,j++){
                reg_zoos[*contador_zoologicos].ciudad[j]=line[line_position];
            }
            reg_zoos[*contador_zoologicos].ciudad[j]='\0';


            for(j=0,line_position++;line[line_position]!='#';line_position++,j++){
                aux[j]=line[line_position];
            }
            aux[j]='\0';
            reg_zoos[*contador_zoologicos].importe=strtof(aux,NULL);


            for(j=0,line_position++;line[line_position]!='#';line_position++,j++){
                aux[j]=line[line_position];
            }
            aux[j]='\0';
            //descomentar la linea inferior si se quiere almacenar el numero de especies guardado en el fichero de importacion txt
            //reg_zoos[*contador_zoologicos].n_especies=atoi(aux);
            reg_zoos[*contador_zoologicos].n_especies=0;


            for(j=0,line_position++;line[line_position]!='#';line_position++,j++){
                aux[j]=line[line_position];
            }
            aux[j]='\0';
            reg_zoos[*contador_zoologicos].extension=strtof(aux,NULL);


            for(j=0,line_position++;line[line_position]!='#';line_position++,j++){
                reg_zoos[*contador_zoologicos].guia[j]=line[line_position];
            }
            reg_zoos[*contador_zoologicos].guia[j]='\0';

            reg_zoos[*contador_zoologicos].cont_animales=0;
            strcpy(reg_zoos[*contador_zoologicos].codigo,codigo);
            (*contador_zoologicos)++;

        }
    }


    system("cls");
    printf("\n\tZOOLOGICOS IMPORTADOS DE %s\n\n",fich_importacion);
    printf(" Codigo\tTipo\t\tImporte $\tExtension(Km)\tEspecies\t\tCiudad\t\t\t\tGuia\n");
    printf(" -----------------------------------------------------------------------------------------------------------------------\n");
    for(i=zoos_preimport;i<*contador_zoologicos;i++){
        printf(" %s\t%s\t%02f\t%07f\t%03i\t%20s\t%30s\n",reg_zoos[i].codigo,reg_zoos[i].tipo,reg_zoos[i].importe,reg_zoos[i].extension,reg_zoos[i].n_especies,reg_zoos[i].ciudad,reg_zoos[i].guia);

    }

    printf("\n\n\n\t");
    system("pause");

    fclose(fzoo_txt);
}


/**************************************************************************/
/* Subprograma: Alta animal */
/* Tipo: Procedimiento (función tipo void) */
/* Prerrequisitos: Recibe array de la estructura zoologicos y la variable contador_zoologicos*/
/* Objetivo: Da la opcion al usuario de añadir un animal a un zoologico */
/**************************************************************************/
void mant_alta_animal(struct_zoo reg_zoos[],int *contador_zoologicos){


    int i,localizador_zoo,check;
    char grupos[6][10]={{"Mamiferos"},{"Aves"},{"Peces"},{"Anfibios"},{"Reptiles"}},codigo_zoo[6];

    do{
        do{
            system("cls");
            printf("\n\tALTA ANIMAL\n\n");
            printf("\n Zoologico a ingresar el animal.\n");
            get_code_zoologico(codigo_zoo);


            for(localizador_zoo=0,check=1;(localizador_zoo<*contador_zoologicos)&&(check!=0);localizador_zoo++){
                check=strcmp(codigo_zoo,reg_zoos[localizador_zoo].codigo);
            }
            localizador_zoo--;


            if(check!=0){
                printf("\n\n\tEl zoologico introducido no se encuentra en nuestra base de datos.\n\t");
                system("pause");
            }
        }while(check!=0);


        do{
            //system("cls");
            //printf("\n\tALTA ANIMAL\n\n");
            get_code_animal(reg_zoos[localizador_zoo].reg_animales[reg_zoos[localizador_zoo].cont_animales].codigo);
            for(i=0,check=1;(i<reg_zoos[localizador_zoo].cont_animales) && (check!=0);i++){
                check=strcmp(reg_zoos[localizador_zoo].reg_animales[reg_zoos[localizador_zoo].cont_animales].codigo,reg_zoos[localizador_zoo].reg_animales[i].codigo);
            }

            if(check==0){
                printf("\n\n\tEl codigo introducido ya esta en uso.\n\t");
                system("pause");
            }

        }while(check==0);

        //grupo
            printf("\n\n");
            printf("\t0-%s\n",grupos[0]);
            printf("\t1-%s\n",grupos[1]);
            printf("\t2-%s\n",grupos[2]);
            printf("\t3-%s\n",grupos[3]);
            printf("\t4-%s\n",grupos[4]);
        do{
            printf("\n  Seleccione una de las opciones:");
            scanf("%i",&i);
        }while(i<0||i>4);

        strcpy(reg_zoos[localizador_zoo].reg_animales[reg_zoos[localizador_zoo].cont_animales].grupo,grupos[i]);


        //fecha de nacimineto
        do{
            printf("\n  Introduzca la fecha de nacimineto:");
            reg_zoos[localizador_zoo].reg_animales[reg_zoos[localizador_zoo].cont_animales].nacimiento[0]=getch();
            putchar(reg_zoos[localizador_zoo].reg_animales[reg_zoos[localizador_zoo].cont_animales].nacimiento[0]);
            reg_zoos[localizador_zoo].reg_animales[reg_zoos[localizador_zoo].cont_animales].nacimiento[1]=getch();
            putchar(reg_zoos[localizador_zoo].reg_animales[reg_zoos[localizador_zoo].cont_animales].nacimiento[1]);
            reg_zoos[localizador_zoo].reg_animales[reg_zoos[localizador_zoo].cont_animales].nacimiento[2]='/';
            putchar(reg_zoos[localizador_zoo].reg_animales[reg_zoos[localizador_zoo].cont_animales].nacimiento[2]);
            reg_zoos[localizador_zoo].reg_animales[reg_zoos[localizador_zoo].cont_animales].nacimiento[3]=getch();
            putchar(reg_zoos[localizador_zoo].reg_animales[reg_zoos[localizador_zoo].cont_animales].nacimiento[3]);
            reg_zoos[localizador_zoo].reg_animales[reg_zoos[localizador_zoo].cont_animales].nacimiento[4]=getch();
            putchar(reg_zoos[localizador_zoo].reg_animales[reg_zoos[localizador_zoo].cont_animales].nacimiento[4]);
            reg_zoos[localizador_zoo].reg_animales[reg_zoos[localizador_zoo].cont_animales].nacimiento[5]='/';
            putchar(reg_zoos[localizador_zoo].reg_animales[reg_zoos[localizador_zoo].cont_animales].nacimiento[5]);
            reg_zoos[localizador_zoo].reg_animales[reg_zoos[localizador_zoo].cont_animales].nacimiento[6]=getch();
            putchar(reg_zoos[localizador_zoo].reg_animales[reg_zoos[localizador_zoo].cont_animales].nacimiento[6]);
            reg_zoos[localizador_zoo].reg_animales[reg_zoos[localizador_zoo].cont_animales].nacimiento[7]=getch();
            putchar(reg_zoos[localizador_zoo].reg_animales[reg_zoos[localizador_zoo].cont_animales].nacimiento[7]);
            reg_zoos[localizador_zoo].reg_animales[reg_zoos[localizador_zoo].cont_animales].nacimiento[8]=getch();
            putchar(reg_zoos[localizador_zoo].reg_animales[reg_zoos[localizador_zoo].cont_animales].nacimiento[8]);
            reg_zoos[localizador_zoo].reg_animales[reg_zoos[localizador_zoo].cont_animales].nacimiento[9]=getch();
            putchar(reg_zoos[localizador_zoo].reg_animales[reg_zoos[localizador_zoo].cont_animales].nacimiento[9]);
            reg_zoos[localizador_zoo].reg_animales[reg_zoos[localizador_zoo].cont_animales].nacimiento[10]='\0';

        }while(date_check(reg_zoos[localizador_zoo].reg_animales[reg_zoos[localizador_zoo].cont_animales].nacimiento)==1);

        //sexo animal
        do{
            printf("\n\n  Introduzca el sexo (H/M) hembra o macho:");
            fflush(stdin);
            reg_zoos[localizador_zoo].reg_animales[reg_zoos[localizador_zoo].cont_animales].sexo=toupper(getchar());
        }while((reg_zoos[localizador_zoo].reg_animales[reg_zoos[localizador_zoo].cont_animales].sexo!='H')&&(reg_zoos[localizador_zoo].reg_animales[reg_zoos[localizador_zoo].cont_animales].sexo!='M'));

        //especie animal
        printf("\n  Introduzca la especie del animal: ");
        fflush(stdin);
        fgets(reg_zoos[localizador_zoo].reg_animales[reg_zoos[localizador_zoo].cont_animales].especie,20,stdin);
        quitar_n(reg_zoos[localizador_zoo].reg_animales[reg_zoos[localizador_zoo].cont_animales].especie);
        for(check=1,i=0;i<reg_zoos[localizador_zoo].cont_animales&&check!=0;i++){
            check=strcmp(reg_zoos[localizador_zoo].reg_animales[reg_zoos[localizador_zoo].cont_animales].especie,reg_zoos[localizador_zoo].reg_animales[i].especie);
        }

        //nombre animal
        printf("\n  Introduzca el nombre:");
        fflush(stdin);
        fgets(reg_zoos[localizador_zoo].reg_animales[reg_zoos[localizador_zoo].cont_animales].nomre,30,stdin);
        quitar_n(reg_zoos[localizador_zoo].reg_animales[reg_zoos[localizador_zoo].cont_animales].nomre);


        reg_zoos[localizador_zoo].reg_animales[reg_zoos[localizador_zoo].cont_animales].premio='N';

        printf("\n\tDesea grabar el animal en el zoologico %s",reg_zoos[localizador_zoo].codigo);
        if(redo()==1){
            reg_zoos[localizador_zoo].cont_animales++;
           /* printf("\n\n\tEs el unico animal de su especie en este zoologico");
            if(redo()==1){*/
            if(check!=0){
                reg_zoos[localizador_zoo].n_especies++;
            }
        }

        printf("\n\tDesea volver a realizar la operacion");


    }while(redo()==1);

}


/**************************************************************************/
/* Subprograma: Baja animal */
/* Tipo: Procedimiento (función tipo void) */
/* Prerrequisitos: Recibe array de la estructura zoologicos y la variable contador_zoologicos*/
/* Objetivo: Da la opcion al usuario de eliminar un anamal de un zoologico */
/**************************************************************************/
void mant_baja_animal(struct_zoo reg_zoos[],int *contador_zoologicos){


    int i,j,localizador_zoo,localizador_animal,check;
    char codigo_animal[7],codigo_zoo[6];

    do{
        do{
            system("cls");
            printf("\n\tBAJA ANIMAL\n\n");
            printf("\n Zoologico a realizar la baja del animal.\n");
            get_code_zoologico(codigo_zoo);


            for(localizador_zoo=0,check=1;(localizador_zoo<*contador_zoologicos)&&(check!=0);localizador_zoo++){
                check=strcmp(codigo_zoo,reg_zoos[localizador_zoo].codigo);
            }
            localizador_zoo--;


            if(check!=0){
                printf("\n\n\tEl zoologico introducido no se encuentra en nuestra base de datos.\n\t");
                system("pause");
            }
        }while(check!=0);


        do{
            get_code_animal(codigo_animal);
            for(localizador_animal=0,check=1;(localizador_animal<reg_zoos[localizador_zoo].cont_animales) && (check!=0);localizador_animal++){
                check=strcmp(codigo_animal,reg_zoos[localizador_zoo].reg_animales[localizador_animal].codigo);
            }
            localizador_animal--;

            if(check!=0){
                printf("\n\n\tEl animal %s no se encuentra en este zoo.\n\t",codigo_animal);
                system("pause");
            }

        }while(check!=0);


        printf("\n\n\tDesea eliminar el animal del zoologico %s",reg_zoos[localizador_zoo].codigo);
        if(redo()==1){


            for(check=1,j=0,i=0;j<reg_zoos[localizador_zoo].cont_animales;j++){
                check=strcmp(reg_zoos[localizador_zoo].reg_animales[localizador_animal].especie,reg_zoos[localizador_zoo].reg_animales[j].especie);
                if(check==0){
                    i++;
                }
            }

            for(j==localizador_animal;j<reg_zoos[localizador_zoo].cont_animales;j++){
                reg_zoos[localizador_zoo].reg_animales[j]=reg_zoos[localizador_zoo].reg_animales[j+1];
            }

            reg_zoos[localizador_zoo].cont_animales--;

            if(i==1){
                reg_zoos[localizador_zoo].n_especies--;
            }
        }

        printf("\n\tDesea volver a realizar la operacion");


    }while(redo()==1);


}


/**************************************************************************/
/* Subprograma: Modificacion animal */
/* Tipo: Procedimiento (función tipo void) */
/* Prerrequisitos: Recibe array de la estructura zoologicos y la variable contador_zoologicos*/
/* Objetivo: Da la opcion al usuario de modificar los datos de un animal */
/**************************************************************************/
void mant_mood_animal(struct_zoo reg_zoos[],int *contador_zoologicos){

    int i,k,localizador_zoo,localizador_animal,check,check2,check3,option;
    char grupos[6][10]={{"Mamiferos"},{"Aves"},{"Peces"},{"Anfibios"},{"Reptiles"}},codigo_zoo[6],codigo_animal[]="AA-000\0";

        do{
            system("cls");
            printf("\n\tMODIFICACION ANIMAL\n\n");
            printf("\n Zoologico alque pertenece el animal.");
            get_code_zoologico(codigo_zoo);


            for(localizador_zoo=0,check=1;(localizador_zoo<*contador_zoologicos)&&(check!=0);localizador_zoo++){
                check=strcmp(codigo_zoo,reg_zoos[localizador_zoo].codigo);
            }
            localizador_zoo--;


            if(check!=0){
                printf("\n\n\tEl zoologico introducido no se encuentra en nuestra base de datos.\n\t");
                system("pause");
            }
        }while(check!=0);

        do{

            printf("\n\n\n Animal a modificar.");
            get_code_animal(codigo_animal);

            for(localizador_animal=0,check=1;(localizador_animal<reg_zoos[localizador_zoo].cont_animales)&&(check!=0);localizador_animal++){
                check=strcmp(codigo_animal,reg_zoos[localizador_zoo].reg_animales[localizador_animal].codigo);
            }
            localizador_animal--;


            if(check!=0){
                printf("\n\n\tEl animal introducido no se encuentra en este zoo.\n\t");
                system("pause");
            }

        }while(check!=0);



        do{
            system("cls");
            printf("\n\tMODIFICANDO ANIMAL(%s) DEL ZOOLOGICO(%s)\n\n",codigo_animal,codigo_zoo);
            printf("\n\t1.-Grupo: %s",reg_zoos[localizador_zoo].reg_animales[localizador_animal].grupo);
            printf("\n\t2.-Fecha de nacimiento: %s",reg_zoos[localizador_zoo].reg_animales[localizador_animal].nacimiento);
            printf("\n\t3.-Sexo: %c",reg_zoos[localizador_zoo].reg_animales[localizador_animal].sexo);
            printf("\n\t4.-Especie: %s",reg_zoos[localizador_zoo].reg_animales[localizador_animal].especie);
            printf("\n\t5.-Nombre: %s",reg_zoos[localizador_zoo].reg_animales[localizador_animal].nomre);
            printf("\n\t6.-Premio: %c\n\n\t0.-Salir.\n\n\t->",reg_zoos[localizador_zoo].reg_animales[localizador_animal].premio);

            scanf("%i",&option);

            system("cls");
            printf("\n\tMODIFICANDO ANIMAL(%s) DEL ZOOLOGICO(%s)\n\n",codigo_animal,codigo_zoo);

            switch(option){

            case 0:
                break;
            case 1:
                    printf("\n\n");
                    printf("\t0-%s\n",grupos[0]);
                    printf("\t1-%s\n",grupos[1]);
                    printf("\t2-%s\n",grupos[2]);
                    printf("\t3-%s\n",grupos[3]);
                    printf("\t4-%s\n",grupos[4]);
                do{
                    printf("\n  Seleccione una de las opciones:");
                    scanf("%i",&i);
                }while(i<0||i>4);

                strcpy(reg_zoos[localizador_zoo].reg_animales[localizador_animal].grupo,grupos[i]);
                break;


            case 2:
                do{
                    printf("\n  Introduzca la fecha de nacimineto:");
                    reg_zoos[localizador_zoo].reg_animales[localizador_animal].nacimiento[0]=getch();
                    putchar(reg_zoos[localizador_zoo].reg_animales[localizador_animal].nacimiento[0]);
                    reg_zoos[localizador_zoo].reg_animales[localizador_animal].nacimiento[1]=getch();
                    putchar(reg_zoos[localizador_zoo].reg_animales[localizador_animal].nacimiento[1]);
                    reg_zoos[localizador_zoo].reg_animales[localizador_animal].nacimiento[2]='/';
                    putchar(reg_zoos[localizador_zoo].reg_animales[localizador_animal].nacimiento[2]);
                    reg_zoos[localizador_zoo].reg_animales[localizador_animal].nacimiento[3]=getch();
                    putchar(reg_zoos[localizador_zoo].reg_animales[localizador_animal].nacimiento[3]);
                    reg_zoos[localizador_zoo].reg_animales[localizador_animal].nacimiento[4]=getch();
                    putchar(reg_zoos[localizador_zoo].reg_animales[localizador_animal].nacimiento[4]);
                    reg_zoos[localizador_zoo].reg_animales[localizador_animal].nacimiento[5]='/';
                    putchar(reg_zoos[localizador_zoo].reg_animales[localizador_animal].nacimiento[5]);
                    reg_zoos[localizador_zoo].reg_animales[localizador_animal].nacimiento[6]=getch();
                    putchar(reg_zoos[localizador_zoo].reg_animales[localizador_animal].nacimiento[6]);
                    reg_zoos[localizador_zoo].reg_animales[localizador_animal].nacimiento[7]=getch();
                    putchar(reg_zoos[localizador_zoo].reg_animales[localizador_animal].nacimiento[7]);
                    reg_zoos[localizador_zoo].reg_animales[localizador_animal].nacimiento[8]=getch();
                    putchar(reg_zoos[localizador_zoo].reg_animales[localizador_animal].nacimiento[8]);
                    reg_zoos[localizador_zoo].reg_animales[localizador_animal].nacimiento[9]=getch();
                    putchar(reg_zoos[localizador_zoo].reg_animales[localizador_animal].nacimiento[9]);
                    reg_zoos[localizador_zoo].reg_animales[localizador_animal].nacimiento[10]='\0';

                }while(date_check(reg_zoos[localizador_zoo].reg_animales[localizador_animal].nacimiento)==1);
                break;


            case 3:
                do{
                    printf("\n\n  Introduzca el sexo (H/M) hembra o macho:");
                    fflush(stdin);
                    reg_zoos[localizador_zoo].reg_animales[localizador_animal].sexo=toupper(getchar());
                }while((reg_zoos[localizador_zoo].reg_animales[localizador_animal].sexo!='H')&&(reg_zoos[localizador_zoo].reg_animales[localizador_animal].sexo!='M'));
                break;


            case 4:

                for(check2=0,k=0;k<reg_zoos[localizador_zoo].cont_animales;k++){
                    if((strcmp(reg_zoos[localizador_zoo].reg_animales[localizador_animal].especie,reg_zoos[localizador_zoo].reg_animales[k].especie))==0){
                        check2++;
                    }
                }

                printf("\n  Introduzca la especie del animal: ");
                fflush(stdin);
                fgets(reg_zoos[localizador_zoo].reg_animales[localizador_animal].especie,20,stdin);
                quitar_n(reg_zoos[localizador_zoo].reg_animales[localizador_animal].especie);

                for(check3=0,k=0;k<reg_zoos[localizador_zoo].cont_animales;k++){
                    if((strcmp(reg_zoos[localizador_zoo].reg_animales[localizador_animal].especie,reg_zoos[localizador_zoo].reg_animales[k].especie))==0){
                        check3++;
                    }
                }

                if(check2==1){
                    reg_zoos[localizador_zoo].n_especies--;
                }
                if(check3==1){
                    reg_zoos[localizador_zoo].n_especies++;
                }

                break;

            case 5:
                printf("\n  Introduzca el nombre:");
                fflush(stdin);
                fgets(reg_zoos[localizador_zoo].reg_animales[localizador_animal].nomre,30,stdin);
                quitar_n(reg_zoos[localizador_zoo].reg_animales[localizador_animal].nomre);
                break;

            case 6:
                do{
                    printf("\n\n  Premiar animal (S/N): ");
                    fflush(stdin);
                    reg_zoos[localizador_zoo].reg_animales[localizador_animal].premio=toupper(getchar());
                }while((reg_zoos[localizador_zoo].reg_animales[localizador_animal].premio!='S')&&(reg_zoos[localizador_zoo].reg_animales[localizador_animal].premio!='N'));
                break;

            default:
                opcion_incorrecta();
                break;


            }
        }while(option!=0);
}


/**************************************************************************/
/* Subprograma: Ordenar animales */
/* Tipo: Procedimiento (función tipo void) */
/* Prerrequisitos: Recibe array de la estructura zoologicos y la variable contador_zoologicos*/
/* Objetivo: Da la opcion al usuario de ordenar los animales */
/**************************************************************************/
void mant_orden_animal(struct_zoo reg_zoos[],int *contador_zoologicos){

    int i,j,localizador_zoo,check;
    char grupos[6][10]={{"Anfibios"},{"Aves"},{"Mamiferos"},{"Peces"},{"Reptiles"}},codigo_zoo[6];

    system("cls");
    printf("\n\tLISTADO ANIMALES POR GRUPO\n\n");
    printf("\n Zoologico a listar los animales.\n");
    get_code_zoologico(codigo_zoo);


    for(localizador_zoo=0,check=1;(localizador_zoo<*contador_zoologicos)&&(check!=0);localizador_zoo++){
        check=strcmp(codigo_zoo,reg_zoos[localizador_zoo].codigo);
    }
    localizador_zoo--;

        printf("\r Zoologico: %s                                                                                 \n",reg_zoos[localizador_zoo].codigo);
        printf("-----------------------------------------------------------------------------------------------------------------\n");
        printf(" Codigo\t\tSexo\tPremio\tNacimiento\t   Grupo\t\tEspecie\t\tNombre\n");
        printf("-----------------------------------------------------------------------------------------------------------------\n");
        for(i=0;i<5;i++){
            for(j=0;j<reg_zoos[localizador_zoo].cont_animales;j++){
                if(0==strcmp(reg_zoos[localizador_zoo].reg_animales[j].grupo,grupos[i])){
                    printf(" %s\t\t",reg_zoos[localizador_zoo].reg_animales[j].codigo);
                    printf("  %c\t",reg_zoos[localizador_zoo].reg_animales[j].sexo);
                    printf("  %c\t",reg_zoos[localizador_zoo].reg_animales[j].premio);
                    printf("%s\t",reg_zoos[localizador_zoo].reg_animales[j].nacimiento);
                    printf("%10s\t",reg_zoos[localizador_zoo].reg_animales[j].grupo);
                    printf("%20s\t",reg_zoos[localizador_zoo].reg_animales[j].especie);
                    printf("%s\n",reg_zoos[localizador_zoo].reg_animales[j].nomre);
                }
            }
        }

    printf("\n\n\n\t");
    system("pause");

}


/**************************************************************************/
/* Subprograma: Importar animales desde .txt */
/* Tipo: Procedimiento (función tipo void) */
/* Prerrequisitos: Recibe array de la estructura zoologicos y la variable contador_zoologicos*/
/* Objetivo: Da la opcion al usuario de importar animales desde un txt */
/**************************************************************************/
void mant_importar_animal_txt(struct_zoo reg_zoos[],int *contador_zoologicos){

    int i,j,k,line_position,animal_preimport,localizador_zoo,check,check2;
    char codigo_zoo[6],codigo_animal[7],line[300],fich_importacion[]="animales.txt";
    FILE *fanimal_txt;


    //codigo#premio#sexo#grupo#especie#nacimiento#nombre#
    //AA-000#S#H#Anfibios#pavo real#12/12/1212#budy#
    system("cls");
    printf("\n\tIMPORTAR ANIMALES DE %s\n\n",fich_importacion);
    printf("\n Zoologico alque se importaran los animales.");
    get_code_zoologico(codigo_zoo);

    //zoo a importar los animales
    for(localizador_zoo=0,check=1;(localizador_zoo<*contador_zoologicos)&&(check!=0);localizador_zoo++){
        check=strcmp(codigo_zoo,reg_zoos[localizador_zoo].codigo);
    }
    localizador_zoo--;

    animal_preimport=reg_zoos[localizador_zoo].cont_animales;

    fanimal_txt=fopen(fich_importacion,"r");

    for(i=0;feof(fanimal_txt)==0;i++){
    fgets(line,300,fanimal_txt);
    for(line_position=0;line[line_position]!='#';line_position++){
            codigo_animal[line_position]=line[line_position];
        }
        codigo_animal[line_position]='\0';

        //chequeo animal repetido en zoologico
        for(j=0,check=1;(j<reg_zoos[localizador_zoo].cont_animales) && (check!=0);j++){
                check=strcmp(codigo_animal,reg_zoos[localizador_zoo].reg_animales[j].codigo);
        }

        if(check!=0){

            line_position++;
            reg_zoos[localizador_zoo].reg_animales[reg_zoos[localizador_zoo].cont_animales].premio=line[line_position];
            line_position+=2;
            reg_zoos[localizador_zoo].reg_animales[reg_zoos[localizador_zoo].cont_animales].sexo=line[line_position];


            for(j=0,line_position+=2;line[line_position]!='#';line_position++,j++){
                reg_zoos[localizador_zoo].reg_animales[reg_zoos[localizador_zoo].cont_animales].grupo[j]=line[line_position];
            }
            reg_zoos[localizador_zoo].reg_animales[reg_zoos[localizador_zoo].cont_animales].grupo[j]='\0';


            for(j=0,line_position++;line[line_position]!='#';line_position++,j++){
                reg_zoos[localizador_zoo].reg_animales[reg_zoos[localizador_zoo].cont_animales].especie[j]=line[line_position];
            }
            reg_zoos[localizador_zoo].reg_animales[reg_zoos[localizador_zoo].cont_animales].especie[j]='\0';

            for(check2=1,k=0;k<reg_zoos[localizador_zoo].cont_animales&&check2!=0;k++){
            check2=strcmp(reg_zoos[localizador_zoo].reg_animales[reg_zoos[localizador_zoo].cont_animales].especie,reg_zoos[localizador_zoo].reg_animales[k].especie);
            }

            if(check2!=0){
                reg_zoos[localizador_zoo].n_especies++;
            }


            for(j=0,line_position++;line[line_position]!='#';line_position++,j++){
                reg_zoos[localizador_zoo].reg_animales[reg_zoos[localizador_zoo].cont_animales].nacimiento[j]=line[line_position];
            }
            reg_zoos[localizador_zoo].reg_animales[reg_zoos[localizador_zoo].cont_animales].nacimiento[j]='\0';


            for(j=0,line_position++;line[line_position]!='#';line_position++,j++){
                reg_zoos[localizador_zoo].reg_animales[reg_zoos[localizador_zoo].cont_animales].nomre[j]=line[line_position];
            }
            reg_zoos[localizador_zoo].reg_animales[reg_zoos[localizador_zoo].cont_animales].nomre[j]='\0';


            strcpy(reg_zoos[localizador_zoo].reg_animales[reg_zoos[localizador_zoo].cont_animales].codigo,codigo_animal);
            reg_zoos[localizador_zoo].cont_animales++;


        }//end_if
    }
    fclose(fanimal_txt);


    system("cls");
    printf("\n\tLISTADO ANIMALES IMPORTADOS\n\n");
    printf(" Zoologico: %s\n",reg_zoos[localizador_zoo].codigo);
    printf("-----------------------------------------------------------------------------------------------------------------\n");
    printf(" Codigo\t\tSexo\tPremio\tNacimiento\t   Grupo\t\tEspecie\t\tNombre\n");
    printf("-----------------------------------------------------------------------------------------------------------------\n");
    for(j=animal_preimport;j<reg_zoos[localizador_zoo].cont_animales;j++){
        printf(" %s\t\t",reg_zoos[localizador_zoo].reg_animales[j].codigo);
        printf("  %c\t",reg_zoos[localizador_zoo].reg_animales[j].sexo);
        printf("  %c\t",reg_zoos[localizador_zoo].reg_animales[j].premio);
        printf("%s\t",reg_zoos[localizador_zoo].reg_animales[j].nacimiento);
        printf("%10s\t",reg_zoos[localizador_zoo].reg_animales[j].grupo);
        printf("%20s\t",reg_zoos[localizador_zoo].reg_animales[j].especie);
        printf("%s\n",reg_zoos[localizador_zoo].reg_animales[j].nomre);
    }


    printf("\n\n\n\t");
    system("pause");


}


/**************************************************************************/
/* Subprograma: Importar animales desde .dat */
/* Tipo: Procedimiento (función tipo void) */
/* Prerrequisitos: Recibe array de la estructura zoologicos y la variable contador_zoologicos*/
/* Objetivo: Da la opcion al usuario de importar animales desde un fichero .dat */
/**************************************************************************/
void mant_importar_animal_dat(struct_zoo reg_zoos[],int *contador_zoologicos){

    int i,j,k,animal_preimport,localizador_zoo,check,check2;
    char codigo_zoo[6],codigo_animal[7],fich_importacion[]="animales.dat";
    struct_animal buffer;
    FILE *fanimal_dat;



    system("cls");
    printf("\n\tIMPORTAR ANIMALES DE %s\n\n",fich_importacion);
    printf("\n Zoologico alque se importaran los animales.");
    get_code_zoologico(codigo_zoo);

    //zoo a importar los animales
    for(localizador_zoo=0,check=1;(localizador_zoo<*contador_zoologicos)&&(check!=0);localizador_zoo++){
        check=strcmp(codigo_zoo,reg_zoos[localizador_zoo].codigo);
    }
    localizador_zoo--;

    animal_preimport=reg_zoos[localizador_zoo].cont_animales;

    fanimal_dat=fopen(fich_importacion,"rb");

    for(i=0;feof(fanimal_dat)==0;i++){


        //chequeo animal repetido en zoologico
        for(j=0,check=1;(j<reg_zoos[localizador_zoo].cont_animales) && (check!=0);j++){
                check=strcmp(codigo_animal,reg_zoos[localizador_zoo].reg_animales[j].codigo);
        }

        if(check!=0){
            fread(&buffer,sizeof(buffer),1,fanimal_dat);
            reg_zoos[localizador_zoo].reg_animales[reg_zoos[localizador_zoo].cont_animales]=buffer;

            quitar_n(reg_zoos[localizador_zoo].reg_animales[reg_zoos[localizador_zoo].cont_animales].nomre);
            quitar_n(reg_zoos[localizador_zoo].reg_animales[reg_zoos[localizador_zoo].cont_animales].especie);

            for(check2=1,k=0;k<reg_zoos[localizador_zoo].cont_animales&&check2!=0;k++){
            check2=strcmp(reg_zoos[localizador_zoo].reg_animales[reg_zoos[localizador_zoo].cont_animales].especie,reg_zoos[localizador_zoo].reg_animales[k].especie);
            }

            if(check2!=0){
                reg_zoos[localizador_zoo].n_especies++;
            }

            reg_zoos[localizador_zoo].cont_animales++;
        }//end_if
    }
    fclose(fanimal_dat);
    reg_zoos[localizador_zoo].cont_animales--;


    system("cls");
    printf("\n\tLISTADO ANIMALES IMPORTADOS\n\n");
    printf(" Zoologico: %s\n",reg_zoos[localizador_zoo].codigo);
    printf("-----------------------------------------------------------------------------------------------------------------\n");
    printf(" Codigo\t\tSexo\tPremio\tNacimiento\t   Grupo\t\tEspecie\t\tNombre\n");
    printf("-----------------------------------------------------------------------------------------------------------------\n");
    for(j=animal_preimport;j<reg_zoos[localizador_zoo].cont_animales;j++){
        printf(" %s\t\t",reg_zoos[localizador_zoo].reg_animales[j].codigo);
        printf("  %c\t",reg_zoos[localizador_zoo].reg_animales[j].sexo);
        printf("  %c\t",reg_zoos[localizador_zoo].reg_animales[j].premio);
        printf("%s\t",reg_zoos[localizador_zoo].reg_animales[j].nacimiento);
        printf("%10s\t",reg_zoos[localizador_zoo].reg_animales[j].grupo);
        printf("%20s\t",reg_zoos[localizador_zoo].reg_animales[j].especie);
        printf("%s\n",reg_zoos[localizador_zoo].reg_animales[j].nomre);
    }


    printf("\n\n\n\t");
    system("pause");


}


/**************************************************************************/
/* Subprograma: Premiar animales */
/* Tipo: Procedimiento (función tipo void) */
/* Prerrequisitos: Recibe array de la estructura zoologicos y la variable contador_zoologicos*/
/* Objetivo: Da la opcion al usuario de premiar a grupos de animales */
/**************************************************************************/
void mant_premiar_animal(struct_zoo reg_zoos[],int *contador_zoologicos){

    int j,localizador_zoo,check,grupo_elegido;
    char grupos[6][10]={{"Mamiferos"},{"Aves"},{"Peces"},{"Anfibios"},{"Reptiles"}},codigo_zoo[6],opcion_premio;


    //titulo y coger codigo del zoo a trabajar.
    system("cls");
    printf("\n\tCONCEDER/REBOCAR PREMIOS\n\n");
    printf("\n Zoologico a premiar/despremiar.");
    get_code_zoologico(codigo_zoo);

    for(localizador_zoo=0,check=1;(localizador_zoo<*contador_zoologicos)&&(check!=0);localizador_zoo++){
        check=strcmp(codigo_zoo,reg_zoos[localizador_zoo].codigo);
    }
    localizador_zoo--;


    //Premiar o despremiar
    do{
        printf("\n\n Marcar grupo de animales como premiados \"S\" o como no premiados \"N\" (S/N): ");
        fflush(stdin);
        opcion_premio=toupper(getchar());

    }while(opcion_premio!='N' && opcion_premio!='S');

    //Grupo a conceder/pribar del premio
    printf("\n\n");
    printf("\t0-%s\n",grupos[0]);
    printf("\t1-%s\n",grupos[1]);
    printf("\t2-%s\n",grupos[2]);
    printf("\t3-%s\n",grupos[3]);
    printf("\t4-%s\n",grupos[4]);
    do{
        printf("\n  Seleccione una de las opciones:");
        scanf("%i",&grupo_elegido);
    }while(grupo_elegido<0||grupo_elegido>4);

    //tabla animales recien premiados
    system("cls");
    printf("\n\tCONCEDER/REBOCAR PREMIOS\n\n");

        printf(" Grupo animales recien (premiados/no premiados) del zoologico: %s \n",reg_zoos[localizador_zoo].codigo);
        printf("-----------------------------------------------------------------------------------------------------------------\n");
        printf(" Codigo\t\tSexo\tPremio\tNacimiento\t   Grupo\t\tEspecie\t\tNombre\n");
        printf("-----------------------------------------------------------------------------------------------------------------\n");
            for(j=0;j<reg_zoos[localizador_zoo].cont_animales;j++){
                if(0==strcmp(reg_zoos[localizador_zoo].reg_animales[j].grupo,grupos[grupo_elegido])){

                    reg_zoos[localizador_zoo].reg_animales[j].premio=opcion_premio;

                    printf(" %s\t\t",reg_zoos[localizador_zoo].reg_animales[j].codigo);
                    printf("  %c\t",reg_zoos[localizador_zoo].reg_animales[j].sexo);
                    printf("  %c\t",reg_zoos[localizador_zoo].reg_animales[j].premio);
                    printf("%s\t",reg_zoos[localizador_zoo].reg_animales[j].nacimiento);
                    printf("%10s\t",reg_zoos[localizador_zoo].reg_animales[j].grupo);
                    printf("%20s\t",reg_zoos[localizador_zoo].reg_animales[j].especie);
                    printf("%s\n",reg_zoos[localizador_zoo].reg_animales[j].nomre);
                }
        }

    printf("\n\n\n\t");
    system("pause");


}





/**************************************************************************/
/* Subprograma: Listado completo zoologicos */
/* Tipo: Procedimiento (función tipo void) */
/* Prerrequisitos: Recibe array de la estructura zoologicos y la variable contador_zoologicos*/
/* Objetivo: Muestra al usuario un listado completo de los zoologicos registrados en la aplicacion */
/**************************************************************************/
void inf_listzoo_full(struct_zoo reg_zoos[],int *contador_zoologicos){

    int i,N_terrestres=0;
    float total_agua=0,medio_subenciones=0;

    system("cls");
    printf("\n\tLISTADO ZOOS COMPLETO\n\n");
    printf(" Codigo\tTipo\t\tImporte $\tExtension(Km)\tEspecies\t\tCiudad\t\t\t\tGuia\n");
    printf(" -----------------------------------------------------------------------------------------------------------------------\n");
    for(i=0;i<*contador_zoologicos;i++){
        printf(" %s\t%s\t%02f\t%07f\t%03i\t%20s\t%30s\n",reg_zoos[i].codigo,reg_zoos[i].tipo,reg_zoos[i].importe,reg_zoos[i].extension,reg_zoos[i].n_especies,reg_zoos[i].ciudad,reg_zoos[i].guia);

    }

    for(i=0;i<*contador_zoologicos;i++){
        if(strcmp(reg_zoos[i].tipo,"Terrestre")==0){
            medio_subenciones+=reg_zoos[i].importe;
            N_terrestres++;
        }else{
            total_agua+=reg_zoos[i].importe;
        }
    }


    printf("\n\n\n\t************************************************\n");
    printf("\tIMPORTE TOTAL (Tasas de Agua) = %f $\n",total_agua);
    printf("\tIMPORTE MEDIO (Subenciones) = %f $\n",medio_subenciones/N_terrestres);
    printf("\t************************************************");

    printf("\n\n\n\t");
    system("pause");

}


/**************************************************************************/
/* Subprograma: Listado parcial zoologicos */
/* Tipo: Procedimiento (función tipo void) */
/* Prerrequisitos: Recibe array de la estructura zoologicos y la variable contador_zoologicos*/
/* Objetivo: Muestra al usuario un listado parcial de los zoologicos registrados en la aplicacion */
/**************************************************************************/
void inf_listzoo_partial(struct_zoo reg_zoos[],int *contador_zoologicos){

    int i;
    char type[10],titulo[11],aux;


    system("cls");
     do{
            printf("\n\n\t(ACUATICO/TERRESTRE)\n\n");
            printf("  Tipo de zologico del que desea ver la informacion(A/T): ");
            fflush(stdin);
            aux=toupper(getchar());
        }while(aux!='A'&&aux!='T');

        if(aux=='A'){
            strcpy(type,"Acuatico\0");
            strcpy(titulo,"ACUATICOS\0");
        }else{
            strcpy(type,"Terrestre\0");
            strcpy(titulo,"TERRESTRES\0");
        }


    system("cls");
    printf("\n\tLISTADO ZOOLOGICOS %s\n\n",titulo);
    printf(" Codigo\tTipo\t\tImporte $\tExtension(Km)\tEspecies\t\tCiudad\t\t\t\tGuia\n");
    printf(" -----------------------------------------------------------------------------------------------------------------------\n");
    for(i=0;i<*contador_zoologicos;i++){
        if(strcmp(reg_zoos[i].tipo,type)==0){
            printf(" %s\t%s\t%02f\t%07f\t%03i\t%20s\t%30s\n",reg_zoos[i].codigo,reg_zoos[i].tipo,reg_zoos[i].importe,reg_zoos[i].extension,reg_zoos[i].n_especies,reg_zoos[i].ciudad,reg_zoos[i].guia);
        }
    }



    printf("\n\n\n\t");
    system("pause");

}


/**************************************************************************/
/* Subprograma: Listado completo animales */
/* Tipo: Procedimiento (función tipo void) */
/* Prerrequisitos: Recibe array de la estructura zoologicos y la variable contador_zoologicos*/
/* Objetivo: Muestra al usuario un listado completo de los animales registrados en la aplicacion */
/**************************************************************************/
void inf_listanimales_full(struct_zoo reg_zoos[],int *contador_zoologicos){


    int i,j;

    system("cls");
    printf("\n\tLISTADO COMPLETO ANIMALES\n\n");
    for(i=0;i<*contador_zoologicos;i++){
        printf(" Zoologico: %s\n",reg_zoos[i].codigo);
        printf("-----------------------------------------------------------------------------------------------------------------\n");
        printf(" Codigo\t\tSexo\tPremio\tNacimiento\t   Grupo\t\tEspecie\t\tNombre\n");
        printf("-----------------------------------------------------------------------------------------------------------------\n");
        for(j=0;j<reg_zoos[i].cont_animales;j++){
            printf(" %s\t\t",reg_zoos[i].reg_animales[j].codigo);
            printf("  %c\t",reg_zoos[i].reg_animales[j].sexo);
            printf("  %c\t",reg_zoos[i].reg_animales[j].premio);
            printf("%s\t",reg_zoos[i].reg_animales[j].nacimiento);
            printf("%10s\t",reg_zoos[i].reg_animales[j].grupo);
            printf("%20s\t",reg_zoos[i].reg_animales[j].especie);
            printf("%s\n",reg_zoos[i].reg_animales[j].nomre);
        }
        printf("\n\n");
    }

    printf("\n\n\n\t");
    system("pause");


}


/**************************************************************************/
/* Subprograma: Listado parcial animales */
/* Tipo: Procedimiento (función tipo void) */
/* Prerrequisitos: Recibe array de la estructura zoologicos y la variable contador_zoologicos*/
/* Objetivo: Muestra al usuario un listado parcial de los animales registrados en la aplicacion */
/**************************************************************************/
void inf_listanimales_partial(struct_zoo reg_zoos[],int *contador_zoologicos){

    int i,j;
    char especie_tolist[20],grupo_tolist[10],grupos[6][10]={{"Mamiferos"},{"Aves"},{"Peces"},{"Anfibios"},{"Reptiles"}};

    system("cls");
    printf("\n\tLISTADO PARCIAL\n\n");
    printf("\n\n");
    printf("\t0-%s\n",grupos[0]);
    printf("\t1-%s\n",grupos[1]);
    printf("\t2-%s\n",grupos[2]);
    printf("\t3-%s\n",grupos[3]);
    printf("\t4-%s\n",grupos[4]);
    do{
        printf("\n Grupo de animales a listar:");
        scanf("%i",&i);
    }while(i<0||i>4);
    strcpy(grupo_tolist,grupos[i]);

    printf("\n Especie animales a listar: ");
    fflush(stdin);
    fgets(especie_tolist,20,stdin);
    quitar_n(especie_tolist);

    system("cls");
    printf("\n\tLISTADO ANIMALES (Grupo: %s, Especie: %s)\n\n",grupo_tolist,especie_tolist);
    for(i=0;i<*contador_zoologicos;i++){
        printf(" Zoologico: %s\n",reg_zoos[i].codigo);
        printf("-----------------------------------------------------------------------------------------------------------------\n");
        printf(" Codigo\t\tSexo\tPremio\tNacimiento\t   Grupo\t\tEspecie\t\tNombre\n");
        printf("-----------------------------------------------------------------------------------------------------------------\n");
        for(j=0;j<reg_zoos[i].cont_animales;j++){
            if(0==strcmp(grupo_tolist,reg_zoos[i].reg_animales[j].grupo) && 0==strcmp(especie_tolist,reg_zoos[i].reg_animales[j].especie)){
                printf(" %s\t\t",reg_zoos[i].reg_animales[j].codigo);
                printf("  %c\t",reg_zoos[i].reg_animales[j].sexo);
                printf("  %c\t",reg_zoos[i].reg_animales[j].premio);
                printf("%s\t",reg_zoos[i].reg_animales[j].nacimiento);
                printf("%10s\t",reg_zoos[i].reg_animales[j].grupo);
                printf("%20s\t",reg_zoos[i].reg_animales[j].especie);
                printf("%s\n",reg_zoos[i].reg_animales[j].nomre);
            }
        }
        printf("\n\n");
    }

    printf("\n\n\n\t");
    system("pause");
}


/**************************************************************************/
/* Subprograma: Listado actualizado zoologicos */
/* Tipo: Procedimiento (función tipo void) */
/* Prerrequisitos: Recibe array de la estructura zoologicos y la variable contador_zoologicos*/
/* Objetivo: Muestra al usuario un listado actualizado de los zoologicos registrados en la aplicacion */
/**************************************************************************/
void inf_listzoo_actualizado(struct_zoo reg_zoos[],int *contador_zoologicos){

    int i;

    system("cls");
    printf("\n\tLISTADO ZOOLOGICOS ACTUALIZADO\n\n");
    printf(" Codigo\tTipo\t  Animales\tExtension(Km)\tEspecies\t\tCiudad\t\t\t\tGuia\n");
    printf(" -----------------------------------------------------------------------------------------------------------------------\n");
    for(i=0;i<*contador_zoologicos;i++){
        printf(" %s\t%s\t%i\t%07f\t%03i\t%20s\t%30s\n",reg_zoos[i].codigo,reg_zoos[i].tipo,reg_zoos[i].cont_animales,reg_zoos[i].extension,reg_zoos[i].n_especies,reg_zoos[i].ciudad,reg_zoos[i].guia);
    }


    printf("\n\n\n\t");
    system("pause");



}


/**************************************************************************/
/* Subprograma: Listado actualizado animales */
/* Tipo: Procedimiento (función tipo void) */
/* Prerrequisitos: Recibe array de la estructura zoologicos y la variable contador_zoologicos*/
/* Objetivo: Muestra al usuario un listado actualizado de los animales registrados en la aplicacion */
/**************************************************************************/
void inf_listanimales_actualizado(struct_zoo reg_zoos[],int *contador_zoologicos){

    int check,j,localizador_zoo;
    char codigo_zoo[6];

    do{
        system("cls");
        printf("\n\tLISTADO ACTUALIZADO ANIMALES\n\n");
        printf("\n Zoologico a listar animales.");
        get_code_zoologico(codigo_zoo);


        for(localizador_zoo=0,check=1;(localizador_zoo<*contador_zoologicos)&&(check!=0);localizador_zoo++){
            check=strcmp(codigo_zoo,reg_zoos[localizador_zoo].codigo);
        }
        localizador_zoo--;

        if(check!=0){
            printf("\n\n\tEl zoologico introducido no se encuentra en nuestra base de datos.\n\t");
            system("pause");
        }
    }while(check!=0);


    printf("\r Zoologico: %s                                                                           \n",reg_zoos[localizador_zoo].codigo);
    printf("-----------------------------------------------------------------------------------------------------------------\n");
    printf(" Codigo\t\tSexo\tPremio\tNacimiento\t   Grupo\t\tEspecie\t\tNombre\n");
    printf("-----------------------------------------------------------------------------------------------------------------\n");
    for(j=0;j<reg_zoos[localizador_zoo].cont_animales;j++){
        printf(" %s\t\t",reg_zoos[localizador_zoo].reg_animales[j].codigo);
        printf("  %c\t",reg_zoos[localizador_zoo].reg_animales[j].sexo);
        printf("  %c\t",reg_zoos[localizador_zoo].reg_animales[j].premio);
        printf("%s\t",reg_zoos[localizador_zoo].reg_animales[j].nacimiento);
        printf("%10s\t",reg_zoos[localizador_zoo].reg_animales[j].grupo);
        printf("%20s\t",reg_zoos[localizador_zoo].reg_animales[j].especie);
        printf("%s\n",reg_zoos[localizador_zoo].reg_animales[j].nomre);
    }

    printf("\n\n\n\t");
    system("pause");

}
