#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[]) {

    char id[5][10];
    char nombre[5][20];
    float precio[5];
    int stock[5];

    int opc=0, opc2=0;

    int cont=0;

    float ganancia=0;

    int pv=0;
    int cantidad=0;
    float valor=0;

    do{

        printf("Seleccione una opcion:\n");
        printf("1.Ingrese un producto\n");
        printf("2.Vender producto\n");
        printf("3.Reabastecer producto\n");
        printf("4.Informacion de producto\n");
        printf("5.Ver ganancias\n");
        printf(">> ");
        scanf("%d",&opc);

        switch (opc)
        {
        case 1:
            printf("Ingrese el ID del producto %d: ",cont);
            fflush(stdin);
            scanf("%s",&id[cont]);
            printf("Ingrese el Nombre del producto %d: ",cont);
            fflush(stdin);
            fgets(nombre[cont],20,stdin);

            int len = strlen(nombre[cont]) - 1;
            nombre[cont][len]='\0';

            printf("Ingrese el precio del producto %d: ",cont);
            scanf("%f",&precio[cont]);
            printf("Ingrese el stock del producto %d: ",cont);
            scanf("%d",&stock[cont]);
            cont++;
            break;
        case 2:

            printf("-----------Productos----------\n");
            printf("#\tID\tNombre Producto\tPrecio\tStock\n");
            for (int i = 0; i < cont; i++)
            {
                printf("%d\t%s\t%s\t%.2f\t%d\n",i,id[i],nombre[i],precio[i],stock[i]);
            }
            printf("Seleccione el producto que desea vender: ");
            scanf("%d",&pv);
            do
            {
                printf("Ingrese la cantidad del producto %d a vender: ", pv);
                scanf("%d", &cantidad);
                if (cantidad > stock[pv])
                {
                    printf("No se puede realizar la venta, stock disponible: %d\n", stock[pv]);
                }
                if (cantidad<=0)
                {
                    printf("La cantidad debe ser mayor a cero\n");
                }
                
            } while (cantidad > stock[pv] || cantidad<=0);
            valor = cantidad * precio[pv];
            stock[pv]-=cantidad;
            ganancia+=valor;
            printf("Venta exitosa, valor de la venta: %.2f\n",valor);
            break;

        case 3:
            printf("-----------Productos----------\n");
            printf("#\tID\tNombre Producto\tPrecio\tStock\n");
            for (int i = 0; i < cont; i++)
            {
                printf("%d\t%s\t%s\t%.2f\t%d\n", i, id[i], nombre[i], precio[i], stock[i]);
            }
            printf("Seleccione el producto que desea reabastecer: ");
            scanf("%d", &pv);
            printf("Ingrese la cantidad del producto %d a reabastecer: ", pv);
            scanf("%d", &cantidad);
            stock[pv]+=cantidad;
            printf("El nuevo stock del producto es: %d\n",stock[pv]);
            break;
        case 4:
            printf("-----------Productos----------\n");
            printf("#\tID\tNombre Producto\tPrecio\tStock\n");
            for (int i = 0; i < cont; i++)
            {
                printf("%d\t%s\t%s\t%.2f\t%d\n", i, id[i], nombre[i], precio[i], stock[i]);
            }
            break;
        case 5:
            printf("Las ganancias totales: %.2f\n",ganancia);
            break;
        default:
            break;
        }
        printf("Desea seleccionar otra opcion 1.Si/2.No: ");
        scanf("%d",&opc2);
    }while(opc2!=2);



    return 0;
}