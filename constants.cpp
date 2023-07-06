//#include "constants.h"

int WINDOW_WIDTH;
int WINDOW_HEIGHT;
int PILLER_DELAY;
int RANGE_Y ;
int RANGE_X ;
int GAP_WIDTH;
int GAP_HEIGHT;
int SPEED ; // pix / second
int DISTANCE; // distence(px) between 2 neighboring pillars
int COIN_INTV_L; // lower bound on coin appear time
int COIN_INTV_H; // upper bound on coin appear time
int BAT_V_INTV;
double BAT_ROTATE_SPEED;
int BAT_ROTATE_RADIUS;
int BAT_SIZE;
void initialize(){
    WINDOW_WIDTH=1300;
    WINDOW_HEIGHT=800;
    PILLER_DELAY= 1000;
    RANGE_Y =100;
    RANGE_X =40;
    GAP_WIDTH= 130;
    GAP_HEIGHT =300;
    SPEED =300; // pix / second
    DISTANCE =500;
    COIN_INTV_L = 1000;
    COIN_INTV_H = 7000;
    BAT_ROTATE_SPEED=500;
    BAT_ROTATE_RADIUS=50;
    BAT_SIZE=100;
}
//WINDOW_WIDTH=1300;
//WINDOW_HEIGHT=800;
//PILLER_DELAY= 1000;
//RANGE_Y =100;
//RANGE_X =40;
//GAP_WIDTH= 130;
//GAP_HEIGHT =300;
//SPEED =300; // pix / second
//DISTANCE =500; // distence(px) between 2 neighboring pillars

