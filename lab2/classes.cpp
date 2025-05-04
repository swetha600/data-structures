#include<stdio.h>

void Index(){
    printf("1.Square\n");
    printf("2.Rectangle\n");
    printf("3.Cube\n");
    printf("4.Cuboid\n");
    printf("5.Exit\n\n");
}

class AreaAndVolume{
private:
    int side;
    int length;
    int breadth;
    int height;

public:



    void squareArea(){

        printf("enter the side of the sqaure:");
        scanf("%d",&side);
        
        printf("Area of the square is :%d sq.cm \n",side*side);
    }

    void rectangleArea(){
        printf("enter the length of the rectangle:");
        scanf("%d",&length);
        printf("enter the breadth of the rectangle:");
        scanf("%d",&breadth);
        printf("Area of the rectangle is :%d sq.cm\n",length*breadth);

    }

    void cubeArea(){

        printf("enter the side of the cube:");
        scanf("%d",&side);

        printf("surface area of the cube is :%d sq.cm\n",6*side*side);
    }

    void cuboidArea(){

        printf("enter the length of the cuboid:");
        scanf("%d",&length);
        printf("enter the breadth of the cuboid:");
        scanf("%d",&breadth);
        printf("enter the height of the cuboid:");
        scanf("%d",&height);
        printf("surface area of the cuboid is :%d sq.cm\n",2*((length*breadth)+(breadth*height)+(length*height)));
    }


};
int main(){

    int choice;
    int side;
    int length;
    int breadth;
    int height;


    AreaAndVolume obj;

    Index();

    printf("Enter choice: ");
    scanf("%d",&choice);

    while(choice!=5){

        switch(choice){
        case 1:
    
            obj.squareArea();
            break;

        case 2:
        
            obj.rectangleArea();
            break;

        case 3:
            
            obj.cubeArea();
            break;

        case 4:

            obj.cuboidArea();
            break;
        }

        Index();
        printf("Enter Choice:");
        scanf("%d",&choice);

    }




    return 0;
}